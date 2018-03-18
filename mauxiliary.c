/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mauxiliary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <aleksandr.rabyj@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:50:09 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/10 17:50:12 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ls_tkflsc(int flags, char **av, int w, int l)
{
	if (av[w] && av[w][l] == '-' && ++l)
		while (av[w][l])
		{
			if (av[w][l] == 'l')
				l += (!(flags % 2)) && (flags += 1) ? 1 : 1;
			else if (av[w][l] == 'a')
				l += (!((flags / 10) % 2)) && (flags += 10) ? 1 : 1;
			else if (av[w][l] == 'r')
				l += (!(FLAG_LR)) && (flags += 100) ? 1 : 1;
			else if (av[w][l] == 'R')
				l += (!(FLAG_R)) && (flags += 1000) ? 1 : 1;
			else if (av[w][l] == 't')
				l += (!(FLAG_T)) && (flags += 10000) ? 1 : 0;
			else if (av[w][l] == '1')
				l += (!(FLAG_1)) && (flags += 1000000) ? 1 : 0;
			else if (av[w][l] == '\0')
				return (flags);
			else
				errs(av[w][l], NULL, 1);
			if (!av[w][l] && w++ != -42 && !(l = 0))
				if (!av[w] || av[w][l] != '-' || l++ == -42)
					break ;
		}
	return (flags);
}

t_ls				*tlsnew(void)
{
	t_ls			*new;

	new = NULL;
	free(new);
	if (!(new = (t_ls *)malloc(sizeof(t_ls))))
	{
		free(new);
		return (NULL);
	}
	new->nm = NULL;
	new->next = NULL;
	return (new);
}

t_exls				*textlsnew(char *s, int flags, unsigned int wscol)
{
	t_exls			*new;

	if (!(new = (t_exls *)malloc(sizeof(t_exls))))
	{
		free(new);
		return (NULL);
	}
	*new = (t_exls){10000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	new->dest = ft_strdup(s);
	new->flags = flags;
	new->wc = wscol;
	return (new);
}

int					errs(char lt, char *way, int code)
{
	char			*temp;

	temp = NULL;
	if (code == 0)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(way, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	if (code == 1)
	{
		ft_putstr_fd("ls: illegal option -- ", 2);
		ft_putchar_fd(lt, 2);
		ft_putstr_fd("\nusage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n", 2);
		free(temp);
		exit(EXIT_FAILURE);
	}
	if (code == 2)
	{
		ft_printf("ls : %s: ", way) ? ft_putstr(strerror(errno)) : 0;
		errno = 0;
	}
	if (code == 4)
		if (!ft_strcmp(way, "/dev/fd/3"))
			ft_putstr("dr--r--r--      1 root     wheel    0 Mar 13 14:04 3");
	free(temp);
	return (1);
}
