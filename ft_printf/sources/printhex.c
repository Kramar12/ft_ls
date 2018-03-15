/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:50:36 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/08 18:02:36 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_printnumb(t_plist *t, size_t num, char x, int bs)
{
	int			lacuna;

	lacuna = t->p;
	num = ((x == 'x' || x == 'X' || x == 'o' || x == 'u') && !ft_iffsd(t, 1))
		? (unsigned int)num : num;
	t->p -= ((x == 'o' || x == 'O') && (t->f / 10000) % 2) ? 1 : 0;
	if ((!((t->f / 100) % 2)) && (ft_printsf(t, x, num, 0)) < 42)
	{
		t->sst *= (((t->f / 10) % 2) && ft_printsf(t, x, num, 1)) ? 1 : 1;
		t->sst *= ((t->w > t->p) && ft_setwidth(t, num, bs, lacuna)) ? 1 : 1;
	}
	if ((!((t->f / 10) % 2) || ((t->f / 100) % 2)))
		if ((x == 'p' && (ft_printsf(t, x, num, 0))) || x != 'p')
			ft_printsf(t, x, num, 1);
	ft_setproc(t, num, bs, x);
	if (num == 0 && t->d == 1 && t->p <= 0 && (!((t->f / 10) % 2)))
		t->r += (t->w >= 0) ? ft_putchar(' ') : 0;
	else if (!(x == 'o' && num == 0 && ((t->f / 10000) % 2)))
		if ((num >= (size_t)bs && (t->r += ft_printhex(num / bs, bs, 0, x)))
			|| num < (size_t)bs)
			t->r += ft_printhex(num % bs, bs, 0, x);
	t->sst *= (((t->f / 100) % 2) && (t->w > lacuna) &&
			ft_setwidth(t, num, bs, lacuna)) ? 1 : 1;
}

void			ft_printssnum(t_plist *t, ssize_t ssnum, char x, int base)
{
	int			lac;

	lac = t->p;
	t->w = t->w;
	base = ssnum >= 0 ? base : -base;
	ft_printsf(t, x, ssnum, 1);
	ft_printsf(t, x, ssnum, 0);
	if (!((t->f / 1000) % 2))
		ft_setall(t, ssnum, base, x);
	t->st *= ((!((t->f / 100) % 2)) && (t->w > t->p && base > 0)
		&& ft_setwidth(t, ssnum, base, lac)) ? 1 : 1;
	t->st *= ((!((t->f / 100) % 2)) && (t->w > t->p && base <= 0)
		&& ft_setwidth(t, ssnum, base, (lac + 1))) ? 1 : 1;
	if ((((t->f / 1000) % 2) && !ft_setall(t, ssnum, base, x)) || x)
		ft_setproc(t, ssnum, base, x);
	if (ssnum == 0 && t->d == 1 && t->p <= 0 && (!((t->f / 10) % 2)))
		t->r += (t->w >= 0) ? ft_putchar(' ') : 0;
	else
		t->st *= ((lac || ssnum) && ft_putnbrpr(t, ssnum)) ? 1 : 1;
	t->st *= (((t->f / 100) % 2) && (t->w > lac && base > 0)
		&& ft_setwidth(t, ssnum, base, lac)) ? 1 : 1;
	t->st *= (((t->f / 100) % 2) && (t->w > lac && base <= 0)
		&& ft_setwidth(t, ssnum, base, (lac + 1))) ? 1 : 1;
}

int				ft_printsf(t_plist *t, char f, ssize_t num, int code)
{
	int			i;

	i = t->w;
	if (ft_iselet(f, 4, 5, 0) && (((t->f / 10000) % 2) || f == 'p') && ((num
		|| f == 'o' || f == 'O') || (f == 'p')))
	{
		t->r += (f == 'X' && code == 1) ? ft_putstr("0X") : 0;
		t->w -= (f == 'X' && code != 1) ? 2 : 0;
		if (f != 'X')
		{
			if (f == 'p' || f == 'x')
			{
				t->r += (code == 1 && (t->ishsh = 1)) ? ft_putstr("0x") : 0;
				t->w -= (code != 1) ? 1 : 0;
			}
			else
				t->r += (code == 1 && (t->ishsh = 1)) ? ft_putchar('0') : 0;
			t->w -= (code != 1) ? 1 : 0;
		}
	}
	return (i != t->w) ? 1 : 0;
}

int				ft_putnbrpr(t_plist *types, ssize_t n)
{
	size_t		num;

	if (n < 0)
	{
		if (types->p != -1)
			types->r += ft_putchar('-');
		num = (size_t)-n;
	}
	else
		num = (size_t)n;
	if (num >= 10)
	{
		ft_putnbrpr(types, num / 10);
		ft_putnbrpr(types, num % 10);
	}
	else
		types->r += (ft_putchar((int)(num + 48)));
	return (0);
}

int				ft_simplpchr(char b)
{
	write(1, &b, 1);
	return (1);
}
