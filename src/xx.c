/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:42:22 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/02 17:11:16 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    work_with_hectaedral(t_print *print, va_list list, int *count)   // not works + width
{
	long long int 	nbr;
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
    len = countcocta(&nbr, print, 16, pres);
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

long long int gethecta(t_print *p, va_list list)
{
	unsigned long long int lld;
    unsigned char a;

	if (p->razmer[0] == ' ' && p->razmer[1] == ' ' && p->type != 'U')
	{
		lld = (unsigned int)va_arg(list, unsigned int);
		return ((unsigned int)lld);
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		lld = (unsigned long int)va_arg(list, unsigned long int);
		return ((unsigned long int)lld);
	}
    if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || p->type == 'U')
	{
		lld = (unsigned long long int)va_arg(list, unsigned long long int);
		return ((unsigned long long int)lld);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		lld = (unsigned short int)va_arg(list, unsigned int);
		return ((unsigned short int)lld);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		a = va_arg(list, unsigned int);
       lld = (unsigned int)a;
		return ((unsigned int)lld);
	}
	return (0);
}

int countcocta(void *a,  t_print *p, int base, int pres)
{

	if (p->razmer[0] == ' ' && p->razmer[1] == ' ' && p->type != 'U')
		return (countforocta((*((unsigned int*)a)), p, base, pres));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ' && p->type != 'U')
		return (countforocta(*((unsigned short int*)a), p, base, pres));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		return (countforocta(*((unsigned int*)a), p, base, pres));
    else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		return (countforocta(*((unsigned long int*)a), p, base, pres));
    else if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || p->type == 'U')
		return (countforocta(*((unsigned long long int*)a), p, base, pres));
	return (0);
}
int countforocta(unsigned long long int a,  t_print *p, int base, int pres)
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