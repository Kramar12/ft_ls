.PHONY:         all clean fclean re $(NAME)

CC = gcc
NAME = ft_ls
SRC = major.c main.c mauxiliary.c rightstypes.c files.c new_ls.c auxiliary.c newsort.c

CFLAGS = -Wall -Wextra -Werror
HEADER = -I ./header
LIBINCL = -L. libft/libft.a
LIBDIR = ./libft
LIBPRINTINCL = -L. ft_printf/libftprintf.a
LIBPRINTDIR = ./ft_printf
OBJFOLD = ./obj/
OBJ = $(addprefix $(OBJFOLD),$(patsubst %.c, %.o, $(SRC)))
all:            $(NAME)
$(NAME):        $(OBJ)
	@make -C $(LIBDIR) -f Makefile
	@make -C $(LIBPRINTDIR) -f Makefile
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBINCL) $(LIBPRINTINCL)
	@echo "ft_ls: done"
$(OBJFOLD)%.o: %.c
	@mkdir -p $(OBJFOLD)
	$(CC) $(CFLAGS) $(HEADER) -o $@ -c $<
clean:
	@rm -rf $(OBJFOLD)
	@make -C $(LIBDIR) -f Makefile clean
	@make -C $(LIBPRINTDIR) -f Makefile clean
	@echo "objects removed"
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) -f Makefile fclean
	@make -C $(LIBPRINTDIR) -f Makefile fclean
	@echo "binary removed"
re:             fclean all

