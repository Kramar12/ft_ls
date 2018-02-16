#include <dirent.h>
#include "ft_ls.h"

# include "libft/ft_strlen.c"
# include "libft/ft_strdup.c"
# include "libft/ft_strcmp.c"

int             ft_ls(char **av)
{
	DIR *dir;
	uid_t uid;
	struct passwd *userinfo;
	struct dirent *entry;

	userinfo = getpwuid(uid);
	*av++;
	dir = *av ? opendir(*av) : opendir("./");
	entry = readdir(dir);

	bhavachakra("../hello/taste");
	closedir(dir);
	return (0);
}

int bhavachakra(char *av)
{
	t_ls *tape;
	t_exls *ext;
	DIR *dir;
	struct dirent *entry;
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	w.ws_col = 132;

	tape = tlsnew();
	ext = textlsnew();
	dir = *av ? opendir(av) : opendir("./");
	entry = readdir(dir);
	ext->wword = ls_tsd(*dir, entry, tape);
	ext->cword = countargs(*dir, entry);
	tape = ls_sl(tape);
	ext->wscol = w.ws_col;
	ls_prnt(tape, ext);


	closedir(dir);
	return (0);
}

void    ls_prnt(t_ls *root, t_exls *ext)
{
	int     i;

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
			ext->cword--;
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
		tape->next->prev = tape;
		tape = tape->next;
		entry = readdir(&dir);
	}

	return (width);
}

int countargs(DIR dir, struct dirent *entry)		//count of objects in dir
{
	int     counter;

	counter = (entry && *entry->d_name != '.') ? 1 : 0;
	while (entry)
		counter += ((entry = readdir(&dir)) && *entry->d_name != '.') ? 1 : 0;

	return (counter);
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