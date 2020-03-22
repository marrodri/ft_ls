
NAME = ft_ls

RM = rm -f

SRC = ft_binary_tree.c ft_ls.c ftls_getstatus.c ftls_tree_comp.c\
		main.c ftls_flagtable.c ftls_output.c

OBJ = $(SRC:.c=.o)

LIBFT = ./libft/libft.a

.PHONY = all clean fclean clean re

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c $< -o $@ -g

$(LIBFT):
		@make -C libft

$(NAME): $(LIBFT) $(OBJ)
		@gcc $(OBJ) $(LIBFT) -o $(NAME) -g

clean:
		@rm -rf $(OBJ)
		@make -C libft clean

fclean: clean
		@rm -rf $(NAME)
		@make -C libft fclean

re: fclean all
