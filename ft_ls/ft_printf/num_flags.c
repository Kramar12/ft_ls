/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:28:15 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/07 19:28:17 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_percent(va_list ap, t_plist *t, const char **f)
{
	while (**f && **f != '%')
		t->r += ft_putchar(*((*f)++));
	while (**f)
	{
		if (**f == '%')
			ft_major(ap, t, f);
		t->r += (**f && !t->pct) ? ft_putchar(**f) : 0;
		*f += (ft_tob(t) || **f) ? 1 : 0;
	}
	return (t->r);
}

void			ft_major(va_list ap, t_plist *t, const char **f)
{
	while (!(t->pp) && *(++(*f)) && (t->pct = 1))
	{
		if (ft_iselet(**f, 0, 0, 0))
			ft_checkflags(t, t->f, f);
		else if (**f == '*')
			t->w = va_arg(ap, int);
		else if (ft_iselet(**f, 1, 0, 0) && !t->fwp)
			ft_takefwp(t, f);
		else if (ft_iselet(**f, 3, 0, 0))
			ft_sflags(ap, t, f);
		else if (ft_iselet(**f, 4, 0, 0))
			ft_dflags(ap, t, f);
		else
		{
			if (!((t->f / 100) % 2))
				t->r += ((!((t->f / 100) % 2)) && ft_setwidth(t, **f, 1, 0))
				? 0 : ft_putchar(**f);
			else
				t->r += (ft_putchar(**f) && ft_setwidth(t, **f, 1, 0)) ? 1 : 1;
			break ;
		}
	}
}

void			ft_dflags(va_list ap, t_plist *types, const char **f)
{
	if ((types->pp = 1) && (**f == 'd' || **f == 'D' || **f == 'i'))
	{
		types->sst = va_arg(ap, ssize_t);
		if (**f == 'D' || ft_turnf(types, &types->sst))
			ft_printssnum(types, types->sst, **f, 10);
		else
			ft_printssnum(types, (int)types->sst, **f, 10);
	}
	else
	{
		types->st = va_arg(ap, size_t);
		ft_turns(types, &types->st, **f);
		if (**f == 'x' || **f == 'X' || **f == 'p')
			ft_printnumb(types, types->st, **f, 16);
		else if (**f == 'o' || **f == 'O')
			ft_printnumb(types, types->st, **f, 8);
		else if (**f == 'u' || **f == 'U')
			ft_printnumb(types, types->st, **f, 10);
	}
}

void			ft_sflags(va_list ap, t_plist *t, const char **f)
{
	if ((t->pp = 1) && (**f == 'c' || **f == 'C' || **f == '%'))
	{
		t->w *= (!((t->f / 100) % 2)) ? ft_setwidth(t, 1, 1, 0) : 1;
		t->sst = **f != '%' ? va_arg(ap, ssize_t) : 0;
		if (**f && **f != '%')
			t->r += (MB_CUR_MAX == 4 && t->sst <= 2097151 && (**f == 'C' ||
			(((t->f / 10000000) % 2) && (!((t->f / 100000000) % 2))))) ?
			ft_qputchar(t->sst) : ft_simplpchr(t->sst);
		else
			t->r += ft_putchar('%');
		t->w *= ((t->f / 100) % 2) ? ft_setwidth(t, 1, 1, 0) : 1;
	}
	else
	{
		t->s = va_arg(ap, char *);
		ft_s(t, f);
	}
}

void			ft_s(t_plist *t, const char **f)
{
	int			isnull;
	ssize_t		length;

	isnull = 0;
	if ((!t->s && !t->d && t->w == -1) && (t->s = "(null)"))
		isnull = 1;
	if (!t->s || !(**f == 'S' || (((t->f / 10000000) % 2) &&
			(!((t->f / 100000000) % 2)))))
		length = t->s ? (int)ft_strlen(t->s) : 6;
	else
		length = ft_ascount(t->s, t->p);
	length = (t->p != -1 && t->p <= length) ? t->p : length;
	length *= (t->p == -1 && t->pnt) ? 0 : 1;
	t->w += t->s ? 1 - length : 1;
	t->w *= (!((t->f / 100) % 2)) ? ft_setwidth(t, length, 1, 0) : 1;
	while (t->s && *t->s && length-- > 0)
		if ((t->sst = *t->s) && t->sst <= 127)
			if ((**f == 'S' || (((t->f / 10000000) % 2) && (!((t->f / 100000000)
				% 2)))) && !isnull && (t->r += ft_putstr_u(t->s++, length + 1)))
				break ;
			else
				t->s += (t->r += ft_simplpchr(t->sst)) ? 1 : 1;
		else
			t->r += ft_qputchar(t->sst);
	t->w *= ((t->f / 100) % 2) ? ft_setwidth(t, length, 1, 0) : 1;
}
