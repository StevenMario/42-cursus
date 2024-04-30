NAME = push_swap.a
CC = cc
LIBFT_N = libft.a
EXECUTABLE = push_swap
CFLAGS = -Wall -Werror -Wextra 
SRC = 		checker.c\
		print_error.c\
		push_swap.c
LIBFT_D = ./libft
OBJ = $(SRC:.c=.o)

all : $(NAME)

makelibft :
	make -C $(LIBFT_D)
	cp $(LIBFT_D)/$(LIBFT_N) .
	mv $(LIBFT_N) $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
$(NAME) : makelibft $(OBJ) 
	ar rcs $(NAME) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -L. -lft -o $(EXECUTABLE)

clean:
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
