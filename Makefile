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

SRC = ft_printf.c main.c

SRC_DIR = src/

PRINTF_H =	-I includes/

SRCS=$(addprefix $(SRC_DIR), $(SRC))

NAME = ft_printf

OBJ = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ) 
	cd libft && $(MAKE) all
	gcc -Wall -Wextra -Werror -o $(NAME) $(OBJ) -L./libft -lft 

%.o:%.c
	gcc -Wall -Wextra -Werror $(PRINTF_H) -c $< -o $@

clean:
	@cd libft && $(MAKE) clean	
	@/bin/rm -f $(OBJ)

fclean: clean
	@cd libft && $(MAKE) fclean
	@/bin/rm -f $(NAME)

re: fclean  all 

