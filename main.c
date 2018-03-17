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

void			ft_sl_av(char **av, int ac)
{
	int			i;
	int			d;
	char		*temp;
	int			j;

	j = 1;
	d = 4;
	while (av && av[j] && av[j][0] == '-' && av[j][1])
		j++;
	while (d == 4 && (i = j))
	{
		d = 0;
		while (av && av[i] && --ac)
		{
			if ((av[i + 1] && (ft_strcmp(av[i], av[i + 1])) > 0) || !(i++))
			{
				temp = ft_strdup(av[i + 1]);
				av[i + 1] = ft_strdup(av[i]);
				av[i] = ft_strdup(temp);
				d = 4;
				free(temp);
			}
		}
	}
}

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
	char		*temp;
	t_ls		*root;
	t_ls		*newroot;

	temp = NULL;
	root = NULL;
	newroot = NULL;
	while (*av || !temp)
	{
		if (!newroot)
			if ((root = tlsnew()))
				newroot = root;
		if (*av && (temp = *av))
			root->nm = ft_strdup(temp);
		else if ((temp = ft_strdup("./")))
			if ((root->nm = ft_strdup(temp)))
				free(temp);
		root->tp = checktype(root->nm, "./", flags);
		if (!(*(av += (*av) ? 1 : 0)))
			break ;
		root->next = tlsnew();
		root = root->next;
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
	t_ls		*root;
	int			i;
	t_ls		*tf;

	f = ls_tkflsc(100000000, av++, 1, 0);
	ft_sl_av(av, ac);
	ac -= ls_rac(av);
	while (av && *av && **av == '-' && *(*av + 1))
		av++;
	root = ls_lsavl(av, f);
	root = sort_ls(root, f, "./", 0);
	ls_remif_ls(&root, 1, 0, &f);
	i = (ac >= 1 && root) ? ft_lsot(&root, f) : 0;
	ac = ls_remif_ls(&root, 2, 0, &f);
	tf = root;
	while (root)
	{
		(i++ == 1) ? write(1, "\n\n", 2) : 0;
		(ac >= 2 || f / 100000 % 2) ? ft_printf("%s:\n", root->nm) : 0;
		(!(ls_ls(root->nm, f)) && root->next) ? write(1, "\n", 1) : 0;
		((root = root->next)) ? write(1, "\n", 1) : 0;
	}
	(ft_putchar('\n') && tf) ? ls_free(tf, NULL) : 0;
	return (0);
}
