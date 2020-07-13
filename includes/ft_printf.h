/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 12:20:55 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/09 13:58:21 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef struct	s_flag
{
	int		plus;
	int		minus;
	int		ortokop;
	int		probel;
	int		zero;
	int		percent;
}				t_flag;

typedef struct	s_printf
{
	int			helper;
	int			minus;
	int			lenforpr;
	int			havewidth;
	int			sizecorrect;
	int			haveprecision;
	char		type;
	t_flag		*flag;
	int			width;
	int			precision;
	char		*razmer;
}				t_print;

int				ft_printf(const char *format, ...);
void			checkforflag(char **format, t_print *print);
t_print			*print_init(t_print *new_print);
int				exits(t_print **end_print);
int				checkforextra(char a, char **f, t_print **p, va_list list);
int				secondcheck(char a, char **f, t_print **print, va_list list);
int				checklast(char **f, char a, t_print **print);
void			work_with_int(t_print *print, va_list list, int *count);
void			work_with_unsigned_int(t_print *print, va_list list, int *c);
void			work_with_float(t_print *print, va_list list, int *count);
void			work_with_char(t_print *print, va_list list, int *count);
void			work_with_string(t_print *print, va_list list, int *count);
void			work_with_octaedral(t_print *print, va_list list, int *count);
void			work_with_hectaedral(t_print *print, va_list list, int *count);
unsigned int	check_nbr_length(long long int nbr, int base, t_print *p);
void			look_at_w(unsigned int nl, unsigned int w, t_print *p, void *d);
void			printing(unsigned int w, unsigned int ln, char sy, t_print *p);
void			outputdata(void *data, t_print *p);
void			outputdata2(void *data, t_print *p);
void			putlesswdth(char a, unsigned int *width);
void			checkprd(int *len, int precision, t_print *p, int nbr);
char			*edits(char *s, unsigned int pr, t_print *p, unsigned int *ln);
unsigned int	lenunsigned(unsigned long long int n);
int				cfo(unsigned long long int a, t_print *p, int base, int pres);
void			puthectadel(unsigned long long int nbr);
void			puthectadel2(unsigned long long int nbr);
void			work_with_percent(t_print *print, int *count);
void			buvford(t_print *print, va_list list, int *count);
void			ft_putnbrlld(long long int n);
long long int	dbuffer(t_print *p, va_list list);
unsigned int	check_nbr_lengthshort(short int nbr, short int b, t_print *p);
unsigned int	checklength(void *nbr, int base, t_print *p);
int				isit(void *nbr, t_print *p);
void			itis(void *nbr, t_print *p);
void			putcorrect(void *data, t_print *p);
long long int	gethecta(t_print *p, va_list list);
int				countcocta(void *a, t_print *p, int base, int pres);
void			putcorrecthecta(void *data, t_print *p);
void			putcorrecthecta2(void *data, t_print *p);
void			putlongint(unsigned long long int nbr);
void			putcorrectocta(void *data, t_print *p);
void			putcorrectunsigned(void *data, t_print *p);
void			modul(t_print *p, int *width);
void			freeinit(t_print **print);
void			work_with_pointer(t_print *print, va_list list, int *count);
void			ft_putfloat(long double nbr, t_print *print);
t_print 		*clear_init(t_print **new_print);
int 			l(t_print *p);

#endif
