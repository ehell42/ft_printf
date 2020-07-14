/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:34:51 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/09 19:18:44 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrlld(long long int n)
{
	char					a;
	unsigned long long int	i;

	i = 0;
	if (n >= 0)
		i = n;
	if (n < 0)
	{
		i = n * -1;
		ft_putchar('-');
	}
	if (i > 9)
	{
		ft_putnbrlld(i / 10);
		ft_putnbrlld(i % 10);
	}
	else
	{
		a = i + '0';
		ft_putchar(a);
	}
}

void	itis(void *nbr, t_print *p)
{
	if (p->r[0] == ' ' && p->r[1] == ' ')
		(*((long long int*)nbr)) = (*((int*)nbr)) * -1;
	else if (p->r[0] == 'l' && p->r[1] == ' ')
		(*((long long int*)nbr)) = (*((long int*)nbr)) * -1;
	else if (p->r[0] == 'h' && p->r[1] == ' ')
	{
		(*((long long int*)nbr)) = *((short int*)nbr) * -1;
	}
	else if (p->r[0] == 'h' && p->r[1] == 'h')
		(*((long long int*)nbr)) = (*((int*)nbr)) * -1;
}
