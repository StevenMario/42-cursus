CC = cc
FLAGS = -Wall -Wextra -Werror 
LIBFT_N = libft.a
LIBFT_D = ./libft
MLX_D = mlx_linux
NAME = so_long
SRC = main.c


%.o: %.c
	$(CC) $(FLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAME)

$(NAME): main.c
	make -C $(MLX_D)
	make -C $(LIBFT_D)
	test -e $(LIBFT_D)/$(LIBFT_N) || cp $(LIBFT_D)/$(LIBFT_N) $(LIBFT_D)
	$(CC) $(FLAGS) main.c -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -L $(LIBFT_D) -l ft  -o $(NAME)
clean:
	make clean -C $(MLX_D) 
	make clean -C $(LIBFT_D)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_D)
	rm -f $(NAME)

re: fclean all