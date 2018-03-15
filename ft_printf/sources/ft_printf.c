/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:01:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/07 20:01:04 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(char *field, ...)
{
	int			ret;
	t_plist		*types;
	va_list		ap;

	types = pr_listnew(1);
	va_start(ap, field);
	ret = ft_percent(ap, types, (const char **)&(field));
	va_end(ap);
	free(types);
	return (ret);
}

t_plist			*pr_listnew(int i)
{
	t_plist		*new;

	if (!(new = (t_plist *)malloc(sizeof(t_plist) * i)))
	{
		free(new);
		return (0);
	}
	*new = (t_plist) {100000000000, NULL, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	return (new);
}

int				ft_tob(t_plist *t)
{
	*t = (t_plist){100000000000, NULL, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, t->r};
	return (0);
}
