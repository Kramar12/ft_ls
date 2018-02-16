/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 13:17:49 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/13 13:27:38 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) +
						ft_strlen(s2) + 1))))
	{
		free(dest);
		return (NULL);
	}
	while (s1 && *s1)
		dest[i++] = *s1++;
	while (s2 && *s2)
		dest[i++] = *s2++;
	dest[i] = '\0';
	return (dest);
}
