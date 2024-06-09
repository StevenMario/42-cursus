CC = cc
CFLAGS = -Wall -Werror -Wextra 
CLIENT = client
SERVER = server

all : $(CLIENT) $(SERVER)

$(CLIENT) : client.c
				$(CC) $(CFLAGS) client.c utils.c -o client
$(SERVER) : server.c
				$(CC) $(CFLAGS) server.c utils.c -o server
fclean:
		rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all fclean re