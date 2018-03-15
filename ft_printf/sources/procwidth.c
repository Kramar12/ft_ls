/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procwidth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:48:42 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/07 19:48:43 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_takefwp(t_plist *t, const char **f)
{
	if (**f != '.')
	{
		if (t->p != -1)
			return ;
		if ((t->w = ft_atoi(*f)))
			(*f) += ft_power(t->w, 10);
	}
	else if ((t->pnt = 1))
	{
		t->p = ft_atoi(++(*f));
		t->d = 1;
	}
	if ((**f == '0' || (**f == '.' && (t->pnt = 1))) && (*f)++ &&
			(t->d = 1))
	{
		if (!(ft_isdigit(**f)) && (*f)--)
			return ;
		if ((t->p = ft_atoi(*f)))
			(*f) += ft_power(t->p, 10);
	}
	if ((t->w != 10 && (*((*f) - 1)) != '0') || ft_iselet(**f, 2, 0, 0))
		(*f)--;
}

int				ft_setwidth(t_plist *t, ssize_t ss, int base, int lacuna)
{
	int			power;

	power = base != 1 ? ft_power(ss, base) : (int)ss;
	if (base != 1)
		t->w = lacuna >= power ? (t->w - lacuna + 1) : (t->w - power + 1);
	t->w -= (!(t->f % 2) || base == 1) ? 0 : 1;
	t->w -= (base <= 0 && ((t->f / 100) % 2) && !(t->f % 2)) ? 1 : 0;
	t->w -= ((((t->f / 1000) % 2) && base > 0) && base != 1) ? 1 : 0;
	t->w += ((t->f % 2) && (t->f / 1000 % 2)) ? 1 : 0;
	while (t->w-- > 1)
		if (((t->f / 10) % 2 && t->f / 10 % 10 != 3 && (!((t->f /
				100) % 2)) && t->p == -1))
		{
			if (ss < 0 && !t->sign && (t->sign = 1))
				t->r += ft_putchar('-');
			if (ss >= 0 && !t->sign && ((t->f / 1000) % 2) &&
					(t->sign = 1))
				t->r += ft_putchar('+');
			t->r += ft_putchar('0');
		}
		else
			t->r += ft_putchar(' ');
	return (0);
}

void			ft_setproc(t_plist *t, ssize_t ss, int base, char x)
{
	int			lacuna;
	short int	power;

	power = ft_power(ss, base);
	if ((t->f / 10000) % 2 && ft_iselet(x, 4, 5, 0))
		t->w -= ft_iselet(x, 4, 7, 0) ? 2 : 1;
	lacuna = t->p;
	if (!(t->f / 100) % 2)
		ft_setwidth(t, ss, base, lacuna);
	t->p = t->p >= power ? (t->p - power + 1) : 0;
	t->p += (x == 'p' && !ss && t->d) ? 1 : 0;
	t->r += (!t->sign && base < 0 && 10 + t->p++ && (t->sign = 1)) ?
			ft_putchar('-') : 0;
	t->w += (base < 0 && (t->f / 100) % 2) ? 1 : 0;
	while (t->p-- > 1)
		t->r += ft_putchar('0');
	t->p = -1;
}

int				ft_setall(t_plist *types, ssize_t ss, int base, char x)
{
	ss = 0;
	if (!types->sign && base == 10 && (((types->f / 1000) % 2)) && x != 'u'
		&& x != 'U' && (types->sign = 1))
		types->r += ft_putchar('+');
	else if (base == 10 && (((types->f / 1) % 2)) && x != 'u' && x != 'U')
		types->r += ft_putchar(' ');
	return (0);
}
