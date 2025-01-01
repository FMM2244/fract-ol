# -*- Makefile -*-
CC = cc

CFLAGS = -Werror -Wall -Wextra -g

NAME = fractol
LIBFTDIR = libft
LIBFT = libft/libft.a
SRC = image_controls.c fractol.c event_controls.c
LDFLAGS = -L/usr/include/../lib -L/usr/local/lib/ -lmlx -lXext -lX11 -lm

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -L$(LIBFTDIR) -I$(LIBFTDIR) -lft -o $(NAME)

clean:
	rm *.o
	$(MAKE) clean -C $(LIBFTDIR)

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)
	$(MAKE) fclean -C $(LIBFTDIR)

re: fclean all

.PHONY: all clean fclean re
