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
# include <grp.h>
# include <sys/acl.h>
# include <sys/types.h>
# include <stdarg.h>


# define FLAG_LR	flags / 100 % 2
# define FLAG_R		flags / 1000 % 2
# define FLAG_T		flags / 10000 % 2
# define FLAG_1		flags / 1000000 % 2
# define MAJOR(x)	((long)major(x))
# define MINOR(x)	((long)minor(x))
# define FLAG_A != '.' || ((ext->flags / 10) % 2)

typedef	struct		s_ls
{
	char			*nm;
	int 			type;
	struct s_ls		*next;

}					t_ls;

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
char				*slovo(char *s);
t_exls				*textlsnew(char *s, int f, unsigned int wcol);
void				ls_lpr(t_ls *rot, t_exls *e, int code);
char				*ls_takeway(char *av, int cod);
int					ls_tkflsc(int flags, char **av, int w, int l);
int            		ft_ls(char *dest, int flags);
void				ls_free(t_ls *tape, t_exls *ext);
int					ft_lsot(t_ls **nroot, int flags);
int					ls_errors(char lt, char *w, int c);
int					ls_getwidth(t_ls *root, t_exls *ext);
t_ls				*ls_tsd(DIR *dir, struct dirent *entry, int flags, char *way);
void				ls_prnt(t_ls *root, t_exls *ext);
void				ls_rights(char *name, int flags, int wblocks);
void				get_time(char *place, t_exls *ext, char *name);
void				ls_pr_type(struct stat sb, int flags, int *wblocks);
void				ls_acl(char *place);
int				checktype(char *av, char *dest, int flags);
int             	ls_ls(char *dest, int flags);
void				newls_whip(char *way, t_ls *tape, int flags);
void				ls_listrec(const char *way, int flags, t_ls *tape, int code);

int					get_files(char *way, int flags, t_ls **otape);
int             	ls_ls(char *dest, int flags);
void				newls_whip(char *way, t_ls *tape, int flags);
void				ft_sl_av(char **av, int ac);
int					ct(char *rootnm, char *nrootnm, char *dest);
t_ls				*sort_ls(t_ls *list, int flags, char *way, int code);
int					get_files(char *way, int flags, t_ls **otape);
t_ls				*sort_ls(t_ls *list, int flags, char *way, int code);
t_ls				*ls_argfl(t_ls *nroot);
void				reversesort(t_ls **list);
void				sort(t_ls **list, char *way, int code);
t_ls				*ls_argfl(t_ls *nroot);

#endif
