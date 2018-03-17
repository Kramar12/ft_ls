/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <aleksandr.rabyj@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 16:37:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/02 16:37:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					ft_lsot(t_ls **root, int flags)
{
	t_exls			*ext;
	t_ls			*new_root;
	struct winsize	w;
	int				i;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (!(i = 0) && w.ws_col > 168 && w.ws_col < 240)
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
		i++;
	}
	ls_free(new_root, ext);
	return (i);
}

t_ls				*ls_argfl(t_ls *nroot)
{
	t_ls			*tape;
	t_ls			*newroot;

	tape = tlsnew();
	newroot = tape;
	while (nroot)
	{
		if (nroot->tp == 2)
		{
			tape->nm = ft_strdup(nroot->nm);
		}
		nroot = nroot->next;
		if (nroot && (nroot->tp == 2) && tape->nm)
		{
			tape->next = tlsnew();
			tape = tape->next;
		}
	}
	return (newroot);
}

int					help_ct(int flags, char *temp, mode_t stmode)
{
	char			buff[1024];

	if ((flags % 2) && ((readlink(temp, buff, 1024) != -1)
						&& !(S_ISDIR(stmode))))
	{
		free(temp);
		return (2);
	}
	return (0);
}

int					checktype(char *av, char *dest, int flags)
{
	int				x;
	DIR				*fstgate;
	FILE			*sndgate;
	struct stat		sb;
	char			*temp;

	if (!(temp = NULL) && ft_strprint(av) && *av != '~' && *av != '/')
		temp = ft_multjoin(3, dest, "/", av);
	temp = (!temp && *av != '~' && *av != '/') ? ft_strjoin(NULL, av) : temp;
	temp = (!temp) ? ft_strdup(av) : temp;
	lstat(temp, &sb);
	if ((x = 0) || (help_ct(flags, temp, sb.st_mode) == 2))
		return (2);
	x += ((fstgate = opendir(temp))) ? 1 : 0;
	x += ((sndgate = fopen(av, "r"))) ? 2 : 0;
	(fstgate) ? closedir(fstgate) : 0;
	(sndgate) ? fclose(sndgate) : 0;
	free(temp);
	if ((S_ISDIR(sb.st_mode) || (x == 1 || x == 3))
		|| (x == 2 && access(temp, R_OK == -1)))
		return (3);
	return (!x) ? (1) : (2);
}
