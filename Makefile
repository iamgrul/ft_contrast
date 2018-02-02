NAME = ft_contrast

SRC = 

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	gcc $(OBJ) libft/libft.a -I libft -o $(NAME)

%.o: %.c ft_contrast.h
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a
	make fclean -C libft

re: fclean all

libft/libft.a:
	make -C libft

git:
	git add *
	git commit -m "auto comment"
	git push