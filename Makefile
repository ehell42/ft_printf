# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehell <фпгшддук@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 22:26:44 by aguiller          #+#    #+#              #
#    Updated: 2020/02/06 11:43:58 by ehell            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c main.c func.c octaedral.c func2.c work_with.c func3.c \
	func4.c dint.c buffers.c xx.c float.c

SRC_DIR = src/

PRINTF_H =	-I includes/
PRINTF_HL =	-I libft/


SRCS=$(addprefix $(SRC_DIR), $(SRC))

NAME = libftprintf.a

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	cd libft && $(MAKE) all
	@cp libft/libft.a ./$(NAME)
	ar rcs  libftprintf.a $(OBJ)

file: $(NAME)
	gcc -Wall -Wextra -Werror -o test ./src/main.o libftprintf.a

%.o:%.c
	gcc -Wall -Wextra -Werror $(PRINTF_H) $(PRINTF_HL) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean	
	@/bin/rm -f $(OBJ)
	@/bin/rm -f test

fclean: clean
	@cd libft && $(MAKE) fclean
	@/bin/rm -f $(NAME)

re: fclean  all 

