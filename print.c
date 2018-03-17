/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twenty_five_functions_withlove.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <ariabyi@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 19:25:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/16 19:25:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char					*ls_lprhp(char *rootnm, int flags, char *exdest)
{
	char				*dest;

	dest = NULL;
	if (*rootnm == '/' && rootnm[ft_strlen(rootnm) - 1] != '/')
		dest = ft_strdup(rootnm);
	if (!dest && (FLAG_R))
		dest = ft_multjoin(3, exdest, "/", rootnm);
	else if (!dest)
		dest = ft_strjoin(exdest, rootnm);
	return (dest);
}

void					ls_lpr(t_ls *root, t_exls *ext, int code)
{
	char				*dest;
	char				*temp;

	(ext->s) && !code ? ft_printf("total %d\n", ext->tt) : 0;
	while (root && root->nm)
	{
		if (*(temp = slovo(root->nm)) != '.' || ((ext->flags / 10) % 2))
		{
			free(temp);
			dest = ls_lprhp(root->nm, ext->flags, ext->dest);
			if (!(ls_rights(dest, ext->b)))
			{
				free(dest);
				root = root->next;
				continue ;
			}
			get_time(dest, ext, root->nm);
			(root->next && root->next->nm) ? write(1, "\n", 1) : 0;
			dest ? free(dest) : 0;
		}
		root = root->next;
	}
}

void					ls_prnt(t_ls *root, t_exls *ext)
{
	int					i;
	char				*temp;
	char				*place;

	temp = NULL;
	place = NULL;
	while (++ext->ww % 8 || (i = 0))
		;
	while (root && root->nm)
	{
		if (i + ext->ww > ext->wc || ((i / ext->ww == ext->cw / 2 + 1
			&& ext->cw * ext->ww > ext->wc)))
			i *= ft_printf("\n%-*s", ext->ww, root->nm) ? 0 : 0;
		else
			ft_printf("%-*s", ext->ww, root->nm);
		free(temp);
		free(place);
		place = NULL;
		i += (root->nm) ? ext->ww : 0;
		root = root->next;
		temp ? free(temp) : 0;
		temp = NULL;
	}
}
