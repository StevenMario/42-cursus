CC = cc
CFLAGS = -Wall -Werror -Wextra 
CLIENT = client
LIBFT_N = libft.a
LIBFT_D = ./libft
SERVER = server
OBJ = $(SRC:.c=.o)

all : $(CLIENT) $(SERVER)

$(CLIENT) : client.c 
			make -C $(LIBFT_D)
			test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
			$(CC) $(CFLAGS) client.c -L $(LIBFT_D) -l ft -o $(CLIENT)
$(SERVER) : server.c 
			make -C $(LIBFT_D)
			test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
			$(CC) $(CFLAGS) server.c -L $(LIBFT_D) -l ft -o $(SERVER)

clean:
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(CLIENT) $(SERVER)

re: fclean all
