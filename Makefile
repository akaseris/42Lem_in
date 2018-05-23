# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/25 16:35:26 by akaseris          #+#    #+#              #
#    Updated: 2018/05/22 14:28:16 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

SRC = src/
INC = includes/
OBJ = objects/
LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror 

FT = ft_lem_in

FT_O = $(patsubst %,%.o,$(FT))
FT_C = $(patsubst %,$(SRC)%.c,$(FT))

.PHONY : all clean fclean re

all: $(NAME)

$(LIB):
	@make -C libft/ all

$(FT_O): $(LIB) $(FT_C)
	@echo '\033[0;34m'***Compiling Lem_in***'\033[0m'
	@gcc -I $(INC) $(FLAGS) -c $(FT_C)
	@mkdir $(OBJ) 2> /dev/null || true
	@mv $(FT_O) $(OBJ)

$(NAME): $(FT_O)
	@gcc -o $(NAME) $(FT_O) libft/libft.a
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
