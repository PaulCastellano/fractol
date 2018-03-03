NAME = fractol

FILES = main.c

OBJECTS = $(FILES:.c=.o)

CFLAG = -Wall -Werror -Wextra

ATTACH = -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	make -C libft/ fclean
	make -C libft/
	gcc $(CFLAG) -I libft/ -c $(FILES)
	gcc $(CFLAG) -o $(NAME) $(OBJECTS)  $(ATTACH)

clean:
	/bin/rm -f $(OBJECTS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
