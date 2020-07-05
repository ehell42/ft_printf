/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 12:34:51 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/03 15:56:11 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbrlld(long long int n)
{
	unsigned long long int i;
  
	i = 0;
	if (n >= 0)
    	i = n;
	if (n < 0)
  	{
    	i = n * -1;
		ft_putchar('-');
 	}
	if (i >= 10)
    ft_putnbrlld(i / 10);
	ft_putchar((i % 10) + '0');
}

void putcorrecthecta(void *data, t_print *p)
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

void putcorrectHecta(void *data, t_print *p)
{
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
		putHectadel(*((unsigned int*)data));
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		putHectadel(*((unsigned long int*)data));
	if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
		putHectadel(*((unsigned long long int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		putHectadel(*((unsigned short int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		putHectadel(*((unsigned int*)data));
}

void putcorrectocta(void *data, t_print *p)
{
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ')
		putlongint(*((unsigned int*)data));
    if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		putlongint(*((unsigned long int*)data));
	if (p->razmer[0] == 'l' && p->razmer[1] == 'l')
		putlongint(*((unsigned long long int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		putlongint(*((unsigned short int*)data));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		putlongint(*((unsigned int*)data));
}