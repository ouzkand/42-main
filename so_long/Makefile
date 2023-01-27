# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 14:56:21 by okandemi          #+#    #+#              #
#    Updated: 2023/01/22 15:44:00 by okandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = src/main.c src/map1.c src/map2.c src/action.c src/basic_op.c src/error.c

OBJS = $(SRCS:.c=.o)

CC = gcc

MFLAGS = ./mlx/libmlx.a ./ft_printf/libftprintf.a ./get_next_line/get_next_line.a

AFLAGS =  -Wall -Wextra -Werror -I./mlx -I./ft_printf -I./get_next_line

RM = rm -rf

NAME = so_long

all :$(MFLAGS) $(NAME)

$(MFLAGS):
	make -C ./get_next_line
	make -C ./ft_printf
	make -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(MFLAGS) $(AFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

fclean : clean
	make fclean -C ./ft_printf
	make fclean -C ./get_next_line
	$(RM) $(NAME)

clean :
	make clean -C ./ft_printf
	make clean -C ./get_next_line
	make clean -C ./mlx
	$(RM) ./src/*.o

re : fclean all

.PHONY : all fclean clean re