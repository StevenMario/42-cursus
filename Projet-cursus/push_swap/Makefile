NAME = push_swap.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFILES =	
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME): $(OFILES) push_swap.h
	ar rc $(NAME) $(OFILES)
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OFILES)
fclean: clean
	rm -f $(NAME)
re: fclean all
