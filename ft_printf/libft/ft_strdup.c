/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:08:34 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/07 11:17:33 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
	{
		free(&dest);
		return (0);
	}
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
