/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:48:44 by ariabyi           #+#    #+#             */
/*   Updated: 2018/01/13 09:18:38 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *string)
{
	unsigned long len;

	len = 0;
	if (!string || !(*string))
		return (0);
	while (string[len] != '\0')
		len++;
	return (len);
}
