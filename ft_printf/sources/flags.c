/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:31:26 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/07 18:51:17 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_checkflags(t_plist *types, size_t num, const char **f)
{
	if (**f == ' ' && (!((types->f / 1) % 2)))
		*f = (types->f += 1) ? ++(*f) : *f;
	if (**f == '0' && (!((types->f / 10) % 2)) && *((*f) - 1) != '.')
		*f = (types->f += 10) ? ++(*f) : *f;
	if (**f == '-' && (!((types->f / 100) % 2)))
		*f = (types->f += 100) ? ++(*f) : *f;
	if (**f == '+' && (!((types->f / 1000) % 2)))
		*f = (types->f += 1000) ? ++(*f) : *f;
	if (**f == '#' && (!((types->f / 10000) % 2)))
		*f = (types->f += 10000) ? ++(*f) : *f;
	if (**f == 'h' && (!((types->f / 100000) % 2)))
		*f = (types->f += 100000) ? ++(*f) : *f;
	if (**f == 'h' && (!((types->f / 1000000) % 2)))
		*f = (types->f += 1000000) ? ++(*f) : *f;
	if (**f == 'l' && (!((types->f / 10000000) % 2)))
		*f = (types->f += 10000000) ? ++(*f) : *f;
	if (**f == 'l' && (!((types->f / 100000000))))
		*f = (types->f += 100000000) ? ++(*f) : *f;
	if (**f == 'j' && (!((types->f / 1000000000) % 2)))
		*f = (types->f += 1000000000) ? ++(*f) : *f;
	if (**f == 'z' && (!((types->f / 10000000000) % 2)))
		*f = (types->f += 10000000000) ? ++(*f) : *f;
	return (num == types->f) ? 0 : (*(--(*f)) * 0 + 1);
}

int			ft_turnf(t_plist *types, ssize_t *s)
{
	if ((((types->f / 100000) % 2)) && !ft_iffsd(types, 2)
		&& !((types->f / 1000000) % 2))
		*s = (short int)*s;
	else if ((types->f / 1000000) % 2 && !ft_iffsd(types, 2))
		*s = (signed char)*s;
	else if ((((types->f / 10000000) % 2)) && (!((types->f / 100000000) % 2)))
		*s = (long int)*s;
	else if ((types->f / 100000000) % 2)
		*s = (long long int)*s;
	else if ((types->f / 1000000000) % 2)
		*s = (intmax_t) * s;
	else if ((types->f / 10000000000) % 2)
		*s = (ssize_t)*s;
	else
		return (0);
	return (1);
}

int			ft_turns(t_plist *types, size_t *s, char x)
{
	if (x != 'U' && (((types->f / 100000) % 2)) && !ft_iffsd(types, 2) &&
			!((types->f / 1000000) % 2))
		*s = (unsigned short int)*s;
	else if ((types->f / 1000000) % 2 && !ft_iffsd(types, 2) &&
			(ft_wcase(x) || x == 'X'))
		*s = (unsigned char)*s;
	else if ((((types->f / 10000000) % 2)) &&
			(!((types->f / 100000000) % 2)))
		*s = (unsigned long int)*s;
	else	if ((types->f / 100000000) % 2)
		*s = (unsigned long long int)*s;
	else	if ((types->f / 1000000000) % 2)
		*s = (uintmax_t) * s;
	else	if ((types->f / 10000000000) % 2)
		*s = (size_t)*s;
	else
		return (0);
	return (1);
}

int			ft_iffsd(t_plist *types, int code)
{
	if (code == 1 && (((types->f / 100000) % 2) || ((types->f / 1000000) % 2)
			|| ((types->f / 10000000) % 2) || ((types->f / 100000000) % 2)
			|| ((types->f / 1000000000) % 2) || ((types->f / 10000000000) % 2)))
		return (1);
	if (code == 2 && (((types->f / 10000000) % 2) || ((types->f / 100000000) %
			2) || ((types->f / 1000000000) % 2)
			|| ((types->f / 10000000000) % 2)))
		return (1);
	return (0);
}
