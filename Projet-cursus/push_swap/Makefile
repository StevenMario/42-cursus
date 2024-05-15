NAME = push_swap
CC = cc
LIBFT_N = libft.a
CFLAGS = -Wall -Werror -Wextra 
SRC = 		checker.c\
			swap_utils.c\
			print_error.c\
			algorithm.c\
			operation.c\
			operation_swap.c\
			operation_push.c\
			operation_rotate.c\
			operation_reverse_rotate.c\
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
	$(CC) $(CFLAGS) $(OBJ) -L $(LIBFT_D) -l ft -o $(NAME)

clean:
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
