# -*- Makefile -*-
CC = cc

CFLAGS = -Werror -Wall -Wextra

NAME = fractol
LIBFTDIR = libft
LIBFT = libft/libft.a
SRC = fractol.c window_controls.c 

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) -L$(LIBFTDIR) -lft -lX11 -lXext -lmlx -lm -o $(NAME)
clean:
	rm -f $(NAME)
	rm -f *.o

fclean: clean
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re