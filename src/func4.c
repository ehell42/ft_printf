/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 17:24:04 by alexzudin         #+#    #+#             */
/*   Updated: 2020/06/16 12:46:28 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int countforocta(unsigned long int a,  t_print *p)
{
	int count;

	count = 0;
	if (p->haveprecision == 0 && p->flag->ortokop == 1)
		count++;
	if (a == 0)
		return (1);
	while (a > 0)
	{
		a /=8;
		count++;
	}
	return (count);
}