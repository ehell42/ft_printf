/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:33:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/05/31 10:55:47 by alexzudin        ###   ########.fr       */
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
	if (p->flag->plus == 1 && p->flag->zero == 0 && *((int*)data) >= 0)
		ft_putchar('+');
	if (p->type == 'd')
		ft_putnbr(*((int*)data));
	if (p->type == 'c')
		ft_putchar(*((char*)data));
}

void putlesswdth(char a, unsigned int *width)
{
	ft_putchar(a);
	*width = (*width) - 1;
}