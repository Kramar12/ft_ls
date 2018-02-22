#include <dirent.h>
#include "ft_ls.h"

char    *ls_takeway(char **av)
{
	char *way;

	while (++(av))
		if (!*av || **av != '-')
			break ;
	way = ft_strdup(*av);
	if (*way != '.' && *way != '/')
		way = ft_strjoin("./", way);
	if (way[ft_strlen(way) - 1] != '/')
		way = ft_strjoin(way, "/");
	return (way);
}

void    ls_errors(char *way, int code)
{
	if (code == 0)
	{
		ft_printf("ls: %s: No such file or directory", ft_strsub(way, 2, (ft_strlen(way) - 3)));
		exit (0);
	}
	if (code == 1)
	{
		ft_printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]", *way);
		exit (1);
	}
}

int             ft_ls(char **av)    // s flagom t dlina kajdogo po 12
{
	int flags;
	DIR *dir;
	struct dirent *entry;
	char *way;

	way = ls_takeway(av);
	flags = ls_tkfls(100000, av);

	if (!(dir = way ? opendir(way) : opendir("./")))
		ls_errors(way, 0);
	entry = readdir(dir);

	ls_whip(way, dir, entry, flags);
	if (flags / 1000 % 2)
		ls_rec(way, flags);
	closedir(dir);
	return (0);
}

void    get_time(char *place, ssize_t xattr, t_exls *ext)
{
	struct passwd *pw;
	struct group  *gr;
	struct stat sb;
	acl_t acl;
	acl_entry_t dummy;

	stat(place, &sb);
	if ((acl = acl_get_link_np(place, ACL_TYPE_EXTENDED))
	    && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
	{
		acl_free(acl);
		acl = NULL;
	}
	xattr = listxattr(place, NULL, 0, XATTR_NOFOLLOW);
	xattr *= xattr < 0 ? 0 : 1;
	if (xattr > 0)
		ft_printf("@");
	else if (acl != NULL)
		ft_printf("+");
	else
		ft_printf(" ");
	pw  = getpwuid(sb.st_uid);
	gr = getgrgid(sb.st_gid);
	ft_printf(" %*d", ext->lenlinks, sb.st_nlink);
	ft_printf(" %-*s\t", ext->lenowner, pw->pw_name);
	ft_printf("%-*s ", ext->lengroup, gr->gr_name);
	ft_printf("%*zu ",ext->lensize, sb.st_size);
	ft_printf("%s ",ft_strsub(ctime(&sb.st_mtimespec), 4, 12));
	acl_free(acl);
}

void	ls_whip(const char *dest, DIR *dir, struct dirent *entry, int flags)
{
	t_ls *tape;
	t_exls *ext;
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	w.ws_col = 136;

	if (!(dir = dest ? opendir(dest) : opendir("./")))
	{
		ft_printf("ls: %s: Permission denied\n\n", entry->d_name);
		return;
	}
	entry = readdir(dir);
	tape = tlsnew();
	ext = textlsnew();
	ext->wword = ls_tsd(*dir, entry, tape);
	ext->cword = countargs(*dir, entry);
	ext->wscol = w.ws_col;
	ext->dest = ft_strdup(dest);
	ext->flags = flags;
	tape = ls_sl(tape);

	if (ext->flags % 2)
		ls_lpr(tape, ext, entry);
	else
		ls_prnt(tape, ext);
	closedir(dir);
}

void	ls_lpr(t_ls *root, t_exls *ext, struct dirent *entry)
{
	char    *dest;
	int     kat;

	kat = 0;
	ls_getwidth(root, ext, ft_strjoin(ext->dest, root->nm), 0);
	ft_printf("total %d", 0);
	while (root)
	{
		if (root->nm && (*root->nm != '.' || ((ext->flags / 10) % 2)))
		{
			dest = ft_strjoin(ext->dest, "/");
			dest = ft_strjoin(dest, root->nm);
			ls_pr_type(root->tp);
			ls_rights(dest);
			get_time(dest, 0, ext);
			ft_printf("%s", root->nm);
		}
		root = root->next;
	}
}

void    ls_getwidth(t_ls *root, t_exls *ext, char *placeq, ssize_t xattr)
{
	struct passwd *pw;
	struct group  *gr;
	struct stat sb;
	char *place;

	while (root)
	{
		place = *root->nm != '.' ? ft_strjoin(ext->dest, root->nm) : ft_strdup(ext->dest);
		stat(place, &sb);
		pw = getpwuid(sb.st_uid);
		gr = getgrgid(sb.st_gid);
		ext->lenlinks = ft_pwrbase(sb.st_nlink, 10) > ext->lenlinks ? ft_pwrbase(sb.st_nlink, 10) : ext->lenlinks;
		ext->lenowner = ft_strlen(pw->pw_name) > ext->lenowner ? (int) (ft_strlen(pw->pw_name)) : ext->lenowner;
		ext->lengroup = ft_strlen(gr->gr_name) > ext->lengroup ? (int) (ft_strlen(gr->gr_name)) : ext->lengroup;
		ext->lensize = ft_pwrbase(sb.st_size, 10) > ext->lensize ? ft_pwrbase(sb.st_size, 10) : ext->lensize;
		root = root->next;
	}
}

void ls_rec(const char *name, int flags)
{
	DIR *dir;
	char *path;
	struct dirent *entry;

	if (!(dir = opendir(name)))
		return;
	while ((entry = readdir(dir)) || closedir(dir))
		if (entry->d_type == DT_DIR && ((*entry->d_name != '.') || ((flags / 10) % 2))) //-Rla ../../../ex1/q1
		{
			if (name[ft_strlen(name) - 1] != '/')
				path = ft_strjoin(ft_strjoin(name, "/"), entry->d_name);
			else
				path = ft_strjoin(name, entry->d_name);
			*entry->d_name != '/' ? ft_printf("%s%s:\n", name,  entry->d_name) : ft_printf("%s/%s:\n", name,  entry->d_name);
			ls_whip(path, dir, entry, flags);
			ls_rec(path, flags);
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
		if (root->nm && (*root->nm != '.' || ((ext->flags / 10) % 2)))
		{
			if (i + ext->wword > ext->wscol || ((i / ext->wword == ext->cword / 2 + 1 && ext->cword * ext->wword > ext->wscol)))
				i *= ft_printf("\n%-*s", ext->wword, root->nm) ? 0 : 0;
			else
				ft_printf("%-*s", ext->wword, root->nm);
		}
		else
			tcword--;
		i += (root->nm && (*root->nm != '.' || ((ext->flags / 10) % 2))) ? ext->wword : 0;
		root = root->next;
	}
	write(1, "\n\n", 2);
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