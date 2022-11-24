/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/24 14:21:42 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// if auto_sizing is true, widht's get calculated hight's
// -> changing Buffers has no effect
# define WINDOW_NAME "Das ist ein window lol"

# define MLX_ERROR 1

# define ESCAPE 53

# define WIDHT 2600
# define HIGHT 1500

// for get_next_line
# define BUFFER_SIZE 1

// changing TILE_HIGHT and TILE_WIDHT creates differnt angles
# define TILE_HIGHT 80
# define TILE_WIDHT 200

# define START_POINT_X 1300
# define START_POINT_Y 100

// smoler val makes grid bigger
# define LINE_LEN 8

// factor to change the contrast of line lenght
# define COTRAST_SIZE 10

# include "../mlx/mlx.h"
# include "../include/libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

// open function
# include <sys/stat.h>
# include <fcntl.h>

// defines macros for exit func (EXIT_SUCCESS and EXIT_FAILURE)
# include <stdlib.h>

typedef struct		s_fdf
{
	int32_t			**matrix;
	char			*argv_map;
	// struct s_fdf	*next;
}					t_fdf;

typedef struct	s_data
{
	double	x[2];
	double	y[2];
	int32_t	linecount_map;
	int32_t	wordcount_map;
	int32_t	colour;
	int32_t	cross_colour;
	double	slow[2];
	double	fast[2];
	void	*mlx;
	void	*mlx_win;
}				t_data;

/*
 * functions to get the next line of a text file
 * -> ../include/get_next_line/get_next_line.c
 */
void	buff_after_line(char *buff);
char	*create_last(char *buff, char *line);
char	*get_next_line(int fd);

/*
 * functions to draw the map that was initialized in "init_matrix.c"
 * -> ../fdf_files/draw_map.c
 */
double	get_point(double prev_x, double prev_y, int32_t prev_z, char *x_or_y);
void	draw_tile(t_data *data, double x1, double y1, int32_t *z);
void	draw_map(t_fdf *fdf, t_data *data);

/*
 * functions to displays error message and exit the program
 * -> ../fdf_files/error.c
 */
void	error_msg(char *msg);

/*
 * functions to initialize coordinates and print lines with the same x or y values
 * -> ../fdf_files/etc.c
 */
void	put_horizontal_line(t_data *data);
void	put_vertical_line(t_data *data);
void	init_x(t_data *data, int32_t x1, int32_t x2);
void	init_y(t_data *data, int32_t y1, int32_t y2);

/*
 * functions to initialize the matrix -> z coordinates of the map_file
 * -> ../fdf_files/init_matrix.c
 */
int32_t	linecount(char *argv_map);
int32_t	wordcount(char *argv_map);
int32_t	open_file(char *argv_map);
void	init_matrix(t_fdf *fdf, t_data *data);

/*
 * mathematical operations to calculate a line
 * -> ../fdf_files/math.c
 */
double	m(t_data *x_data, int case_);
double	b(t_data *x_data, int case_);

/*
 * functions to initialize the the needed factors for the line algo
 * -> ../fdf_files/get_factors.c
 */
double	get_slow_factor(t_data *data);
double	get_fast_factor(t_data *data);
void	init_direction_speed(t_data *data);
void	check_koordinates(t_data *data);

/*
 * functions that draw a line
 * -> ../fdf_files/put_line.c
 */
void	line_algo(t_data *data);
void	put_line(t_data *data);

/*
 * functions that help "put_line.c" to draw a line
 * -> ../fdf_files/put_line_helps.c
 */
double	find_x(t_data *data, char *y1_or_y2);
double	find_y(t_data *data, char *y1_or_y2);
bool	reached_second_point(t_data *data);
double	distance_to_line(t_data *data, double slow_factor, double fast_factor);

#endif