#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef struct				s_printf
{
	char                type;
    char                flag;
    struct s_printf     *next;
}							t_print;

#endif