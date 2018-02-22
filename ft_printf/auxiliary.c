/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:32:59 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/07 19:33:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_iselet(char f, int code, size_t start, size_t end)
{
	char			*s;

	s = "0-+# hljz";
	if (code == 1)
		s = ".123456789";
	if (code == 2)
		s = "%aAcCdDeEfFgGioOpsSuUxX";
	if (code == 3)
		s = "%cCsS";
	if (code == 4)
		s = "idDuUOoxXp";
	if (!end)
		end = 1 + ft_strlen(s);
	while (s[start] && start != end)
		if (f == s[start++])
			return (1);
	return (0);
}

short int			ft_power(ssize_t num, int base)
{
	short int		counter;

	counter = 1;
	if (num < 0 || base < 0)
		counter++;
	if (num == base)
		return (counter);
	while ((num /= base))
		counter++;
	return (counter);
}

size_t				ft_putstr_u(const char *s, ssize_t end)
{
	int				c;
	size_t			i;
	size_t			ret;

	if (!s)
		return (0);
	i = 0;
	ret = 0;
	while (s[i] || s[i + 1] || s[i + 2] || s[i + 3])
	{
		c = 0;
		c += (unsigned char)s[i];
		c += ((int)((unsigned char)s[i + 1])) << 8;
		c += ((int)((unsigned char)s[i + 2])) << 16;
		c += ((int)((unsigned char)s[i + 3])) << 24;
		if (ft_check(c) != 1 && (ret + ft_check(c)) > (size_t)end)
			return (ret);
		ret += ft_qputchar(c);
		if (ret >= (size_t)end)
			return (ret);
		i += 4;
	}
	return (ret);
}

size_t				ft_ascount(const char *s, int prec)
{
	int				c;
	int				ret;
	size_t			i;

	ret = 0;
	i = 0;
	while (s[i] || s[i + 1] || s[i + 2] || s[i + 3])
	{
		c = 0;
		c += (unsigned char)s[i] << 0;
		c += ((int)((unsigned char)s[i + 1])) << 8;
		c += ((int)((unsigned char)s[i + 2])) << 16;
		c += ((int)((unsigned char)s[i + 3])) << 24;
		i += 4;
		if ((prec == -1 || ret + 1 <= prec) && c <= 127)
			ret += 1;
		else if ((prec == -1 || ret + 2 <= prec) && c <= 2047)
			ret += 2;
		else if ((prec == -1 || ret + 3 <= prec) && c <= 65535)
			ret += 3;
		else	if ((prec == -1 || ret + 4 <= prec) && c <= 2097151)
			ret += 4;
	}
	return (ret);
}

int					ft_check(int c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else if (c <= 2097151)
		return (4);
	return (0);
}
