/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 18:33:38 by aguiller          #+#    #+#             */
/*   Updated: 2020/06/21 11:56:31 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    unsigned int a;

    a = 0;
    //printf("%13.4da", 42);
    //ft_printf("@moulitest: %#.x %#.0x", 0, 0);
    printf("%x%x\n",999,42);
    ft_printf("%x%x\n",999,42);
    //ft_printf("%o", 42);
    //ft_printf("%.9d", 42);
    //ft_printf("%-5d", 42);
    //ft_putstr("\n");
    return(0);
}