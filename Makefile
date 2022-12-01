NAME = fdf
LIBFT = include/libft
SRC =	include/get_next_line/get_next_line.c \
		fdf_files/math.c \
		fdf_files/main.c \
		fdf_files/etc.c \
		fdf_files/put_line.c \
		fdf_files/extra.c \
		fdf_files/init_matrix.c \
		fdf_files/draw_map.c \
		fdf_files/get_factors.c \
		fdf_files/put_line_helps.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -g
DEBUG = -fsanitize=address
LIBS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(MAKE) -C mlx/
	cd include/libft && make bonus; cd ../../
	$(CC) $(LIBFT)/libft.a $(OBJ) $(CFLAGS) $(LIBS)  -o $(NAME)
	@echo "Everything compiled successfully"

g:
	$(MAKE) -C libft/
	$(CC) $(SRC) $(CFLAGS) $(LIBS) $(LIBFT)/libft.a -o $(NAME)
	@echo "my shit compiled successfully"

clean:
	@$(RM) $(NAME)
	
fclean: clean
	@$(MAKE) clean -C mlx/
	@$(MAKE) clean -C include/libft/
	
re: fclean all
