NAME = libftprintf.a
CC = cc
LIBFT_N = libft.a
CFLAGS = -Wall -Werror -Wextra
SRC = 		ft_printf.c\
		ft_print_char.c\
		print_int.c\
		print_str.c\
		print_unsigned_dec.c\
		print_hex.c\
		print_adress_hex.c
		
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

clean:
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
