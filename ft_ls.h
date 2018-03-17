/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:16:48 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/10 17:16:49 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# include <grp.h>
# include <pwd.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <dirent.h>
# include <sys/acl.h>
# include <termios.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <uuid/uuid.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/ioctl.h>
# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"

# define FLAG_LR	flags / 100 % 2
# define FLAG_R		flags / 1000 % 2
# define FLAG_T		flags / 10000 % 2
# define FLAG_1		flags / 1000000 % 2
# define MAJOR(x)	((long)major(x))
# define MINOR(x)	((long)minor(x))
# define PWR(x)		(ft_pwrbase(x, 10))

typedef	struct		s_ls
{
	char			*nm;
	int				tp;
	struct s_ls		*next;

}					t_ls;

typedef	struct		s_exls
{
	int				flags;
	char			*dest;
	int				dev;
	int				lj;
	int				lm;
	int				s;
	size_t			ww;
	size_t			wc;
	int				cw;
	int				tt;
	int				b;
	int				lsz;
	int				lls;
	size_t			lo;
	size_t			lg;
}					t_exls;

t_ls				*tlsnew(void);
int					ph(char *name);
char				*slovo(char *s);
void				ls_acl(char *place);
t_ls				*ls_argfl(t_ls *nroot);
void				reversesort(t_ls **list);
void				ft_sl_av(char **av, int ac);
int					ls_ls(char *dest, int flags);
char				*ls_takeway(char *av, int cod);
void				ls_free(t_ls *tape, t_exls *ext);
int					ft_lsot(t_ls **nroot, int flags);
void				ls_prnt(t_ls *root, t_exls *ext, int flags);
int					errs(char lt, char *w, int c);
int					ls_getwidth(t_ls *root, t_exls *ext, int flags);
void				ls_lpr(t_ls *rot, t_exls *e, int code, int flags);
void				sort(t_ls **list, char *way, int code);
int					checktype(char *av, char *dest, int flags);
int					ct(char *rootnm, char *nrootnm, char *dest);
int					newls_whip(char *way, t_ls *tape, int flags);
t_exls				*textlsnew(char *s, int f, unsigned int wcol);
int					ls_tkflsc(int flags, char **av, int w, int l);
int					ls_rights(char *name, int wblocks);
int					get_files(char *way, int flags, t_ls **otape);
int					get_time(char *place, t_exls *ext, char *name);
void				ls_listrec(const char *w, int f, t_ls *t, int c);
t_ls				*ls_tsd(DIR *dir, struct dirent *e, int f, char *w);
void				ls_pr_type(struct stat sb, int *wblocks);
t_ls				*sort_ls(t_ls *list, int flags, char *way, int code);

#endif
