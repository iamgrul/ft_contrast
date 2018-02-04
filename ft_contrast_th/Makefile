NAME = ft_contrast_th

SRC = ft_contrast_th.c

OBJ = $(SRC:.c=.o)

INC = ../libft/

CFLAGS = -Wall -Werror -Wextra

all:
	gcc -o $(NAME) -g *.c -I$(INC) -L$(INC) -lft
	./ft_contrast_th

#all: $(NAME)

$(NAME): $(INC)/libft.a $(OBJ)
	gcc -g $(OBJ) -I$(INC) -o $(NAME) -L$(INC) -lft
	./ft_contrast_th

%.o: %.c ft_contrast_th.h
	gcc -I$(INC) -c -o $@ $<
	#gcc $(CFLAGS) -I$(INC) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -f $(INC)/libft.a
	make fclean -C $(INC)

re: fclean all

$(INC)/libft.a:
	make -C $(INC)