/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <ariabyi@student.unit.ua>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:35:00 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/12 15:35:00 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int             			ls_ls(char *dest, int flags)
{
	char					*way;
	t_ls					*tape;

	//islink()
	way = (dest) ? ls_takeway(dest, 1) : ls_takeway("./", 1);
	get_files(way, flags, &tape);

	if (!(FLAG_R))
		newls_whip(way, tape, flags);
	else
		ls_listrec(way, flags, tape, 0);
//	while (1)
//		;
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
		if (ls_errors(0, way, 2))
			return (-1);
	tape = ls_tsd(dir, entry, flags, way);
	tape = sort_ls(tape, flags, way, 1);
	dir ? closedir(dir) : 0;
	*root = tape;
	return (1);
}

void						ls_listrec(const char *way, int flags, t_ls *tape, int code)
{
	char					*path;
	t_ls					*subdir;

	if (code && tape->nm)
		ft_printf("\n\n%s:\n", way);
	else if (code)
		ft_printf("\n\n%s:", way);
	while (tape)
	{
		newls_whip((char *)way, tape, flags);
		while (tape)
		{

			if (tape->nm && ft_mstrcmp(3, tape->nm, ".", "..", "./", "../") && tape->type == 3)
			{
				if (way[ft_strlen(way) - 1] != '/')
					path = ft_multjoin(3, way, "/", tape->nm);
				else
					path = ft_strjoin(way, tape->nm);
				if ((code = (get_files(path, flags, &subdir))) != -1)
				{
					ls_listrec(path, flags, subdir, code);
					ls_free(subdir, NULL);
				}
				free(path);
				path = NULL;
			}
			tape = tape->next;
		}
	}
	ls_free(tape, NULL);
}

void						newls_whip(char *way, t_ls *tape, int flags)
{
	t_exls					*ext;
	struct winsize			w;


 	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	w.ws_col = 100;
	if (w.ws_col > 168 && w.ws_col < 240)
		w.ws_col = 168;
	else if (w.ws_col > 240 && w.ws_col < 336)
		w.ws_col = 240;
	else if (w.ws_col > 336)
		w.ws_col = 336;
	w.ws_col *= (FLAG_1) ? 0 : 1;
	ext = textlsnew(way, flags, w.ws_col);
	if (ext->flags % 2)
		ls_lpr(tape, ext, 0);
	else
		ls_prnt(tape, ext);
	ls_free(NULL, ext);
}
