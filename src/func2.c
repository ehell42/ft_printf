/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 15:33:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/04/01 16:11:36 by alexzudin        ###   ########.fr       */
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