/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octaedral.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 18:58:43 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/09 17:03:33 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	work_with_char(t_print *print, va_list list, int *count)
{
	char	a;

	a = (char)va_arg(list, int);
	if (print->width < 0)
	{
		print->width *= -1;
		print->f->m = 1;
	}
	if (print->width > 1)
		*count = *count + print->width;
	else
		*count = *count + 1;
	look_at_w(1, print, &a);
}

void	work_with_octaedral(t_print *print, va_list list, int *count)
{
	unsigned long long int	nbr;
	int						len;

	len = 0;
	nbr = gethecta(print, list);
	len = countcocta(&nbr, print, 8, print->precision);
	checkprd(&len, print->precision, print, nbr);
	if (print->precision == 0 && print->f->o == 1 && nbr != 0)
		len++;
	if (print->width > len)
		*count = *count + print->width;
	else
		*count = *count + len;
	look_at_w(len, print, &nbr);
	if (((print->f->pr == 1 && print->m == 0
	&& print->f->p == 0)) && print->hp == 0)
		*count = *count + 1;
}

void	work_with_string(t_print *print, va_list list, int *count)
{
	unsigned int	len;
	char			*str;

	modul(print, &(print->width));
	str = va_arg(list, char *);
	len = ft_strlen(str);
	str = edits(str, print->precision, print, &len);
	if ((unsigned int)print->width > len)
		*count = *count + print->width;
	else
		*count = *count + len;
	look_at_w(len, print, str);
}

void	modul(t_print *p, int *width)
{
	if (*width < 0)
	{
		*width = *width * -1;
		p->f->m = 1;
	}
}
