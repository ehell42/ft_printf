/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:33:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/07/05 18:18:56 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    float   f = -0.00001;
    //ft_putnbr(ft_printf("%#.o\n", 42));
    //ft_printf("%+i", 42);
    //ft_printf("%+i", 42);
    //printf("{%*d}\n", -5, 42);
    //ft_printf("{%*d}", -5, 42);
    //ft_printf("%#.o", 42));
    ft_printf("\n%15f", f);
    printf("\n%15f\n", f);
    return(0);
}