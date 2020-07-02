/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octaedral.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:58:43 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/02 10:30:00 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
    long long int   nbr;
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
    nbr = gethecta(print, list);
    if (nbr < 0)
        print->minus = 1;
    len = countcocta(&nbr, print, 8, pres);
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
    int    width;
    unsigned int    len;
    int    pres;
    char            *str;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (*((char*)(print->precision)) == '*')
        pres = va_arg(list, int);
    else
        pres = ft_atoi((char*)(print->precision));
    modul(print, &width);
    str = va_arg(list, char *);
    len = ft_strlen(str);
    str = editstring(str, pres, print, &len);
    look_at_width(len, width, print , str);
    if ((unsigned int)width > len)
        *count = *count + width;
    else
        *count = *count + len;
}

void modul(t_print *p, int *width)
{
    if (*width < 0)
    {
        *width = *width * -1;
        p->flag->minus = 1;
    }
}