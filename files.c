/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <ariabyi@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:37:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/02 16:37:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_lsot(t_ls **root, int flags)
{
	t_exls			*ext;
	t_ls 			*new_root;
	struct winsize	w;


	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (w.ws_col > 168 && w.ws_col < 240)
		w.ws_col = 168;
	else if (w.ws_col > 240 && w.ws_col < 336)
		w.ws_col = 240;
	else if (w.ws_col > 336)
		w.ws_col = 336;
	w.ws_col *= (FLAG_1) ? 0 : 1;
	ext = textlsnew("./", flags, w.ws_col);
	new_root = ls_argfl(*root);
	if (new_root && new_root->nm)
	{
		if (ext->flags % 2)
			ls_lpr(new_root, ext, 1);
		else
			ls_prnt(new_root, ext);
//		if (new_root->type)
//			write (1, "\n\n", 2);
//		else
//			write (1, "\n", 1);
	}
	ls_free(new_root, ext);
	return (0);
}

t_ls					*ls_argfl(t_ls *nroot)
{
	t_ls			*tape;
	t_ls			*newroot;

	tape = tlsnew();
	newroot = tape;
	while (nroot)
	{
		if (nroot->type == 2)
		{
			tape->nm = ft_strdup(nroot->nm);
		}
		nroot = nroot->next;
		if (nroot && (nroot->type == 2) && tape->nm)
		{
			tape->next = tlsnew();
			tape = tape->next;
		}
	}
	return (newroot);
}
