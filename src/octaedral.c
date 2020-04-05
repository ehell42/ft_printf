#include "ft_printf.h"

void    work_with_int(t_print *print, va_list list)    //works + width
{
    int nbr;

    nbr = va_arg(list, int);
    if (nbr < 0)
        look_at_width(check_nbr_length(-nbr, 10), ft_atoi((char*)(print->width)), 1);
    else
        look_at_width(check_nbr_length(nbr, 10), ft_atoi((char*)(print->width)), 0);
    ft_putnbr(nbr);
}

void    work_with_char(t_print *print, va_list list)    //works + width
{
    char    a;

    look_at_width(1, ft_atoi((char*)(print->width)), 0);
    a = (char) va_arg(list, int);
    ft_putchar(a);
}

void    work_with_octaedral(t_print *print, va_list list)   //works but negative differs + width(but negative)
{
    unsigned int nbr;
    unsigned int nbr_tmp;
    int     len;

    nbr = va_arg(list, unsigned int);
    look_at_width(check_nbr_length(nbr, 8), ft_atoi((char*)(print->width)), 0);
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

void    work_with_hectaedral(t_print *print, va_list list)   //works + width
{
    unsigned int nbr;
    unsigned int nbr_tmp;
    char    *nbr_hex;
    int     len;

    nbr = va_arg(list, unsigned int);
    look_at_width(check_nbr_length(nbr, 16), ft_atoi((char*)(print->width)), 0);
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

void    work_with_string(t_print *print, va_list list)  //works + width
{
    char    *str;
    
    str = va_arg(list, char *);
    look_at_width(ft_strlen(str), ft_atoi((char*)(print->width)), 0);
    ft_putstr(str);
}