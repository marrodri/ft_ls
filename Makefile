# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marrodri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 14:48:43 by marrodri          #+#    #+#              #
#    Updated: 2018/12/20 22:22:07 by marrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = ft_binary_tree.c ft_ls.c ftls_getstatus.c ftls_tree_comp.c\
		main.c ftls_flagtable.c ftls_output.c print_tree.c directories_to_list.c\
		string_manipulation.c long_format_setup.c ftls_file_data.c ftls_recursive.c\
		ftls_tree_to_list.c
OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c $< -o $@ -g

$(LIBFT):
		@make -C libft

$(NAME): $(LIBFT) $(OBJ)
		@gcc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -g

clean:
		@rm -rf $(OBJ)
		@make -C libft clean

fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean

re: fclean all
