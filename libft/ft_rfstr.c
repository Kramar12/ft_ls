/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rfstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 12:59:13 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/18 13:00:54 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_rfstr(char *wt, char *wr, char *wh, int code)
{
	char			*temp;
	char			*temp2;
	unsigned int	i;
	unsigned int	ti;
	char			*ret;

	i = 0;
	while (!(ti = 0) && wr[i])
	{
		while (*wt == wr[i] && wt++ && (int)(ti = !ti ? i : ti) >= 0)
			i++;
		if (++i == 0 || !*wt)
		{
			temp = ft_strsub(wr, 0, ti);
			temp2 = ft_strsub(wr, i - 1, ft_strlen(wr));
			if ((ret = NULL) || code == 1)
				ret = ft_strjoin(temp, temp2);
			else if (code == 2)
				ret = ft_multjoin(3, temp, wh, temp2);
			free(temp);
			free(temp2);
			return (ret);
		}
	}
	return (NULL);
}
