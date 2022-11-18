NAME = fdf
SRC =	files/include_libft.c \
		files/math.c \
		files/main.c \
		files/etc.c \
		files/put_line.c \
		files/error.c \
		files/get_next_line.c \
		files/init_matrix.c \
		files/draw_map.c \
		files/helper_funcs/helper_funcs.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	$(MAKE) -C mlx/
	$(MAKE) -C libft/
	$(CC) $(SRC) $(CFLAGS) $(NAME)
	@echo "Everything compiled successfully"

g:
	$(MAKE) -C libft
	$(CC) $(SRC) $(CFLAGS) $(NAME)
	@echo "my shit compiled successfully"

clean:
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) clean -C mlx/
	@$(MAKE) clean -C libft/
	
re: fclean all
# -Og -g3 -fsanitize=address