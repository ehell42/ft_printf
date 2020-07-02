/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:33:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/02 16:39:21 by alexzudin        ###   ########.fr       */
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

void outputdata(void *data, t_print *p)
{
	if (((p->flag->plus == 1 && p->flag->zero == 0 && p->minus == 0) || (p->flag->plus == 1 && p->flag->zero == 1 && p->minus == 0 && p->flag->minus == 1)) && p->type != 'u')
		ft_putchar('+');
	if (p->minus == 1 && isit(data, p) == 1 && p->haveprecision == 1)
	{
		ft_putchar('-');
		itis(data, p);
	}
	if (p->lenforpr != 0)
	{
		while (p->lenforpr > 0)
		{
			ft_putchar('0');
			(p->lenforpr)--;
		}
	}
	if ((p->type == 'd' || p->type == 'i') && p->helper != 1)
		putcorrect(data, p);
	if (p->type == 'c')
		ft_putchar(*((char*)data));
	if (p->type == 's' && p->helper != 1 && ((char*)data) != NULL)
		ft_putstr(((char*)data));
	outputdata2(data, p);
}

void putlesswdth(char a, unsigned int *width)
{
	ft_putchar(a);
	*width = (*width) - 1;
}

void	checkprd(unsigned int *len, unsigned int precision, t_print *p, int nbr)
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

void putcorrect(void *data, t_print *p)
{
	if ((p->razmer[0] == ' ' && p->razmer[1] == ' ') || (p->razmer[0] == 'l' && p->razmer[1] == 'h'))
		ft_putnbrlld(*((int*)data));
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		ft_putnbrlld(*((long int*)data));
	if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || ((p->razmer[0] == 'j' || p->razmer[0] == 'z') && p->razmer[1] == 'h'))
		ft_putnbrlld(*((long long int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		ft_putnbrlld(*((short int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		ft_putnbrlld(*((int*)data));
}