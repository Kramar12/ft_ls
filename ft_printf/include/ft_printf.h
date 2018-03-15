/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 20:53:43 by ariabyi           #+#    #+#             */
/*   Updated: 2018/03/08 17:23:11 by ariabyi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

typedef	struct	s_plist
{
	size_t		f;
	char		*s;
	int			w;
	int			p;
	int			pp;
	size_t		st;
	ssize_t		sst;
	int			fwp;
	int			pct;
	int			d;
	int			sign;
	int			ishsh;
	int			pnt;
	int			r;
}				t_plist;

int				ft_printf(char *field, ...);
t_plist			*pr_listnew(int i);
int				ft_percent(va_list ap, t_plist *types, const char **f);
int				ft_tob(t_plist *types);
void			ft_dflags(va_list ap, t_plist *types, const char **f);
void			ft_sflags(va_list ap, t_plist *types, const char **f);
int				ft_checkflags(t_plist *types, size_t num, const char **f);
int				ft_iselet(char f, int code, size_t start, size_t end);
int				ft_printsf(t_plist *types, char f, ssize_t num, int code);
short int		ft_power(ssize_t num, int base);
void			ft_takefwp(t_plist *types, const char **f);
void			ft_setproc(t_plist *types, ssize_t ss, int base, char x);
int				ft_setwidth(t_plist *types, ssize_t ss, int base, int lacuna);
int				ft_setall(t_plist *types, ssize_t ss, int base, char x);
int				ft_putnbrpr(t_plist *types, ssize_t num);
void			ft_printnumb(t_plist *types, size_t num, char x, int base);
void			ft_printssnum(t_plist *types, ssize_t ssnum, char x, int base);
int				ft_simplpchr(char b);
int				ft_qputchar(ssize_t c);
size_t			ft_ascount(const char *s, int prec);
int				ft_check(int c);
void			ft_major(va_list ap, t_plist *t, const char **f);
size_t			ft_putstr_u(const char *s, ssize_t end);
int				ft_turnf(t_plist *types, ssize_t *ss);
int				ft_turns(t_plist *types, size_t *s, char x);
int				ft_iffsd(t_plist *types, int code);
void			ft_s(t_plist *types, const char **f);
size_t			qft_putnbrpr(int prec, size_t ret, ssize_t n);

#endif
