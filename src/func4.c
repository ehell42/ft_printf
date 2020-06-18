/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:24:04 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/18 19:06:17 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int countforocta(unsigned long int a,  t_print *p, int base, int pres)
{
	int count;

	count = 0;
	if (a == 0 && pres == 0 && p->haveprecision == 1 && (p->type == 'x' || p->type == 'X'))
		p->helper = 1;
	if (p->haveprecision == 0 && p->flag->ortokop == 1 && p->type == 'o')
		count++;
	if (p->flag->ortokop == 1 && (p->type == 'x' || p->type == 'X'))
		count = count + 2;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /=base;
		count++;
	}
	return (count);
}

void puthectadel(unsigned int nbr)
{
	char *nbr_hex;
	int len;
	unsigned int nbr_tmp;
	
	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		ft_putchar('0');
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

void putHectadel(unsigned int nbr)
{
	char *nbr_hex;
	int len;
	unsigned int nbr_tmp;
	
	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		ft_putchar('0');
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
            nbr_hex[len] = 'A' + nbr % 16 - 10;
        nbr /= 16;
        len--;
    }
    ft_putstr(&nbr_hex[1]);
    free(nbr_hex);
}

 void    work_with_percent(t_print *print, va_list list, int *count)    //work full
{
    unsigned int    width;

    if (*((char*)(print->width)) == '*')
        width = va_arg(list, int);
    else
        width = ft_atoi((char*)(print->width));
    if (width > 1)
        *count = *count + width;
    else
        *count = *count + 1;
   look_at_width(1, width, print, NULL);
}