/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:34:57 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/03 15:53:28 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *editstring(char *str, unsigned int precision, t_print *p, unsigned int *len)
{
	char *newstr;

	if (str == NULL)
    {
        *len +=6;
        str = "(null)";
    }
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

void outputu(unsigned  long long int n)
{
	if (n >= 10)
	{
		ft_putnbr( n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

void putlongint(unsigned long long int nbr)
{
	int len;
	unsigned long long int nbr_tmp;

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
	ft_putnbrlld(nbr / 10);
}

void outputdata2(void *data, t_print *p)
{
	if ((p->type == 'u' || p->type == 'U') && p->helper != 1)
		putcorrectunsigned(data, p);
	if (p->type == 'o' && p->haveprecision == 0 && p->flag->ortokop == 1 && (*((unsigned long int*)data)) != 0)
		ft_putchar('0');
	if (p->type == 'o' && ((p->helper == 1 && p->flag->ortokop == 1) || p->helper != 1)) 
		putcorrectocta(data, p);
	if (p->type == 'x' && p->helper != 1)
	{
		if (((p->flag->zero == 0) || p->flag->minus == 1) && *((unsigned int*)data) != 0 && p->flag->ortokop == 1)
			ft_putstr("0x");
		putcorrecthecta(data, p);
	}
	if (p->type == 'X' && p->helper != 1)
	{
		if (((p->flag->zero == 0) || p->flag->minus == 1) && *((unsigned int*)data) != 0 && p->flag->ortokop == 1)
			ft_putstr("0X");
		putcorrectHecta(data, p);
	}
	if (p->flag->percent == 1)
		ft_putchar('%');
}

unsigned int lenunsigned(unsigned long long int n)
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

void putcorrectunsigned(void *data, t_print *p)
{
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ' && p->type != 'U')
		outputu(*((unsigned int*)data));
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		outputu(*((unsigned long int*)data));
	if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || p->type == 'U')
		outputu(*((unsigned long long int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		outputu(*((unsigned short int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		outputu(*((unsigned int*)data));
}