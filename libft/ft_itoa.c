/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:34:37 by ariabyi           #+#    #+#             */
/*   Updated: 2017/11/27 14:38:11 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_power(long n)
{
	int			counter;

	counter = 1;
	if (n == 0)
		return (1);
	while (n && counter++)
		n /= 10;
	return (counter - 1);
}

static	long	ft_sign(int num)
{
	long		n;

	n = (long)num;
	if (n < 0 && n != 0)
		return (-n);
	else
		return (n);
}

char			*ft_itoa(int num)
{
	long		counter;
	long		sign;
	long		power;
	char		*dest;
	long		n;

	n = ft_sign(num);
	counter = 0;
	sign = (num < 0 && num != 0) ? 1 : 0;
	power = ft_power(n);
	if (!(dest = ft_memalloc(power + 1 + sign)))
		return (NULL);
	dest[power + 1 + sign] = '\0';
	while (n > 0)
	{
		dest[counter++] = n % 10 + 48;
		n /= 10;
	}
	if (sign == 1 && num != 0)
		dest[counter++] = '-';
	if (num == 0)
		dest[0] = '0';
	dest = ft_strrev(dest);
	return (dest);
}
