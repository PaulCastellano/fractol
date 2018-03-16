NAME = fractol

FILES = main.c

OBJ = $(FILES:.c=.o)

CFLAG = -Wall -Werror -Wextra

LIBXL = -lm -L libft/ -L/usr/lib/X11 -lmlx -lXext -lX11

all: $(NAME)

$(NAME) : libft
	echo "Creating LINUX executable $(NAME) ..."
	gcc $(CFLAGS) libft/libft.h -c $(FILES)
	gcc -o $(NAME) $(OBJ) libft/libft.a $(LIBXL)

libft:
	make -C libft fclean
	make -C libft

clean :
	echo "Removing object files ..."
	rm -f $(OBJ)

fclean : clean
	echo "Removing $(NAME) ..."
	rm -f $(NAME)

re: fclean all
