/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:22:54 by alexzudin         #+#    #+#             */
/*   Updated: 2020/07/10 16:46:16 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int        lengt(long long int nbr)
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

char			*ft_itoa(long long int n)
{
	char	*strmem;
	int		i;
	long long unsigned int nbr;
	long long int 	nr;

	if (n >= 0)
		nbr = n;
	else
		nbr = n * -1;
	nr = nbr;
	if (!(strmem = (char*)malloc(sizeof(char) * (lengt(n) + 1))))
		return (NULL);
	strmem[lengt(n)] = '\0';
	i = lengt(nr) - 1;
	if (nr == 0)
		strmem[0] = '0';
	if (n <= -1)
		strmem[0] = '-';
	while (nr > 0)
	{
		strmem[i] = ('0' + (nr % 10));
		nr = nr / 10;
		i--;
	}
	return (strmem);
}
