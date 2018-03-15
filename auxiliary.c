#include "ft_ls.h"

t_ls					*ls_tsd(DIR *dir, struct dirent *entry, int flags, char *way)   //take struct dirent
{
	t_ls				*tape;
	t_ls				*root;
	int 				swc;

	swc = 0;
	tape = tlsnew();
	root = tape;
	entry = readdir(dir);
	while (entry)
	{
		if ((*(entry->d_name) != '.' || (flags / 10) % 2))
		{
			tape->nm = ft_strdup(entry->d_name);
			tape->type = checktype(tape->nm, way, flags);
			swc = 1;
		}
		if ((entry = readdir(dir)) && swc == 1)
		{
			tape->next = tlsnew();
			tape = tape->next;
		}
		swc = 0;
	}
	return (root);
}

char					*slovo(char *s)
{
	int					i;
	char				*dest;
	unsigned short int	j;

	i = 0;
	j = 32767;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == '/')
			j = (unsigned short int )i;
		i++;
	}
	if (j != 32767)
		dest = ft_strsub(s, j, ft_strlen(s) - j);
	else
		dest = ft_strdup(s);
	return (dest);
}

void					ls_acl(char *place)
{
	acl_t				acl;
	ssize_t				xattr;
	acl_entry_t			dummy;

	if ((acl = acl_get_link_np(place, ACL_TYPE_EXTENDED))
		&& acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1)
		acl = !(acl_free(acl)) ? NULL : NULL;
	if ((xattr = listxattr(place, NULL, 0, XATTR_NOFOLLOW)) < 0)
		xattr = 0;
	if (xattr > 0)
		write(1, "@", 1);
	else if (acl)
		write(1, "+", 1);
	else
		write(1, " ", 1);
	acl_free(acl);
}

 char					*ls_takeway(char *av, int code)
{
	char				*way;

	way = NULL;
	if (code == 1)
	{
		way = ft_strdup(av);
		if (*way != '.' && *way != '/')
			way = ft_strjoin("./", way);
		if (way[ft_strlen(way) - 1] != '/')
			way = ft_strjoin(way, "/");
	}
	return (way);
}

int						ls_errors(char lt, char *way, int code)
{
	char				*temp;

	temp = NULL;
	code == 0 ? ft_printf("ls: %s: %s\n", (temp = ft_strsub(way, 0, (ft_strlen(way)))), strerror(errno)) : 0;
	if (code == 1)
	{
		ft_printf("ls: illegal option -- %c\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", lt);
		free(temp);
		exit (0);
	}
	code == 2 ? ft_printf("\n\nls: %s: %s", way, strerror(errno)) : 0;
	free(temp);
	return (1);
}

void ls_free(t_ls *head, t_exls *ext)
{
	t_ls *curr;

	while ((curr = head))
	{
		head = head->next;
		if (curr->nm)
			free(curr->nm);
		free (curr);
	}
	if (ext)
	{
		free(ext->dest);
		free(ext);
	}
}
