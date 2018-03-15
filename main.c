/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:10:30 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/10 17:10:32 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				checktype(char *av, char *dest, int flags)
{
	int			x;
	DIR			*fstgate;
	FILE		*sndgate;
	struct stat	sb;
	char *temp;
	char 		buff[1024];

	x = 0;
	flags--;
	flags++;
	if (ft_strprint(av) && *av != '~' && *av != '/')
		temp = ft_multjoin(3, dest, "/", av);
	else if (*av != '~' && *av != '/')
		temp = ft_strjoin(NULL, av);
	else
		temp = ft_strdup(av);
	lstat(temp, &sb);
	if ((flags % 2) && ((readlink(temp, buff, 1024) != -1)  && !(S_ISDIR(sb.st_mode))))
	{
		free(temp);
		return (2);
		//temp = ft_strdup(buff);
	}

	x += ((fstgate = opendir(temp))) ? 1 : 0;
	x += ((sndgate = fopen(av, "r"))) ? 2 : 0;
	(fstgate) ? closedir(fstgate) : 0;
	(sndgate) ? fclose(sndgate) : 0;

	free(temp);
	if ((S_ISDIR(sb.st_mode) || (x == 1 || x == 3)) || (x == 2 && access(temp, R_OK == -1)))
		return 3; //(S_ISDIR(sb.st_mode)) ? 3 : 4
	else if (!x)
		return (1);
	else
		return (2);
}

void			ft_sl_av(char **av, int ac)
{
	int			i;
	int			d;
	char		*temp;
	int 		j;

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

int	ls_remif_ls(t_ls **begin_list, int i)
{
	t_ls *list;
	t_ls *parent;
	t_ls *tmp;
	int		c;

	list = *begin_list;
	parent = 0;
	c = 0;
	while (list && (tmp = list) && list->nm && ++c)
	{
		if (list->type == i)
		{
			if (parent)
				parent->next = list->next;
			else
				*begin_list = list->next;
			if (i == 1)
				ls_errors(0, list->nm, 0);
			free(list->nm);
			free(list);
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
		root->type = checktype(root->nm, "./", flags);
		if (!(*(av += (*av) ? 1 : 0)))
			break ;
		root->next = tlsnew();
		root = root->next;
	}
	return (newroot);
}

int 			ls_rac(char **av)
{
	int 		c;

	c = 0;
	while (av && (*av))
	{
		if (**av == '-' && *((*av) + 1))
		{
			c++;
			(av)++;
		}
		else
			return (c);
	}
	return (c);
}

int				main(int ac, char **av)
{
	int			flags;
	t_ls		*root;
	int 		i;
	t_ls		*tofree;

	flags = ls_tkflsc(100000000, av++, 1, 0);
	ft_sl_av(av, ac);
	ac -= ls_rac(av);

	while (av && *av && **av == '-' && *(*av + 1))
		av++;
	root = ls_lsavl(av, flags);
	root = sort_ls(root, flags, "./", 0);
	ls_remif_ls(&root, 1);
	(!(i = 0) && ac >= 1 && root) ? ft_lsot(&root, flags) : 0;
	ac = ls_remif_ls(&root, 2);
	tofree = root;

	while (root)
	{
		if (!i)
			write (1, "\n\n", 2);
		if (ac >= 2) // was i++
			ft_printf("%s:\n", root->nm);
		(!(ls_ls(root->nm, flags)) && root->next) ? write(1, "\n", 1) : 0;
		if ((root = root->next))
			write(1, "\n", 1);
	}
	if (ac >= 2 && tofree == root)
		write(1, "\n", 1);
	ls_free(tofree, NULL);
	while (1)
		;
	return (0);
}
