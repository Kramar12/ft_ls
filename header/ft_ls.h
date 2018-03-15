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

# include "libft/libft.h"
# include "ft_printf/include/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <time.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <termios.h>
# include <errno.h>
# include <sys/ioctl.h>
# include <stdarg.h>
# include <grp.h>
# include <sys/acl.h>
# include <sys/types.h>

# define FLAG_LR flags / 100 % 2
# define FLAG_R flags / 1000 % 2
# define FLAG_T flags / 10000 % 2
# define FLAG_S flags / 100000 % 2
# define FLAG_1 flags / 1000000 % 2
# define MAJOR(x)    ((long)major(x))
# define MINOR(x)    ((long)minor(x))
# define FLAG_A != '.' || ((ext->flags / 10) % 2)

typedef	struct		s_ls
{
	char			*nm;
	struct s_ls		*next;
}					t_ls;

typedef	struct		s_lsav
{
	char			*nm;
	int				type;
	struct s_lsav	*next;
}					t_lsav;

typedef	struct		s_exls
{
	int				dev;
	int				lmaj;
	int				lmin;
	int				elms;
	int				solo;
	int				wword;
	int				wscol;
	int				cword;
	int				flags;
	int				total;
	int				block;
	char			*dest;
	int				lensize;
	int				lenlinks;
	int				lenowner;
	int				lengroup;
}					t_exls;

t_ls				*tlsnew(void);
t_lsav				*tlsavnew(void);
char				*slovo(char *s);
t_exls				*textlsnew(char *s, int f, unsigned int wcol);
t_ls				*ls_sl(t_ls *root);
t_ls				*ls_sl_r(t_ls **root);
t_lsav				*ls_slav(t_lsav *root);
void				ls_avfree(t_lsav **head);
t_lsav				*ls_slav_r(t_lsav **root);
void				ls_lpr(t_ls *rot, t_exls *e);
char				*ls_takeway(char *av, int cod);
int					ls_tkflsc(int flags, char **av, int w, int l);
int					ft_ls(t_lsav **root, int flags);
void				ls_free(t_ls *tape, t_exls *ext);
t_ls				*ls_sl_t(t_ls *root, t_exls *ext);
int					ft_lsot(t_lsav **nroot, int flags);
int					ls_errors(char lt, char *w, int c);
int					ls_rec(const char *name, int flags);
void				ls_getwidth(t_ls *root, t_exls *ext);
t_ls				*ls_tsd(DIR dir, struct dirent *entry);
int					ls_argfile(t_ls **ntape, t_lsav **nroot);
void				ls_prnt(t_ls *root, t_exls *ext, int code);
void				ls_rights(char *name, int flags, int wblocks);
void				get_time(char *place, t_exls *ext, char *name);
void				ls_pr_type(struct stat sb, int flags, int wblocks);
int					ls_whip(const char *d, DIR *dir, struct dirent *e, int f);

t_lsav				*ls_slav_t(t_lsav *root);

#endif
