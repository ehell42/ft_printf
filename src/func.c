/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:36:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/05/31 11:22:44 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int checkforextra(char a, char **format, t_print *print)
{
	if (a == 't')
	{
		print->type = **format;
		(*format)++;
		return (0);
	}
	if (a == 'f')
	{
		if (**format == '%')
		{
			print->flag->percent = 1;
			(*format)++;
			return (0);
		}
		checkforflag(format, print);
		(*format)++;
		return (1);
	}
	return	(secondcheck(a, format, print));
}

int secondcheck(char a, char **format, t_print *print)
{
	if (a == 'w')
	{
		if (**format == '*')
    		print->width = "*";
    	else
    		(print->width) = *format;
		return (checklast(format, 'w', print));
	}
	if (a == 'p')
	{
		(*format)++;
        if (**format == '*')
            print->precision = "*";
        else
			print->precision = *format;
        return (checklast(format, 'p', print));
	}
	if (a == 's')
	{
		print->razmer[0] = **format;
		(*format)++;
		if (**format == 'l' || **format == 'h')
		{
			print->razmer[1] = **format;
			(*format)++;
		}
		return (checklast(format, 's', print));
	}
	return (exits(print));
}

int checklast(char **f, char a, t_print *print)
{
	while ((**f >= '0' && **f <= '9') || **f == '*')
		(*f)++;
	if (a == 'w')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' 
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p' || **f == '.' 
		|| **f =='%' || **f == 'u')
			return (1);
	}
	if (a == 'p')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' 
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p' || **f =='%' 
		|| **f == 'u' || **f == 'l' || **f == 'h')
			return (1);
	}
	if (a == 's')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' 
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p' || **f =='%' 
		|| **f == 'u')
			return (1);
	}
	return (exits(print));
}

t_print    *print_init(t_print *new_print)
{
	t_flag *new_flag;

	new_flag = (t_flag*)malloc(sizeof(t_flag));
	new_print = (t_print*)malloc(sizeof(t_print));
	new_flag->plus = 0;
	new_flag->minus = 0;
	new_flag->ortokop = 0;
	new_flag->probel = 0;
	new_flag->zero = 0;
	new_flag->percent = 0;
    new_print->flag = new_flag;
    new_print->type = 0;
    new_print->width = "0";
    new_print->precision = "0";
	new_print->razmer[0] = ' ';
	new_print->razmer[1] = ' ';
    return (new_print);
}

int exits(t_print *end_print)
{
	//ft_putstr("something wrong in ");
	//ft_putstr(strerr);
	free(end_print);
	exit(-1);
	return (0);
}
