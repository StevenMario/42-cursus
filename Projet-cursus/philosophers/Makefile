CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = philo
SRC =	check_arg.c\
		utils.c\
		init_all.c\
		routine.c\
		philosophers.c\

all: $(NAME)

$(NAME): $(SRC)
		@ $(CC) $(FLAGS) $(SRC) -o $(NAME)
		@ echo "Make[OK]"
	
fclean:
	@rm -f $(NAME)
	@ echo "Make fclean [OK]"

re: fclean all