# ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H

# include "libft/libft.h"
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
# include <termios.h>   //for tcgetattr
# include <errno.h>     //do i need this?
# include <sys/ioctl.h>
# include <stdarg.h>
#include <grp.h>


#include "ft_printf.h"

typedef struct      s_ls
{
	int             tp;
	int             sz;
	int             cls;
	int             root;
	char            *grp;
	char            *nm;
	char            *ownr;
	size_t          tstmp;

	struct  s_ls    *next;
	//struct	s_ls	*prev;
}                   t_ls;

typedef struct      s_exls
{
	int             wword;
	int             wscol;
	int             cword;
	int 			flags;
	char 			*dest;

	struct  t_exls  *next;
}                   t_exls;



int                 ft_ls(char **av);
int                 countargs(DIR dir, struct dirent *entryr);
void    ls_prnt(t_ls *root, t_exls *ext);
int					ls_tkfls(t_exls *ext, char **av);
t_ls                *tlsnew(void);
int                 ls_tsd(DIR dir, struct dirent *entry, t_ls *tape);
t_exls              *textlsnew(void);
t_ls 				*ls_sl(t_ls *root);
int bhavachakra(char *av);
void ls_rec(const char *name);
void	ls_whip(const char *dest, DIR *dir, struct dirent *entry);
void	ls_lpr(t_ls *root, t_exls *ext, struct dirent *entry);
void	ls_rights(char *name);
void	ls_prrgh(int kat);
void	ls_pr_type(int type);


#endif
