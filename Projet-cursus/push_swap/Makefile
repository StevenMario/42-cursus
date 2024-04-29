NAME = push_swap.a
CC = cc
FT_PRINTF_N = libftprintf.a
CFLAGS = -Wall -Werror -Wextra
SRC = 		push_swap.c
		
LIBFT_D = ./ft_printf
OBJ = $(SRC:.c=.o)

all : $(NAME)

makeftprintf :
	make -C $(LIBFT_D)
	cp $(LIBFT_D)/$(FT_PRINTF_N) .
	mv $(FT_PRINTF_N) $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
$(NAME) : makeftprintf $(OBJ) 
	ar rcs $(NAME) $(OBJ)

clean:
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re