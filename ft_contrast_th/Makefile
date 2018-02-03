NAME = ft_contrast_th

SRC = ft_contrast_th.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

# all: 
# 	gcc *.c -o $(NAME)

all: $(NAME)

$(NAME): libft/libft.a $(OBJ)
	@gcc $(OBJ) libft/libft.a -I libft -o $(NAME)
	@./ft_contrast_th

%.o: %.c ft_contrast_th.h
	@gcc $(CFLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@rm -f libft/libft.a
	@make fclean -C libft

re: fclean all

libft/libft.a:
	@make -C libft