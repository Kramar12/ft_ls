/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <aleksandr.rabyj@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:10:30 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/10 17:10:32 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ls_remif_ls(t_ls **begin_list, int i, int c, int *flags)
{
	t_ls		*list;
	t_ls		*parent;
	t_ls		*tmp;

	list = *begin_list;
	parent = NULL;
	while (list && (tmp = list) && list->nm && ++c)
	{
		if (list->tp == i)
		{
			if (parent)
				parent->next = list->next;
			else
				*begin_list = list->next;
			if (i == 1)
				errs(0, list->nm, 0);
			free(list->nm);
			free(list);
			(*flags) += ((*flags) / 100000 % 2) ? 100000 : 0;
		}
		else
			parent = list;
		list = tmp->next;
	}
	return (c);
}

t_ls			*ls_lsavl(char **av, int flags)
{
	char		*t;
	t_ls		*r;
	t_ls		*newroot;

	t = NULL;
	r = NULL;
	newroot = NULL;
	while (*av || !t)
	{
		if (!newroot)
			if ((r = tlsnew()))
				newroot = r;
		if (*av && (t = *av))
			r->nm = *t != '~' ? ft_strdup(t) :
					ft_rfstr("~", t, "/Users/ariabyi", 2);
		else if ((t = ft_strdup("./")))
			if ((r->nm = ft_strdup(t)))
				free(t);
		r->tp = checktype(r->nm, "./", flags);
		if (!(*(av += (*av) ? 1 : 0)))
			break ;
		r->next = tlsnew();
		r = r->next;
	}
	return (newroot);
}

int				ls_rac(char **av)
{
	int			c;

	c = 0;
	while (av && (*av))
		if (**av == '-' && *((*av) + 1) && ++c)
			(av)++;
		else
			return (c);
	return (c);
}

int				main(int ac, char **av)
{
	int			f;
	t_ls		*r;
	int			i;
	t_ls		*tf;

	f = ls_tkflsc(100000000, av++, 1, 0);
	ac -= ls_rac(av);
	while (av && *av && **av == '-' && *(*av + 1))
		av++;
	r = ls_lsavl(av, f);
	r = sort_ls(r, f, "./", 0);
	ls_remif_ls(&r, 1, 0, &f);
	i = (ac >= 1 && r) ? ft_lsot(&r, f) : 0;
	ac = ls_remif_ls(&r, 2, 0, &f);
	tf = r;
	while (r)
	{
		(i++ == 1) ? write(1, "\n\n", 2) : 0;
		(ac >= 2 || f / 100000 % 2) ? ft_printf("%s:\n", r->nm) : 0;
		(!(ls_ls(r->nm, f)) && r->next) ? write(1, "\n", 1) : 0;
		((r = r->next)) ? write(1, "\n", 1) : 0;
	}
	((!errno && ft_putchar('\n')) || tf) ? ls_free(tf, NULL) : 0;
	return (0);
}
