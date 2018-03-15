/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mauxiliary.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
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
				ls_errors(av[w][l], NULL, 1);
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
	*new = (t_exls){0, 0, 0, 0, 0, 0, 0, 0, 10000000, 0, 0, 0, 0, 0, 0, 0};
	new->dest = ft_strdup(s);
	new->flags = flags;
	new->wscol = wscol;

	return (new);
}