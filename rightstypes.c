/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rightstypes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:07:38 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/10 17:07:41 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ls_sst(int *t, int upc, int *wb, int c)
{
	if (c == 1 && *wb >= 4 && (*wb -= 4) >= 0)
		(upc && !(*t)) ? write(1, "S", 1) : write(1, "s", 1);
	else if (c == 2 && *wb >= 2 && (*wb -= 2) >= 0)
		(upc && !(*t)) ? write(1, "S", 1) : write(1, "s", 1);
	else if (c == 3 && *wb >= 1 && (*wb -= 1) >= 0)
		(upc && *t) ? write(1, "t", 1) : write(1, "T", 1);
	else if (*t >= 1)
		write (1, "x", 1);
	else
		write(1, "-", 1);
	(*t) -= (*t) ? 1 : 0;
}

void			ls_rights(char *name, int flags, int wb)
{
	int			rg;
	int			t;
	int			c;
	struct stat	sb;
	int upc;

	if ((lstat(name, &sb) == -1) || (rg = sb.st_mode) == -42)
		return ;
	ls_pr_type(sb, flags, &wb);
	wb = 0;
	wb += (sb.st_mode & S_ISUID) ? 4 : 0;
	wb += (sb.st_mode & S_ISGID) ? 2 : 0;
	wb += (sb.st_mode & S_ISVTX) ? 1 : 0;
	upc = (sb.st_mode % 4096) ? 1 : 0;
	while (rg >= 4096 || (c = 0))
		rg -= 4096;
	while (wb && rg >= 512)
		rg -= 512;
	rg -= ((t = rg / 64) >= 0) ? t * 64 : 0;
	while (c++ < 3)
	{
		(t >= 4 && (t -= 4) >= 0) ? write(1, "r", 1) : write(1, "-", 1);
		(t >= 2 && (t -= 2) >= 0) ? write(1, "w", 1) : write(1, "-", 1);
		if (!wb)
			(t >= 1 && (t -= 1) >= 0) ? write(1, "x", 1) : write(1, "-", 1);
		else
			ls_sst(&t, upc, &wb, c);
		rg -= (!t && rg >= 8 && ((t = rg / 8) != -42)) ? t * 8 : 0;
		rg *= (!t && rg && !(c % 2) && (t = rg) != -42) ? 0 : 1;
	}
}

void			ls_pr_type(struct stat sb, int flags, int *wblocks)
{
	if (flags / 100000 % 2)
		ft_printf("%*d ", (*wblocks), sb.st_blocks);
	if (S_ISFIFO(sb.st_mode))
		write(1, "p", 1);
	else if (S_ISCHR(sb.st_mode))
		write(1, "c", 1);
	else if (S_ISDIR(sb.st_mode))
		write(1, "d", 1);
	else if (S_ISREG(sb.st_mode))
		write(1, "-", 1);
	else if (S_ISLNK(sb.st_mode))
		write(1, "l", 1);
	else if (S_ISSOCK(sb.st_mode))
		write(1, "s", 1);
	else if (S_ISBLK(sb.st_mode))
		write(1, "b", 1);
	else
		write(1, " ", 1);
	(*wblocks) = 0;
}
