#include "ft_printf.h"

void    work_with_int(t_print *print, va_list list, int *count)    //works all without hh h l ll
{
    int             nbr;
    unsigned int    width;
    unsigned int    len;
    unsigned int    pres;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    nbr = va_arg(list, int);
    if (nbr < 0)
        print->minus = 1;
    len = check_nbr_length(nbr, 10, print);
    checkprd(&len, pres, print, nbr);
    look_at_width(len, width, print, &nbr);
    if (width > len)
        *count = *count + width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}

void    work_with_char(t_print *print, va_list list, int *count)    //work full
{
    char    a;
    unsigned int    width;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    a = (char) va_arg(list, int);
    if (width > 1)
        *count = *count + width;
    else
        *count = *count + 1;
   look_at_width(1, width, print, &a);
}

void    work_with_octaedral(t_print *print, va_list list, int *count)   //not all works
{
    long int    nbr;
    long int    nbr_tmp;
    unsigned int    len;
    unsigned int    width;
    unsigned int    pres;

    nbr_tmp = 0;
    len = 0;
    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    nbr = va_arg(list, unsigned long int);
    if ((int)nbr < 0)
        print->minus = 1;
    if (nbr == 0)
        len++;
    nbr_tmp = nbr;
    while (nbr_tmp > 0)
    {
        nbr_tmp /= 8;
        len++;
    }
    checkprd(&len, pres, print, nbr);
    look_at_width(len, width, print, &nbr);
    if (width > (unsigned int)len)
        *count = *count + width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}

void    work_with_hectaedral(t_print *print, va_list list)   //not works + width
{
    unsigned int nbr;
    unsigned int nbr_tmp;
    char    *nbr_hex;
    int     len;

    nbr = va_arg(list, unsigned int);
    print->width = 0;
    //look_at_width(check_nbr_length(nbr, 16), ft_atoi((char*)(print->width)), 0);
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

void    work_with_string(t_print *print, va_list list, int *count)  //work full
{
    unsigned int    width;
    unsigned int    len;
    unsigned int    pres;
    char            *str;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    str = va_arg(list, char *);
    len = ft_strlen(str);
    str = editstring(str, pres, print, &len);
    look_at_width(len, width, print , str);
    if (width > len)
        *count = *count + width;
    else
        *count = *count + len;
    if (str == NULL)
        *count +=6;
}