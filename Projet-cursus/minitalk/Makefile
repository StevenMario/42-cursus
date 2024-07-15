CC = cc
CFLAGS = -Wall -Werror -Wextra 
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
LIBFT_N = libft.a
LIBFT_D = ./libft
OBJ = $(SRC:.c=.o)

all : $(CLIENT) $(SERVER)

bonus : $(CLIENT_BONUS)  $(SERVER_BONUS)

$(CLIENT) : client.c 
			make -C $(LIBFT_D)
			test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
			$(CC) $(CFLAGS)  client.c -L $(LIBFT_D) -l ft -o $(CLIENT)
$(SERVER) : server.c 
			make -C $(LIBFT_D)
			test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
			$(CC) $(CFLAGS) server.c -L $(LIBFT_D) -l ft -o $(SERVER)
$(CLIENT_BONUS) : client_bonus.c 
			make -C $(LIBFT_D)
			test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
			$(CC) $(CFLAGS) utils_bonus.c client_bonus.c -L $(LIBFT_D) -l ft -o $(CLIENT_BONUS)
$(SERVER_BONUS) : server_bonus.c 
			make -C $(LIBFT_D)
			test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
			$(CC) $(CFLAGS) server_bonus.c -L $(LIBFT_D) -l ft -o $(SERVER_BONUS)

clean:
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all bonus
