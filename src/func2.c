/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:33:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/10 16:42:23 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void checkforflag(char **format, t_print *print)
{
	if (**format == '+')
		print->flag->plus = 1;
	if (**format == '-')
		print->flag->minus = 1;
	if (**format == '#')
		print->flag->ortokop = 1;
	if (**format == ' ')
		print->flag->probel = 1;
	if (**format == '0')
		print->flag->zero = 1;
}

void outputdata(char *data, t_print *p)
{
	if (((p->flag->plus == 1 && p->flag->zero == 0 && p->minus == 0) || (p->flag->plus == 1 && p->flag->zero == 1 && p->minus == 0 && p->flag->minus == 1)) && p->type != 'u')
		ft_putchar('+');
	if (p->type == 'p'  || (p->type == 'x' && p->flag->ortokop == 1 && p->zero != 1  && (p->flag->zero == 0 || (p->flag->zero == 1 && p->flag->minus == 1))))
		ft_putstr("0x");
	if (p->type == 'X' && p->flag->ortokop == 1 && p->zero != 1 && (p->flag->zero == 0 || (p->flag->zero == 1 && p->flag->minus == 1)))
		ft_putstr("0X");
	if (p->minus == 1 && ((p->minus == 1 && p->haveprecision == 1) || (p->type == 'f' && p->flag->zero == 0)))
		ft_putchar('-');
	if (p->lenforpr != 0)
	{
		while (p->lenforpr > 0)
		{
			ft_putchar('0');
			(p->lenforpr)--;
		}
	}
	if (p->type == 'o' && (p->haveprecision == 0 || p->precision == 0) && p->flag->ortokop == 1 && (*((unsigned long int*)data)) != 0)
		ft_putchar('0');
	if (p->helper != 1)
		ft_putstr(data);
}

void putlesswdth(char a, unsigned int *width)
{
	ft_putchar(a);
	*width = (*width) - 1;
}

void	checkprd(int *len, int precision, t_print *p, int nbr)
{
	int count;

	if (p->haveprecision == 1)
	{
		if (precision >= *len)
		{
			if (p->minus == 1)
				count = *len -1;
			else
				count = *len;
			if (p->flag->plus == 1 && p->minus == 0)
				count--;
			p->lenforpr = precision - count;
			*len = *len + p->lenforpr;
		}
		else
		{
			if (precision == 0 && nbr == 0)
			{
				p->helper = 1;
				if (p->flag->ortokop != 1)
					(*len)--;
			}
		}
	}
}