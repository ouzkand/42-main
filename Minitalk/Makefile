SRC = server client
BONUS = server_bonus client_bonus

SRCLIENT_BONUS =   client_bonus.c
OBJSCLIENT_BONUS = $(SRCLIENT_BONUS:.c=.o)

SRCSERVER_BONUS = server_bonus.c
OBJSERVER_BONUS = $(SRCSERVER_BONUS:.c=.o)

SRCUTILS_BONUS= minitalk_utils_bonus.c
OBJUTILS_BONUS = $(SRCUTILS_BONUS:.c=.o)

SRCLIENT =   client.c
OBJSCLIENT = $(SRCLIENT:.c=.o)

SRCSERVER = server.c
OBJSERVER = $(SRCSERVER:.c=.o)

CFLAGS = -Wall -Wextra -Werror
LIB = ./ft_printf/libftprintf.a 

all: $(SRC) $(BONUS)
src: $(SRC)
bonus: $(BONUS)


$(SRC): $(LIB) $(OBJSERVER) $(OBJSCLIENT)
	gcc -o server $(SRCSERVER) $(CFLAGS) $(LIB)
	gcc -o client $(SRCLIENT) $(CFLAGS) $(LIB)

$(BONUS): $(LIB) $(OBJSERVER_BONUS) $(OBJSCLIENT_BONUS) $(OBJUTILS_BONUS)
	gcc -o server_bonus $(SRCSERVER_BONUS) $(SRCUTILS_BONUS) $(CFLAGS) $(LIB)
	gcc -o client_bonus $(SRCLIENT_BONUS) $(SRCUTILS_BONUS) $(CFLAGS) $(LIB)

$(LIB):
	make -C ./ft_printf

clean:
	rm -f $(OBJSERVER_BONUS) $(OBJSCLIENT_BONUS) $(OBJUTILS_BONUS) $(OBJSERVER) $(OBJSCLIENT)
	rm -f ./ft_printf/*.o

fclean: clean
	rm -f server client server_bonus client_bonus
	rm -f ./ft_printf/*.a

re: fclean all

.PHONY: all clean fclean re
