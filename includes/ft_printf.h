#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef struct				s_printf
{
	char                type;
    char                flag;
    char                width;
    char                precision;
}							t_print;

int         ft_printf(const char *format, ...);
t_print    *print_init(t_print *new_print);
int         exits(char *strerr, t_print *end_print);
int         checkforextra(char a, char **format, t_print *print);
int         secondcheck(char a, char **format, t_print *print);
int         checklast(char **f, char a, t_print *print);
#endif