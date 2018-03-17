/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <aleksandr.rabyj@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 15:34:40 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/16 15:35:01 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls					*ls_tsd(DIR *dir, struct dirent *e, int f, char *way)
{
	t_ls				*tape;
	t_ls				*root;
	int					swc;

	swc = 0;
	tape = tlsnew();
	root = tape;
	e = readdir(dir);
	while (e)
	{
		if ((*(e->d_name) != '.' || (f / 10) % 2))
		{
			tape->nm = ft_strdup(e->d_name);
			tape->tp = checktype(tape->nm, way, f);
			swc = 1;
		}
		if ((e = readdir(dir)) && swc == 1)
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
			j = (unsigned short int)i;
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
	char				*temp;

	way = NULL;
	if (code == 1)
	{
		temp = ft_strdup(av);
		if (*temp != '.' && *temp != '/')
		{
			way = ft_strjoin("./", temp);
			free(temp);
			temp = ft_strdup(way);
		}
		if (temp[ft_strlen(temp) - 1] != '/')
		{
			way ? free(way) : 0;
			way = ft_strjoin(temp, "/");
		}
		way = !way ? ft_strdup(av) : 0;
		free(temp);
	}
	return (way);
}

void					ls_free(t_ls *head, t_exls *ext)
{
	t_ls				*curr;

	while ((curr = head))
	{
		head = head->next;
		if (curr->nm)
			free(curr->nm);
		free(curr);
	}
	if (ext)
	{
		free(ext->dest);
		free(ext);
	}
}
