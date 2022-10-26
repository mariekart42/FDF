NAME = fdf
SRC = files/test_mlx.c

#leaks -atExit -- ./so_long maps/wrong_map.ber
FLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):
	$(MAKE) -C mlx
	$(CC) $(SRC) $(FLAGS) $(NAME)
	@echo "Everything compiled successfully"

g:
	$(CC) $(SRC) $(FLAGS) $(NAME)
	@echo "my shit compiled successfully"

clean:
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) clean -C mlx/
	
re: fclean all
# -Og -g3 -fsanitize=address