# -*- Makefile -*-
CC = cc

CFLAGS = -Werror -Wall -Wextra -g

NAME = fractol
LIBFTDIR = libft
LIBFT = libft/libft.a
SRC = window_controls.c fractol.c event_controls.c
LDFLAGS = -L/usr/include/../lib -L/usr/local/lib/ -lmlx -lXext -lX11 -lm

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -L$(LIBFTDIR) -I$(LIBFTDIR) -lft -o $(NAME)

clean:
	rm -f $(NAME)
	$(MAKE) clean -C $(LIBFTDIR)


test: $(SRC) $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -L$(LIBFTDIR) -I$(LIBFTDIR) -lft -o $(NAME)

fclean: clean
	rm -f $(LIBFT)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re