/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:24:04 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/09 14:01:31 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *puthectadel(unsigned long long int nbr)
{
	char *nbr_hex;
	int len;
	unsigned long long int nbr_tmp;
	
	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		return(szero());
    while (nbr_tmp)
    {
        nbr_tmp /= 16;
        len++;
    }
	nbr_hex = ft_strnew(len + 1);
	len--;
	while (len >= 0)
    {
        if (nbr % 16 < 10)
            nbr_hex[len] = '0' + nbr % 16;
        else
            nbr_hex[len] = 'a' + nbr % 16 - 10;
        nbr /= 16;
        len--;
    }
    return (nbr_hex);
}

char *puthectadel2(unsigned long long int nbr)
{
	char *nbr_hex;
	int len;
	unsigned long long int nbr_tmp;
	
	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		return(szero());
    while (nbr_tmp)
    {
        nbr_tmp /= 16;
        len++;
    }
	nbr_hex = (char*)(malloc(sizeof(char) * (len + 1)));
	nbr_hex[len] = '\0';
	len--;
	while (len >= 0)
    {
        if (nbr % 16 < 10)
            nbr_hex[len] = '0' + nbr % 16;
        else
            nbr_hex[len] = 'A' + nbr % 16 - 10;
        nbr /= 16;
        len--;
    }
    return (nbr_hex);
}

 void    work_with_percent(t_print *print, int *count)    //work full
{
    if (print->width > 1)
        *count = *count + print->width;
    else
        *count = *count + 1;
   look_at_w(1, print->width, print, "%");
}

void    work_with_pointer(t_print *print, va_list list, int *count)
{
	long long int 	nbr;
    int    len;
    char *a;

    nbr = (unsigned long long int)va_arg(list, void*);
    print->razmer[0] = 'l';
    print->razmer[1] = 'l';
    len = countcocta(&nbr, print, 16, print->precision);
    checkprd(&len, print->precision, print, nbr);
    len +=2;
    a = puthectadel(nbr);
    look_at_w(len, print->width, print, a);
    free(a);
    if (print->width > len)
        *count = *count + print->width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}