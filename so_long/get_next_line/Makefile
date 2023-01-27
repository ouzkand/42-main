# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: okandemi <okandemi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/22 14:57:18 by okandemi          #+#    #+#              #
#    Updated: 2023/01/22 14:57:19 by okandemi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

CC = @gcc

RM = @rm -f

CFLAGS = -Wall -Wextra -Werror -I.

NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re