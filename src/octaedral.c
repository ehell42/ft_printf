/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octaedral.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:58:43 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/18 18:58:45 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void    work_with_octaedral(t_print *print, va_list list, int *count)   //all works
{
    long int    nbr;
    unsigned int    len;
    unsigned int    width;
    unsigned int    pres;

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
    len = countforocta(nbr, print, 8, pres);
    checkprd(&len, pres, print, nbr);
    look_at_width(len, width, print, &nbr);
    if (width > (unsigned int)len)
        *count = *count + width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}

void    work_with_hectaedral(t_print *print, va_list list, int *count)   // not works + width
{
    unsigned int nbr;
    unsigned int    len;
    unsigned int    width;
    unsigned int    pres;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    nbr = va_arg(list, unsigned int);
    len = countforocta(nbr, print, 16, pres);
    if (nbr == 0 && pres == 0 && print->haveprecision == 1)
        len--;
    checkprd(&len, pres, print, nbr);
    look_at_width(len, width, print, &nbr);
    if (width > (unsigned int)len)
        *count = *count + width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
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