/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:32:34 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/13 13:26:52 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	if (!(dest = ft_memalloc(len + 1)))
	{
		free(dest);
		return (NULL);
	}
	while (s[start] != '\0' && j < len)
		dest[j++] = s[start++];
	dest[j] = '\0';
	return (dest);
}
