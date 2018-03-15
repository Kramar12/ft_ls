/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <ariabyi@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 09:12:00 by ariabyi           #+#    #+#             */
/*   Upnmd: 2018/03/14 09:12:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ct(char *rootnm, char *nrootnm, char *dest)
{
	struct stat		sb;
	struct stat		sp;
	ssize_t			q;
	char			*place;

	place = ft_multjoin(3, dest, "/", nrootnm);
	lstat(place, &sb);
	free(place);
	q = sb.st_mtimespec.tv_sec;
	place = ft_strjoin(dest, rootnm);
	lstat(place, &sp);
	q -= sp.st_mtimespec.tv_sec;
	free(place);
	if (!q)
		return (ft_strcmp(rootnm, nrootnm) >= 0 ? 1 : 0);
	return (q > 0 ? 1 : 0);
}

int		ls_asctime(t_ls *elem1, t_ls *elem2, char *way, int code)
{
	if (code == 0)
		return (ft_strcmp(elem1->nm, elem2->nm));
	else if (code == 1)
		return (ct(elem1->nm, elem2->nm, way));
	else if (code == 2)
		return (elem1->type - elem2->type);
	return (-1);
}

t_ls	*sort_ls(t_ls *list, int flags, char *way, int code)
{
	t_ls	*new;

	if (!(new = list))
		return (NULL);

	sort(&new, way, 0);
	if (code == 2)
		sort(&new, way, code);
	((FLAG_T) == 1) ? sort(&new, way, 1) : NULL;
	((FLAG_LR) == 1) ? reversesort(&new) : NULL;
	return (new);
}

/*
 * code 0 = assci, code 1 = time, code 2 = type
 */

void	sort(t_ls **list, char *way, int code)
{
	t_ls	*a;
	t_ls	*b;
	char	*temp;

	a = *list;
	while (a && a->next)
	{
		b = a->next;
		while (b && b->nm)
		{
			if (ls_asctime(a, b, way, code) > 0)
			{
				temp = ft_strdup(a->nm);
				free(((a)->nm));
				a->nm = ft_strdup(b->nm);
				free(((b)->nm));
				b->nm = ft_strdup(temp);
				ft_swap(&(a->type), &(b->type));
				free(temp);
			}
			b = b->next;
		}
		a = a->next;
	}
}

void	reversesort(t_ls **list)
{
	t_ls	*p;
	t_ls	*q;
	t_ls	*r;

	p = *list;
	q = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*list = q;
}
