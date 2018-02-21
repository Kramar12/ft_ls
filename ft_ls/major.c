#include <dirent.h>
#include "ft_ls.h"

# include "libft/ft_strlen.c"
# include "libft/ft_strdup.c"
# include "libft/ft_strcmp.c"
# include "libft/ft_strjoin.c"
# include "libft/ft_strsub.c"
# include "libft/ft_memalloc.c"
# include "libft/ft_memset.c"


void    get_time(char *place);


int             ft_ls(char **av)    // s flagom t dlina kajdogo po 12
{
	DIR *dir;
	uid_t uid;
	struct passwd *userinfo;
	struct dirent *entry;
	t_ls *tape;
	t_exls *ext;

	userinfo = getpwuid(uid);

	dir = *av ? opendir(*av) : opendir("./");
	entry = readdir(dir);

	ls_whip(*av, dir, entry);
	//ls_rec(*av);
	closedir(dir);
	return (0);
}

void    get_time(char *place)
{
	struct passwd *pw;
	struct group  *gr;
	struct stat sb;
	char *dest;
	stat(place, &sb);

	dest = ft_strsub(ctime(&sb.st_mtimespec), 4, 12);
	pw  = getpwuid(sb.st_uid);
	gr = getgrgid(sb.st_gid);
	printf("\t%d\t%s\t%s\t%10zu\t%s\t",sb.st_nlink, pw->pw_name, gr->gr_name, sb.st_size, dest);       //dodelat

	char outstr[200];



//	struct group  *gr = getgrgid(sb.st_gid);


}

void	ls_whip(const char *dest, DIR *dir, struct dirent *entry)
{
	t_ls *tape;
	t_exls *ext;
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	w.ws_col = 136;

	if (!(dir = dest ? opendir(dest) : opendir("./")))
		return ;
	entry = readdir(dir);
	tape = tlsnew();
	ext = textlsnew();
	ext->wword = ls_tsd(*dir, entry, tape);
	ext->cword = countargs(*dir, entry);
	ext->wscol = w.ws_col;
	ext->dest = ft_strdup(dest);
	tape = ls_sl(tape);


	ls_lpr(tape, ext, entry);
	//ls_prnt(tape, ext);
	closedir(dir);
}

void	ls_lpr(t_ls *root, t_exls *ext, struct dirent *entry)
{
	time_t lt;
	int     i;
	DIR *dir;
	char *dest;

//	lt = time(NULL);
//	printf (ctime(&lt));

	if (!(dir = opendir(ext->dest)))
		return;
	while (root)
	{
		if (root->nm && *root->nm != '.')
		{
				dest = ft_strjoin(ext->dest, root->nm);
				ls_pr_type(root->tp);
				ls_rights(dest);
				get_time(dest);
				printf("%s", root->nm);
		}
		root = root->next;
	}

}

void ls_rec(const char *name)
{
	DIR *dir;
	char *path;
	struct dirent *entry;

	if (!(printf("\n")) || !(dir = opendir(name)))
		return;
	if((entry = readdir(dir)))
		ls_whip(name, dir, entry);
	closedir(dir);


	if (!(printf("\n")) || !(dir = opendir(name)))
		return;
	while ((entry = readdir(dir)) || closedir(dir))
		if (entry->d_type == DT_DIR && (*entry->d_name != '.'))
		{
			path = ft_strjoin(ft_strjoin(name, "/"), entry->d_name);
			printf("%s/%s:", name,  entry->d_name);
			ls_rec(path);
		}
}

void    ls_prnt(t_ls *root, t_exls *ext)
{
	int     i;
	int 	tcword;

	tcword = ext->cword;
	i = 0;
	while (++ext->wword % 8);	// there is a problem with a wide, but i forgot what the problem is
	while (root)
	{
		if (root->nm && *root->nm != '.')
		{
			if (i + ext->wword > ext->wscol || ((i / ext->wword == ext->cword / 2 + 1 && ext->cword * ext->wword > ext->wscol)))
				i *= printf("\n%-*s", ext->wword, root->nm) ? 0 : 0;
			else
				printf("%-*s", ext->wword, root->nm);
		}
		else
			tcword--;
		i += (root->nm && *root->nm != '.') ? ext->wword : 0;
		root = root->next;
	}
}

t_ls 	*ls_sl(t_ls *root)	//sort list
{
	t_ls *new_root;
	t_ls *node;
	t_ls *cur;

	new_root = NULL;
	while (root != NULL)
	{
		node = root;
		root = root->next;
			if (new_root == NULL ||	(node->nm && new_root->nm && ft_strcmp(node->nm, new_root->nm) < 0))
		{
			node->next = new_root;
			new_root = node;
		}
		else
		{
			cur = new_root;
			while (cur->next != NULL && (node->nm && cur->next->nm && ft_strcmp(node->nm, cur->next->nm) >= 0))
				cur = cur->next;
			node->next = cur->next;
			if (node->nm)
				cur->next = node;
		}
	}
	return (new_root);
}


int     ls_tsd(DIR dir, struct dirent *entry, t_ls *tape)   //take struct dirent
{
	int     width;

	width = 0;
	while (entry)
	{
		tape->nm = ft_strdup(entry->d_name);
		tape->tp = entry->d_type;
		tape->sz = dir.__dd_len;
		width = entry->d_namlen > width ? entry->d_namlen : width;
		tape->next = tlsnew();
		tape = tape->next;
		entry = readdir(&dir);
	}

	return (width);
}





//have to make vertical sorts, but it doesnt :c ,
/*
t_ls    *ls_vert(t_ls *root, t_exls *ext)
{
	t_ls	*new;
	t_ls	*rn;
	int     i;
	int j;
	int jv;
	int tcw;

	tcw = ext->cword;

	i = 0;
	jv = 0;
	new = tlsnew();
	rn = new;
	while (++ext->wword % 8 && ++ext->wword);
	while (jv + ext->wword < ext->wscol)
		jv += ext->wword;
	while (root)
	{
		j = 0;
		if (root->name && *root->name != '.')
		{
			if (i + ext->wword > ext->wscol || (i / ext->wword == ext->cword / 2 + 1))
			{
				//i *= printf("\n%-*s", ext->wword, root->name) ? 0 : 0;
				while (j++ < ((i / ext->wword) * 2))
				{
					if (new->prev)
						new = new->prev;
				}
				new->name = root->name;
			}
			else
			{
				//printf("%-*s", ext->wword, root->name);
				while (j++ < (jv / ext->wword) && (jv / ext->wword)) //
				{
					if (!new->next)
						new->next = tlsnew();
					new->next->prev = new;
					new = new->next;
				}
				new->name = root->name;
			}
		}
		else
			ext->cword--;
		i += (root->name && *root->name != '.') ? ext->wword : 0;
		root = root->next;
	}
	ext->cword = tcw;
	return (rn);
}
*/