# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <akaseris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:05:02 by akaseris          #+#    #+#              #
#    Updated: 2018/05/09 15:58:35 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FT = ft_putchar ft_putstr ft_strcmp ft_strlen ft_strdup ft_strcpy ft_strcat \
		ft_strncat ft_strlcat ft_strstr ft_strncmp ft_atoi ft_toupper \
		ft_tolower ft_putnbr ft_isalpha ft_isdigit ft_isprint ft_itoa \
		ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
		ft_memcmp ft_strncpy ft_strchr ft_strrchr ft_strnstr ft_isalnum \
		ft_isascii ft_memalloc ft_memdel ft_strnew ft_strdel ft_strclr \
		ft_striter ft_striteri ft_strmap ft_strmapi ft_strequ ft_strnequ \
		ft_strsub ft_strjoin ft_strtrim ft_strsplit ft_putendl ft_putchar_fd \
		ft_putstr_fd ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone \
		ft_lstdel ft_lstadd ft_lstiter  ft_lstmap ft_isprime ft_sqrt \
		ft_sortwordtab ft_advancedsortwordtab ft_swap ft_printwordstables \
		ft_strndup ft_strreplace ft_itoa_base ft_strtolower ft_strtoupper \
		ft_utoa_base ft_convertunicode ft_strunicode ft_strmove ft_checkunicode \
		ft_strjoinfree ft_ftoa ft_printf ft_assign ft_alpha ft_handle \
		ft_process ft_form ft_snb1 ft_snb2 ft_unb1 ft_unb2 ft_printbuf ft_sprint \
		get_next_line ft_deltab ft_atoli

SRC = src/
INC = includes/
OBJ = objects/

FLAGS = -Wall -Werror -Wextra

FT_C = $(patsubst %,$(SRC)%.c,$(FT))
FT_O = $(patsubst %,%.o,$(FT))
FT_O_OBJ = $(patsubst %,$(OBJ)%.o,$(FT))

.PHONY: all clean fclean re

all: $(NAME)
	@echo '\033[1;32m'***Libft Compiled***'\033[0m'

$(FT_O_OBJ):
	@echo '\033[0;34m'***Compiling Libft***'\033[0m'
	@gcc -I $(INC) $(FLAGS) -c $(FT_C)
	@mkdir $(OBJ) 2> /dev/null || true
	@mv $(FT_O) $(OBJ)

$(NAME): $(FT_O_OBJ)
	@ar rc $(NAME) $(FT_O_OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJ)
	@echo '\033[0;31m'***Deleted Libft Objects***'\033[0m'

fclean: clean
	@/bin/rm -f $(NAME)
	@echo '\033[0;31m'***Deleted Libft Objects and Library***'\033[0m'

re: fclean all

