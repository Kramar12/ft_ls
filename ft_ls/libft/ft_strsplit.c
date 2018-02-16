/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 09:29:41 by ariabyi           #+#    #+#             */
/*   Updated: 2018/02/13 13:36:14 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_trimfsplit(char const *s, char c, int *counter)
{
	int		j;
	int		q;
	char	*dest;

	j = 0;
	q = (ft_strlen(s) - 1);
	if (!(dest = (char*)malloc((sizeof(char)) * (q + 1))))
	{
		free(dest);
		return (NULL);
	}
	while (s[*counter] == c && s[*counter])
		(*counter)++;
	while (s[q] == c && s[q])
		q--;
	while (s[*counter] && *counter <= q && s[*counter] != c)
		dest[j++] = s[(*counter)++];
	dest[j] = '\0';
	return (dest);
}

static	int		ft_numbofwords(char const *s, char c)
{
	int		i;
	int		counter;
	char	inword;

	counter = 1;
	i = -1;
	inword = (s[0] == c) ? 0 : 1;
	while (s[++i])
	{
		if (s[i] != c && inword == 1 && counter++)
			inword = 0;
		if (s[i] == c && s[i])
			inword = 1;
	}
	return (counter - 1);
}

char			**ft_strsplit(const char *str, char c)
{
	int		j;
	int		wrd;
	int		counter;
	char	**s;

	if (!str)
		return (NULL);
	counter = 0;
	j = -1;
	wrd = ft_numbofwords(str, c);
	if (!(s = (char **)malloc(sizeof(char *) * (wrd + 2))))
	{
		free(s);
		return (NULL);
	}
	while (++j < wrd && str[counter])
	{
		s[j] = ft_trimfsplit(str, c, &counter);
		if (!s[j])
		{
			while (j > -1)
				ft_strdel(&s[j--]);
			return (NULL);
		}
	}
	s[j] = NULL;
	return (s);
}
