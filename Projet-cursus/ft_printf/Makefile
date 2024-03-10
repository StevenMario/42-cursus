NAME = libftprintf.a
CC = cc
LIBFT_N = libft.a
LIBFT_D = ./libft
CFLAGS = -Wall -Werror -Wextra
SRCS = 		ft_printf.c\
		ft_print_char.c\
		#print_hex.c\
		print_int.c\
		print_str.c
		#print_maj_hex.c\
		#print_min_hex.c\
OBJ = $(SRCS:.c=.o)

all : $(NAME)

makelibft :
	make -C $(LIBFT_D)
	cp $(LIBFT_D)/$(LIBFT_N) .
	mv $(LIBFT_N) $(NAME)
	
$(NAME) : makelibft $(OBJ) 
	ar -rcs $(NAME) $(OBJ)
	
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
