/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xx.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 20:42:22 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/10 15:38:30 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			work_with_hectaedral(t_print *p, va_list list, int *count)
{
	long long int	nbr;
	int				len;
	char			*a;

	nbr = gethecta(p, list);
	len = countcocta(&nbr, p, 16, p->precision);
	if (nbr == 0 && p->precision == 0 && p->haveprecision == 1)
		len--;
	checkprd(&len, p->precision, p, nbr);
	if (p->flag->ortokop == 1 && (p->type == 'x' || p->type == 'X') && nbr != 0)
		len = len + 2;
	if (p->type == 'x')
		a = puthectadel(nbr);
	else
		a = puthectadel2(nbr);
	look_at_w(len, p->width, p, a);
	free(a);
	if (p->width > len)
		*count = *count + p->width;
	else
		*count = *count + len;
	if (((p->flag->probel == 1 && p->minus == 0 && p->flag->plus == 0))
	&& p->haveprecision == 0)
		*count = *count + 1;
}

long long int	gethecta(t_print *p, va_list l)
{
	unsigned long long int	d;
	unsigned char			a;

	if (p->razmer[0] == ' ' && p->razmer[1] == ' ' && p->type != 'U')
		return ((d = (unsigned int)va_arg(l, unsigned int)));
	else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		return ((d = (unsigned long int)va_arg(l, unsigned long int)));
	else if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || p->type == 'U')
		return ((d = va_arg(l, unsigned long long int)));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ')
		return ((d = (unsigned short int)va_arg(l, unsigned int)));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
	{
		a = va_arg(l, unsigned int);
		d = (unsigned int)a;
		return ((unsigned int)d);
	}
	return (0);
}

int				countcocta(void *a, t_print *p, int base, int pres)
{
	if (p->razmer[0] == ' ' && p->razmer[1] == ' ' && p->type != 'U')
		return (cfo((*((unsigned int*)a)), p, base, pres));
	else if (p->razmer[0] == 'h' && p->razmer[1] == ' ' && p->type != 'U')
		return (cfo(*((unsigned short int*)a), p, base, pres));
	else if (p->razmer[0] == 'h' && p->razmer[1] == 'h')
		return (cfo(*((unsigned int*)a), p, base, pres));
	else if (p->razmer[0] == 'l' && p->razmer[1] == ' ')
		return (cfo(*((unsigned long int*)a), p, base, pres));
	else if ((p->razmer[0] == 'l' && p->razmer[1] == 'l') || p->type == 'U')
		return (cfo(*((unsigned long long int*)a), p, base, pres));
	return (0);
}

int				cfo(unsigned long long int a, t_print *p, int b, int pres)
{
	int count;

	count = 0;
	if (a == 0)
		p->zero = 1;
	if (a == 0 && pres == 0 && p->haveprecision == 1 && (p->type == 'x' || p->type == 'X'))
		p->helper = 1;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /= b;
		count++;
	}
	return (count);
}
