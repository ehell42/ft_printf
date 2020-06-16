#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef struct				s_flag
{
	int                plus;
    int                minus;
    int                ortokop;
    int                probel;
    int                zero;
    int                 percent;
}							t_flag;

typedef struct				s_printf
{
    int                     helper;
    int                     minus;
    int                     lenforpr;
    int                     havewidth;
    int                     haveprecision;
	char                    type;
    t_flag                  *flag;
    void                    *width;
    void                    *precision;
    char                    razmer[2];
}							t_print;

int             ft_printf(const char *format, ...);
void            checkforflag(char **format, t_print *print);
t_print         *print_init(t_print *new_print);
int             exits(t_print *end_print);
int             checkforextra(char a, char **format, t_print *print);
int             secondcheck(char a, char **format, t_print *print);
int             checklast(char **f, char a, t_print *print);
void            work_with_int(t_print *print, va_list list, int *count);
void            work_with_unsigned_int(t_print *print, va_list list, int *count);
//void        work_with_float(t_print *print, va_list list);
void            work_with_char(t_print *print, va_list list, int *count);
void            work_with_string(t_print *print, va_list list, int *count);
void            work_with_octaedral(t_print *print, va_list list, int *count);
void            work_with_hectaedral(t_print *print, va_list list);
void            work_with_Hectaedral(t_print *print, va_list list);
unsigned int        check_nbr_length(long long int nbr, int base, t_print *p);
void            look_at_width(unsigned int numberlnght, unsigned int width,t_print *print,void *data);
//void        work_with_pointer(t_print *print, va_list list);
void            printing(unsigned int width, unsigned int len,char symbol);
void            outputdata(void *data, t_print *p);
void            outputdata2(void *data, t_print *p);
void            putlesswdth(char a, unsigned int *width);
void	        checkprd(unsigned int *len, unsigned int precision, t_print *p, int nbr);
char            *editstring(char *str, unsigned int precision, t_print *p, unsigned int *len);
unsigned int    lenunsigned(unsigned int n);
int             countforocta(unsigned long int a,  t_print *p);

#endif