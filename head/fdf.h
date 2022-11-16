/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/16 19:26:34 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

# define WIDHT 1000
# define HIGHT 1000
# define BUFFER_SIZE 20

# define TILE_HIGHT 50
# define TILE_WIDHT 50

# define START_POINT_X 200
# define START_POINT_Y 400

# define LINE_LEN 1
# define ANGLE 0.5

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
# include <stdbool.h>

// cos and sin
#include <math.h>

// open function
#include <sys/stat.h>
#include <fcntl.h>

// defines macros for exit func (EXIT_SUCCESS and EXIT_FAILURE)
# include <stdlib.h>

typedef struct  s_fdf
{
	int32_t	**matrix;

	// float curr_point[3];
	// float right_point[3];
	// float lower_point[3];
	
	int32_t linecount_map;
	int32_t wordcount_map;

	// float	x1;
	// float	y1;

	// float y_vector;
	// float x_vector;

	// int val;
	char *argv_map;
	
	struct s_fdf *next;
}				t_fdf;

typedef struct	s_data
{
    float     x[2];
    float     y[2];
	
	int32_t colour;
	int32_t cross_colour;
	// put line
	float	slow[2];
	float fast[2];

    
    void	*mlx;
	void	*mlx_win;
    
}				t_data;


//colour shit
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"

# define RESET "\x1B[0m"

//		new_try.c
float get_point(float prev_x, float prev_y, char *x_or_y);
void draw_tile(t_data *data, float x1, float y1);



//		init_points.c
void init_current_point(t_fdf *fdf, char *lower_or_right_point);
void init_lower_point(t_fdf *fdf, int32_t x, int32_t y, int32_t z);
void init_next_right_point(t_fdf *fdf, int32_t x, int32_t y, int32_t z);
void init_points(t_fdf *fdf, t_data *data);

// //		draw_map.c
// void draw_lines(t_fdf *fdf, t_data *data, bool right, bool down);

//		init_matrix.c
int32_t linecount(char *argv_map);
void init_matrix(t_fdf *fdf);
int32_t wordcount(char *argv_map);


// 		draw_map.c
void func(t_data *data, int32_t x, int32_t y, int32_t z);
void init_vectors(t_fdf *fdf);
void func_(t_fdf *fdf, t_data *data, int32_t x_, int32_t y_, int32_t z_);
void print_grit(t_data *data, t_fdf *fdf);
void print_coordinate(t_data *data, t_fdf *fdf, int32_t x, int32_t y, int32_t z);



//		get_next_line.c
void	buff_after_line(char *buff);
char	*create_last(char *buff, char *line);
char	*get_next_line(int fd);



//		delete_later_funcs.c
void put_cross(t_data *x_data,int x, int y);
void print_case(t_data *x_data, float slow_f, float fast_f);
void print_factor(float fast_f, float slow_f);

//		include_libft.c
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
int32_t	ft_atoi(const char *str);
int32_t	amount_subs(const char *s, char c);
char	**ft_split(char const *s, char c);



//		not_compile_funcs.c
void put_rectangle(t_data *x_data, int colour);
void shift_rectangle(t_data *x_data, int colour, bool right, bool up, int times, int sep);

//		math.c
float m(t_data *x_data, int case_);
float b(t_data *x_data, int case_);



//		test_mlx.c
void init_y(t_data *data, int32_t y1, int32_t y2);
void init_x(t_data *data, int32_t x1, int32_t x2);
void put_vertical_line(t_data *data);
void put_horizontal_line(t_data *data);


//		put_line.c
void check_koordinates(t_data *data);
float find_x(t_data *data, char *y1_or_y2);
float find_y(t_data *data, char *y1_or_y2);
bool reached_second_point(t_data *data);
void init_direction_speed(t_data *data);
float get_slow_factor(t_data *data);
float get_fast_factor(t_data *data);
float distance_to_line(t_data *data, float slow_factor, float fast_factor);
void bresenham_algo(t_data *data);
void put_line(t_data *data);


//		error.c
void	error_msg(char *msg);

#endif