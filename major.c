/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   major.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:00:35 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/16 17:00:36 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					pwgr(uid_t uid, gid_t gid, nlink_t nlink, t_exls *ext)
{
	struct passwd		*pw;
	struct group		*gr;

	pw = getpwuid(uid);
	gr = getgrgid(gid);
	ft_printf("%*d %-*s  %-*s  ", ext->lls + 1, nlink, ext->lo,
		pw->pw_name, ext->lg, gr->gr_name);
}

int						get_time(char *place, t_exls *ext, char *name)
{
	char				*t;
	struct stat			sb;
	char				buff[1024];
	int					kata;

	lstat(place, &sb);
	ls_acl(place);
	kata = 0;
	if ((readlink(place, buff, 1024) != -1) && (kata = 1))
	{
		t = ft_multjoin(3, name, " -> ", buff);
		name = ft_strdup(t);
		free(t);
	}
	pwgr(sb.st_uid, sb.st_gid, sb.st_nlink, ext);
	if (ext->dev || (S_ISBLK(sb.st_mode) || S_ISCHR(sb.st_mode)))
		(ext->dev = 1) ? ft_printf("%*llu, %*llu ",
				ext->lj, MAJOR(sb.st_rdev), ext->lm, MINOR(sb.st_rdev)) : 0;
	else
		ft_printf("%*zu ", ext->lsz, sb.st_size);
	ft_printf("%s %s", (t =
		ft_strsub(ctime((const time_t *)&sb.st_mtimespec), 4, 12)), name);
	free(t);
	(kata) ? free(name) : 0;
	return (1);
}

int						ls_helpget(char *pl, t_exls **ext, char *rnm, int f)
{
	struct passwd		*p;
	struct group		*g;
	struct stat			sb;
	t_exls				*e;

	e = *ext;
	lstat(pl, &sb);
	e->ww = ft_strlen(rnm) > e->ww ? ft_strlen(rnm) : e->ww;
	e->cw++;
	if (!(f % 2))
		return (1);
	if ((p = getpwuid(sb.st_uid)))
		e->lo = ft_strlen(p->pw_name) > e->lo ? ft_strlen(p->pw_name) : e->lo;
	if ((g = getgrgid(sb.st_gid)))
		e->lg = ft_strlen(g->gr_name) > e->lg ? ft_strlen(g->gr_name) : e->lg;
	if ((sb.st_blksize < 0 || sb.st_rdev < 0) && !S_ISLNK(sb.st_mode))
		return (0);
	e->tt += (sb.st_blksize >= 0 && sb.st_rdev >= 0) ? sb.st_blocks : 0;
	e->tt *= (PWR(e->tt) <= 7) ? 1 : 0;
	e->lls = PWR(sb.st_nlink) > e->lls ? PWR(sb.st_nlink) : e->lls;
	e->lsz = PWR(sb.st_size) > e->lsz ? PWR(sb.st_size) : e->lsz;
	e->b = PWR(sb.st_blocks) > e->b ? PWR(sb.st_blocks) : e->b;
	e->lj = PWR(MAJOR(sb.st_rdev)) > e->lj ? PWR(MAJOR(sb.st_rdev)) : e->lj;
	e->lm = PWR(MINOR(sb.st_rdev)) > e->lm ? PWR(MINOR(sb.st_rdev)) : e->lm;
	return (1);
}

int						ls_getwidth(t_ls *root, t_exls *ext, int flags)
{
	int					kata;
	char				*place;
	char				*temp;

	if (ext->dest[ft_strlen(ext->dest) - 1] != '/')
	{
		temp = ft_strdup(ext->dest);
		free(ext->dest);
		ext->dest = ft_strjoin(temp, "/");
		free(temp);
	}
	while (root && root->nm && (temp = slovo(root->nm)))
	{
		place = (*root->nm == '/') ? ft_strdup(root->nm)
					: ft_strjoin(ext->dest, root->nm);
		kata = ls_helpget(place, &ext, root->nm, flags);
		root = root->next;
		free(place);
		free(temp);
		if (!kata)
			return (0);
	}
	ext->s = !ext->cw ? 0 : 1;
	return (1);
}
