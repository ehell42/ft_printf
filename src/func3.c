/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:34:57 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/09 14:02:37 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *edits(char *str, unsigned int precision, t_print *p, unsigned int *len)
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
	char *nbr_hex;
	int len;
	unsigned long long int nbr_tmp;
	
	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		ft_putchar('0');
    while (nbr_tmp)
    {
        nbr_tmp /= 8;
        len++;
    }
	nbr_hex = (char*)(malloc(sizeof(char) * (len + 1)));
	nbr_hex[len] = '\0';
	len--;
	while (len >= 0)
    {
        nbr_hex[len] = '0' + nbr % 8;
        nbr /= 8;
        len--;
    }
    ft_putstr(nbr_hex);
    free(nbr_hex);
}

void outputdata2(void *data, t_print *p)
{
	if ((p->type == 'u' || p->type == 'U') && p->helper != 1)
		putcorrectunsigned(data, p);
	if (p->type == 'o' && (p->haveprecision == 0 || p->precision == 0) && p->flag->ortokop == 1 && (*((unsigned long int*)data)) != 0)
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
		putcorrecthecta2(data, p);
	}
	if (p->flag->percent == 1)
		ft_putchar('%');
	if (p->type == 'p' && p->helper != 1)
			putcorrecthecta(data, p);
	if (p->type == 'f')
			ft_putfloat(*((double*)data), p);;
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