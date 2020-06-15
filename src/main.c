/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:33:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/06/15 10:57:44 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    unsigned int a;

    a = 0;
    //printf("%13.4da", 42);
    printf("%o\n", -1);
    printf("%u\n", -1);
    printf("%o\n", 42);
    ft_printf("%o\n", 42);
    //ft_printf("%o", 42);
    //ft_printf("%.9d", 42);
    //ft_printf("%-5d", 42);
    //ft_putstr("\n");
    return(0);
}