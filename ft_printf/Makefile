NAME=libftprintf.a

CFLAGS=-Wall -Werror -Wextra

SRC=ft_printf.c flags.c num_flags.c printhex.c procwidth.c auxiliary.c putsymb.c

OBJ=$(SRC:.c=.o)
OBJLIBFT=libft/*.o

HDRS=./ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft -f Makefile
	ar rc $(NAME) $(OBJ) $(OBJLIBFT)

%.o: %.c
	gcc $(CFLAGS) -I $(HDRS) -c $< -o $@ 

clean:
	make -C ./libft -f Makefile fclean
	rm -f $(OBJ)

fclean: clean
	make -C ./libft -f Makefile fclean
	rm -f $(NAME) 

re: fclean all

.PHONY: clean fclean re all

.NOTPARALLEL: clean fclean re all
