NAME = fdf
LIBFT = libft
SRC =	get_next_line/get_next_line.c \
		files/math.c \
		files/main.c \
		files/etc.c \
		files/put_line.c \
		files/error.c \
		files/init_matrix.c \
		files/draw_map.c \
		files/helper_funcs/helper_funcs.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -g
DEBUG = -fsanitize=address
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):
	$(MAKE) -C mlx/
	$(MAKE) -C libft/
	$(CC) $(SRC) $(CFLAGS) $(LIBS) $(LIBFT)/libft.a $(DEBUG) -o $(NAME)
	@echo "Everything compiled successfully"

g:
	$(MAKE) -C libft/
	$(CC) $(SRC) $(CFLAGS) $(LIBS) $(LIBFT)/libft.a -o $(NAME)
	@echo "my shit compiled successfully"

clean:
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) clean -C mlx/
	@$(MAKE) clean -C libft/
	
re: fclean all
