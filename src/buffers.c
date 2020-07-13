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

void	putcorrecthecta(void *data, t_print *p)
{
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
		puthectadel(*((unsigned int*)data));
	if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		puthectadel(*((unsigned long int*)data));
	if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
		puthectadel(*((unsigned long long int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		puthectadel(*((unsigned short int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		puthectadel(*((unsigned int*)data));
}

void	putcorrecthecta2(void *data, t_print *p)
{
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
		puthectadel2(*((unsigned int*)data));
	else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		puthectadel2(*((unsigned long int*)data));
	else if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
		puthectadel2(*((unsigned long long int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		puthectadel2(*((unsigned short int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		puthectadel2(*((unsigned int*)data));
}

void	putcorrectocta(void *data, t_print *p)
{
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
		putlongint(*((unsigned int*)data));
	else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		putlongint(*((unsigned long int*)data));
	else if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
		putlongint(*((unsigned long long int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		putlongint(*((unsigned short int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		putlongint(*((unsigned int*)data));
}
