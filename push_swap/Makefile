# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 16:36:14 by okandemi          #+#    #+#              #
#    Updated: 2023/02/01 12:41:47 by okandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	=	\033[0m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
RED		=	\033[31m

NAME = push_swap

SRCS =  main.c pushswap_utils.c pushswap_utils2.c sort.c swap1.c swap2.c 

OBJS = $(SRCS:.c=.o)

CC = @gcc -ggdb
AFLAGS =  -Wall -Wextra -Werror ./libft 
CFLAGS =  -Wall -Wextra -Werror

RM = rm -rf


all :$(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)>- Compiling... [$(NAME)] $(RESET)"
	@$(CC) $(OBJS) $(CFLAGS) -o $(NAME)
	@echo "$(GREEN)>-Finish.. [$(NAME)] $(RESET)"

fclean : clean
	@echo "$(RED)>- Deleting... [$(NAME)] $(RESET)"
	@$(RM) ./*.a
	@$(RM) $(NAME)
	@echo "$(RED)>- Finish.. [$(NAME)] $(RESET)"

clean :
	@$(RM) ./*.o
	@$(RM) $(OBJS)

re : fclean all

.PHONY : all fclean clean re
