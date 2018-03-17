/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <aleksandr.rabyj@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:35:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/12 15:35:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int							ls_ls(char *dest, int flags)
{
	char					*way;
	t_ls					*tape;

	way = (dest) ? ls_takeway(dest, 1) : ls_takeway("./", 1);
	get_files(way, flags, &tape);
	if (!(FLAG_R))
		newls_whip(way, tape, flags);
	else
		ls_listrec(way, flags, tape, 0);
	ls_free(tape, NULL);
	free(way);
	return (0);
}

int							get_files(char *way, int flags, t_ls **root)
{
	DIR						*dir;
	struct dirent			*entry;
	t_ls					*tape;

	entry = NULL;
	if (!(dir = opendir(way)))
		if (errs(0, way, 2))
			return (-1);
	tape = ls_tsd(dir, entry, flags, way);
	tape = sort_ls(tape, flags, way, 1);
	dir ? closedir(dir) : 0;
	*root = tape;
	return (1);
}

void						ls_whipe(const char *way, char *tnm, int c, int fs)
{
	char					*path;
	t_ls					*subdir;

	if (way[ft_strlen(way) - 1] != '/')
		path = ft_multjoin(3, way, "/", tnm);
	else
		path = ft_strjoin(way, tnm);
	if (!ft_strcmp(path, "/usr/share/man/man3"))
		write(1, "\n", 1);
	if ((c = (get_files(path, fs, &subdir))) != -1)
	{
		ls_listrec(path, fs, subdir, c);
		c ? ls_free(subdir, NULL) : 0;
	}
	free(path);
}

void						ls_listrec(const char *way, int f, t_ls *t, int c)
{
	if (c && t->nm)
		ft_printf("\n\n%s:\n", way);
	else if (c)
		ft_printf("\n\n%s:", way);
	while (t)
	{
		newls_whip((char *)way, t, f);
		while (t)
		{
			if (t->nm && ft_mstrcmp(3, t->nm, ".", "..",
									"./", "../") && t->tp == 3)
			{
				ls_whipe(way, t->nm, c, f);
			}
			t = t->next;
		}
	}
	ls_free(t, NULL);
}

int							newls_whip(char *way, t_ls *tape, int flags)
{
	t_exls					*ext;
	struct winsize			w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	if (w.ws_col > 168 && w.ws_col < 240)
		w.ws_col = 168;
	else if (w.ws_col > 240 && w.ws_col < 336)
		w.ws_col = 240;
	else if (w.ws_col > 336)
		w.ws_col = 336;
	w.ws_col *= (FLAG_1) ? 0 : 1;
	ext = textlsnew(way, flags, w.ws_col);
	ls_getwidth(tape, ext, flags);
	if (ext->flags % 2)
		ls_lpr(tape, ext, 0);
	else
		ls_prnt(tape, ext);
	if (ext)
		ls_free(NULL, ext);
	return (1);
}
