/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:34:57 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/15 17:34:35 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *editstring(char *str, unsigned int precision, t_print *p, unsigned int *len)
{
	char *newstr;

	if (precision < *len && p->haveprecision == 1)
	{
		if (precision == 0)
		{
			p->helper = 1;
			*len = 0;
			return (str);
		}
		*len = precision;
		newstr = ft_strnew(precision);
		ft_strncpy(newstr, str, precision);
		return (newstr);
	}
	else
		return (str);
	
}

void outputu(unsigned  int n)
{
	if (n >= 10)
	{
		ft_putnbr( n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void putlongint(void *data)
{
	int len;
	unsigned long int nbr;
	unsigned long int nbr_tmp;

	nbr = *((unsigned long int*)data);
	nbr_tmp = 0;
	len = 0;
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

void outputdata2(void *data, t_print *p)
{
	if (p->type == 'u' && p->helper != 1)
		outputu((*(unsigned int*)data));
	if (p->type == 'o' && p->haveprecision == 0 && p->flag->ortokop == 1)
		ft_putchar('0');
	if (p->type == 'o' && p->helper != 1)
	{
		putlongint(data);
	}
	if (p->type == 'o' && p->helper == 1 && p->flag->ortokop == 1) 
	{
		putlongint(data);
	}
}

unsigned int lenunsigned(unsigned int n)
{
	unsigned int len;

	len = 0;
	while (n >= 10)
    {
        n = n / 10;
        len++;
    }
    if (n >=0 )
        len++;
	return (len);
}