/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 10:36:16 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/05 11:28:01 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int checkforextra(char a, char **format, t_print **print, va_list list)
{
	if (a == 't')
	{
		(*print)->type = **format;
		(*format)++;
		if ((*print)->type == 'f')
                (*print)->precision = -1;
		return (0);
	}
	if (a == 'f')
	{
		if (**format == '%')
		{
			(*print)->flag->percent = 1;
			(*format)++;
			return (0);
		}
		checkforflag(format, *print);
		(*format)++;
		return (1);
	}
	return	(secondcheck(a, format, print, list));
}

int secondcheck(char a, char **format, t_print **print, va_list list)
{
	if (a == 'w')
	{
		(*print)->havewidth = 1;
		if (**format == '*')
		{
    		(*print)->width = va_arg(list, int);
			while ( **format == '*')
				(*format)++;
		}
    	else
		{
    		(*print)->width = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
		return (checklast(format, 'w', print));
	}
	if (a == 'p')
	{
		(*print)->haveprecision = 1;
		(*format)++;
        if (**format == '*')
		{
            (*print)->precision = va_arg(list, int);
			while ( **format == '*')
				(*format)++;
		}
        else
		{
			(*print)->precision = ft_atoi(*format);
			while (**format >= '0' && **format <= '9')
				(*format)++;
		}
        return (checklast(format, 'p', print));
	}
	if (a == 's')
	{
		(*print)->razmer[0] = **format;
		if ((**format == 'j' || **format == 'z') && *((*format) + 1) != 'h')
			(*print)->razmer[0] = 'l';
		if (**format == 'L')
			(*print)->razmer[1] = **format;
		(*format)++;
		if (**format == 'l' || **format == 'h')
		{
			(*print)->razmer[1] = **format;
				(*format)++;
		}
		return (checklast(format, 's', print));
	}
	return (exits(print));
}

int checklast(char **f, char a, t_print **print)
{
	if (a == 'w')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' || **f == 'i'
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p' || **f == '.' 
		|| **f =='%' || **f == 'u' || **f == '+' || **f == 'U' || (**f >= '0' && **f <= '9'))
			return (1);
	}
	if (a == 'p')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' || **f == 'i'
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p' || **f =='%' 
		|| **f == 'u' || **f == 'l' || **f == 'h' || **f == 'U' || **f == '.' || **f == '#' || **f == 'L')
			return (1);
	}
	if (a == 's')
	{
		if (**f == 'd' || **f == 'f' || **f == 'c' || **f == 's' || **f == 'o' || **f == 'i'
		|| **f == 'x' || **f == 'X' || **f == 'F' || **f == 'p' || **f =='%' 
		|| **f == 'u' || **f == 'U' || **f == '#' || **f == 'l' || **f == 'j' || **f == 'z' || **f == 'h' || **f == 'L')
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
    new_print->type = 'e';
	new_print->haveprecision = 0;
	new_print->havewidth = 0;
	new_print->lenforpr = 0;
	new_print->sizecorrect = 0;
    new_print->width = 0;
	new_print->helper = 0;
    new_print->precision = 0;
	new_print->minus = 0;
	new_print->razmer = ft_strnew(2);
	new_print->razmer[0] = ' ';
	new_print->razmer[1] = ' ';
    return (new_print);
}

int exits(t_print **end_print)
{
	freeinit(end_print);
	//exit(0);
	return (0);
}
