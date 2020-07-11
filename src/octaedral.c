/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octaedral.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:58:43 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/09 17:03:33 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    work_with_char(t_print *print, va_list list, int *count)    //work full
{
    char    a;
    char    *str;

    a = (char) va_arg(list, int);
    if (print->width < 0)
	{
		print->width *= -1;
		print->flag->minus = 1;
	}
    if (print->width > 1)
        *count = *count + print->width;
    else
        *count = *count + 1;
    str = ft_strnew(1);
    str[0] = a;
   look_at_w(1, print->width, print, str);
   free(str);
}

void    work_with_octaedral(t_print *print, va_list list, int *count)   //all works
{
    unsigned long long int   nbr;
    int    len;
    char    *a;

    len = 0;
    nbr = gethecta(print, list);
    len = countcocta(&nbr, print, 8, print->precision);
    checkprd(&len, print->precision, print, nbr);
    if (print->precision == 0 && print->flag->ortokop == 1 && nbr != 0)
        len++;
    a = putlongint(nbr);
    look_at_w(len, print->width, print, a);
    free(a);
    if (print->width > len)
        *count = *count + print->width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}

void    work_with_string(t_print *print, va_list list, int *count)  //work full
{
    unsigned int    len;
    char            *str;

    modul(print, &(print->width));
    str = va_arg(list, char *);
    len = ft_strlen(str);
    str = edits(str, print->precision, print, &len);
    look_at_w(len, print->width, print , str);
    if ((unsigned int)print->width > len)
        *count = *count + print->width;
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