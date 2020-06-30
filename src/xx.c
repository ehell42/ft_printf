/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:42:22 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/30 14:26:39 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    work_with_hectaedral(t_print *print, va_list list, int *count)   // not works + width
{
    void 			*nbr;
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
    len = countcocta(nbr, print, 16, pres);
    if (*(unsigned int*)nbr == 0 && pres == 0 && print->haveprecision == 1)
        len--;
    checkprd(&len, pres, print, *(unsigned int*)nbr);
    look_at_width(len, width, print, nbr);
    if (width > (unsigned int)len)
        *count = *count + width;
    else
        *count = *count + len;
    if (((print->flag->probel == 1 && print->minus == 0 && print->flag->plus == 0)) && print->haveprecision == 0)
        *count = *count + 1;
}

void *gethecta(t_print *p, va_list list)
{
	unsigned int *d;
	unsigned long int *ld;
	unsigned long long int *lld;
	unsigned short int *hd;
    unsigned char a;
	unsigned int *hhd;

	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
	{
		d = (unsigned int*)malloc(sizeof(unsigned int));
		*d = va_arg(list, unsigned int);
		return (d);
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
	{
		ld = (unsigned long int*)malloc(sizeof(unsigned long int));
		*ld = va_arg(list, unsigned long int);
		return (ld);
	}
    if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
	{
		lld = (unsigned long long int*)malloc(sizeof(unsigned long long int));
		*lld = va_arg(list, unsigned long long int);
		return (lld);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
	{
		hd = (unsigned short int*)malloc(sizeof(unsigned short int));
		*hd = va_arg(list, unsigned long long int);
		return (hd);
	}
    if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		hhd = (unsigned int*)malloc(sizeof(unsigned int));
		a = va_arg(list, unsigned int);
       *hhd = (unsigned int)a;
		return (hhd);
	}
	return (0);
}

int countcocta(void *a,  t_print *p, int base, int pres)
{

	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
		return (countforocta((*((unsigned int*)a)), p, base, pres));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		return (countforocta(*((unsigned short int*)a), p, base, pres));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		return (countforocta(*((unsigned int*)a), p, base, pres));
    else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		return (countforocta(*((unsigned long int*)a), p, base, pres));
    else if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
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