/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 15:34:57 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/10 15:59:41 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *edits(char *str, unsigned int precision, t_print *p, unsigned int *len)
{
	char *newstr;

	if (str == NULL)
    {
        *len +=6;
        str = "(null)";
    }
	if (precision < *len && p->haveprecision == 1)
	{
		if (precision == 0)
		{
			p->helper = 1;
			*len = 0;
			return (str);
		}
		*len = precision;
		newstr = ft_strnew(precision);
		ft_strncpy(newstr, str, precision);
		return (newstr);
	}
	else
		return (str);
}

char *putlongint(unsigned long long int nbr)
{
	char *nbr_hex;
	int len;
	unsigned long long int nbr_tmp;
	
	len = 0;
	nbr_tmp = nbr;
	if (nbr == 0)
		return (szero());
    while (nbr_tmp)
    {
        nbr_tmp /= 8;
        len++;
    }
	nbr_hex = (char*)(malloc(sizeof(char) * (len + 1)));
	nbr_hex[len] = '\0';
	len--;
	while (len >= 0)
    {
        nbr_hex[len] = '0' + nbr % 8;
        nbr /= 8;
        len--;
    }
	return (nbr_hex);
}

int        len(long long int nbr)
{
    unsigned int len;
    unsigned long long int n;

    len = 0;
    if (nbr == 0)
        return (len + 1);
    if (nbr < 0)
    {
        n = nbr * -1;
        len++;
    }
    else
        n = nbr;
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char			*itoa(long long int n)
{
	char	*strmem;
	int		i;
	unsigned long long int nbr;
	unsigned long long int 	nr;

	if (n >= 0)
		nbr = n;
	else
		nbr = n * -1;
	nr = nbr;
	if (!(strmem = (char*)malloc(sizeof(char) * (len(n) + 1))))
		return (NULL);
	strmem[len(n)] = '\0';
	i = len(n) - 1;
	if (nr == 0)
		strmem[0] = '0';
	if (n <= -1)
	{
		strmem[0] = '-';
	}
	while (nr > 0)
	{
		strmem[i] = ('0' + (nr % 10));
		nr = nr / 10;
		i--;
	}
	return (strmem);
}

char *szero()
{
	char *a;

	a = ft_strnew(1);
	a[0] = '0';
	return (a);
}