#include "ft_printf.h"

void    work_with_int(t_print *print, va_list list)    //works
{
    int nbr;
    t_flag    *a;

    a = print->flag;
    nbr = va_arg(list, int);
    ft_putnbr(nbr);
}

void    work_with_char(t_print *print, va_list list)    //works
{
    char    a;
    t_flag    *s;

    s = print->flag;
    a = (char) va_arg(list, int);
    ft_putchar(a);
}

void    work_with_octaedral(t_print *print, va_list list)   //works but negative differs
{
    unsigned int nbr;
    unsigned int nbr_tmp;
    t_flag    *a;
    int     len;

    a = print->flag;
    nbr = va_arg(list, unsigned int);
    nbr_tmp = 0;
    len = 0;
    if (nbr == 0)
        ft_putnbr(0);
    else
    {
        while (nbr)
        {
            nbr_tmp += nbr % 8;
            nbr_tmp *= 10;
            nbr /= 8;
            len++;
        }
        while (len >= 0)
        {
            nbr += nbr_tmp % 10;
            nbr *= 10;
            nbr_tmp /= 10;
            len--;
        }
        ft_putnbr(nbr / 10);
    }
}

void    work_with_hectaedral(t_print *print, va_list list)   //works
{
    unsigned int nbr;
    unsigned int nbr_tmp;
    char    *nbr_hex;
    t_flag    *a;
    int     len;

    a = print->flag;
    nbr = va_arg(list, unsigned int);
    if (nbr == 0)
        ft_putnbr(0);
    else
    {
        nbr_tmp = nbr;
        len = 0;
        while (nbr_tmp)
        {
            nbr_tmp /= 16;
            len++;
        }
        nbr_hex = (char*) ft_memalloc(sizeof(char) * len);
        while (len >= 0)
        {
            if (nbr % 16 < 10)
                nbr_hex[len] = '0' + nbr % 16;
            else
                nbr_hex[len] = 'a' + nbr % 16 - 10;
            nbr /= 16;
            len--;
        }
        ft_putstr(&nbr_hex[1]);
        free(nbr_hex);
    }
}

void    work_with_string(t_print *print, va_list list)
{
    char    *str;
    t_flag    *a;

    a = print->flag;
    str = va_arg(list, char *);
    ft_putstr(str);
}