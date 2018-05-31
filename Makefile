# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 16:35:26 by akaseris          #+#    #+#              #
#    Updated: 2018/05/31 17:26:35 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = src/
INC = includes/
OBJ = objects/
LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror 

FT = ft_lem_in ft_lemin_tools ft_input ft_inp_tools ft_inp_tools2 ft_map \
		ft_map_tools ft_path ft_path_tools ft_move

FT_O = $(patsubst %,%.o,$(FT))
FT_O_IN = $(patsubst %,$(OBJ)%.o,$(FT))
FT_C = $(patsubst %,$(SRC)%.c,$(FT))

.PHONY : all clean fclean re

all: $(NAME)

$(LIB):
	@make -C libft/ all

$(FT_O_IN): $(LIB) $(FT_C)
	@echo '\033[0;34m'***Compiling Lem_in***'\033[0m'
	@gcc -I $(INC) $(FLAGS) -c $(FT_C)
	@mkdir $(OBJ) 2> /dev/null || true
	@mv $(FT_O) $(OBJ)

$(NAME): $(FT_O_IN)
	@gcc -o $(NAME) $(FT_O_IN) libft/libft.a
	@echo '\033[0;32m'***Lem_in Compiled***'\033[0m'

clean:
	@/bin/rm -rf $(OBJ)
	@echo '\033[0;31m'***Deleted Lem_in Objects***'\033[0m'
	@make -C libft/ clean

fclean: clean
	@/bin/rm -f $(NAME)
	@echo '\033[0;31m'***Deleted Lem_in Objects and Execs***'\033[0m'
	@make -C libft/ fclean

re: fclean all
