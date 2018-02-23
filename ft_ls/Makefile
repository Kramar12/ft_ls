# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariabyi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 13:32:48 by ariabyi           #+#    #+#              #
#    Updated: 2018/02/23 19:08:49 by ariabyi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     all clean fclean re $(NAME)
	CFLAGS =    -Wall -Wextra -Werror
	SRC =       main.c major.c mauxiliary.c rightstypes.c
	NAME =      ft_ls
	OBJFOLD =   obj/
	LIBFT =     ./libft/
	LIB =       -L. libft/libft.a -L. ft_printf/libftprintf.a
	HEADER =    -I ./
	OBJ =       $(addprefix $(OBJFOLD),$(patsubst %.c, %.o, $(SRC)))
all:        $(NAME)
	$(NAME):    $(OBJ)
	    @make -C $(LIBFT) -f Makefile
	    gcc $(CFLAGS) -o $(NAME) $(OBJ) $(LIB)
$(OBJFOLD)%.o:  %.c
	    mkdir -p $(OBJFOLD)
	    gcc $(CFLAGS) $(HEADER) -c $< -o $@
clean:
	    @make -C $(LIBFT) -f Makefile clean
	    @rm -rf $(OBJFOLD)
fclean:     clean
	    @make -C $(LIBFT) -f Makefile fclean
	    @rm -f $(NAME)
re:        fclean all


