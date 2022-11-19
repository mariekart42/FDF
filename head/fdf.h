/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/19 16:08:20 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

// if auto_sizing is true, widht's get calculated hight's
// -> changing Buffers has no effect
# define WINDOW_NAME "Das ist ein window lol"
# define AUTO_SIZING false

# define WIDHT 2600
# define HIGHT 1500

// for get_next_line
# define BUFFER_SIZE 1

// changing TILE_HIGHT and TILE_WIDHT creates differnt angles
# define TILE_HIGHT 80
# define TILE_WIDHT 200

# define START_POINT_X WIDHT/2
# define START_POINT_Y 100

// smoler val makes grid bigger
# define LINE_LEN 8


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
	

	char	*argv_map;
	
	struct s_fdf *next;
}				t_fdf;

typedef struct	s_data
{
    double	x[2];
    double	y[2];
	
	int32_t linecount_map;
	int32_t wordcount_map;
	
	int32_t	colour;
	int32_t	cross_colour;
	// put line
	double	slow[2];
	double 	fast[2];

    void	*mlx;
	void	*mlx_win;
    
}				t_data;


// ---- colour shit -----
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"

# define RESET "\x1B[0m"
// ----------------------

void	buff_after_line(char *buff);
char	*create_last(char *buff, char *line);
char	*get_next_line(int fd);

//		auto_sizing.c
void *init_window(t_data *data);
void *calc_size(t_data *data);


//		draw_map.c
double	get_point(double prev_x, double prev_y, int32_t prev_z, char *x_or_y);
void	draw_tile(t_data *data, double x1, double y1, int32_t *z);
void	draw_map(t_fdf *fdf, t_data *data);

//		error.c
void	error_msg(char *msg);

//		etc.c
void	put_horizontal_line(t_data *data);
void	put_vertical_line(t_data *data);
void	init_x(t_data *data, int32_t x1, int32_t x2);
void	init_y(t_data *data, int32_t y1, int32_t y2);

//		init_matrix.c
int32_t linecount(char *argv_map);
int32_t wordcount(char *argv_map);
void init_matrix(t_fdf *fdf, t_data *data);

//		math.c
double	m(t_data *x_data, int case_);
double	b(t_data *x_data, int case_);

//		put_line.c
void	check_koordinates(t_data *data);
double	find_x(t_data *data, char *y1_or_y2);
double	find_y(t_data *data, char *y1_or_y2);
bool	reached_second_point(t_data *data);
void	init_direction_speed(t_data *data);
double	get_slow_factor(t_data *data);
double	get_fast_factor(t_data *data);
double	distance_to_line(t_data *data, double slow_factor, double fast_factor);
void	bresenham_algo(t_data *data);
void	put_line(t_data *data);


// ----------------------------------------------------------
// // ---- delete later if included ----------------------------
// //		get_next_line.c
// void	buff_after_line(char *buff);
// char	*create_last(char *buff, char *line);
// char	*get_next_line(int fd);

// //		include_libft.c
// size_t	ft_strlen(const char *str);
// int		ft_strncmp(const char *s1, const char *s2, size_t n);
// void	*ft_memmove(void *dest, const void *src, size_t n);
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strchr(const char *str, int c);
// int32_t	ft_atoi(const char *str);
// int32_t	amount_subs(const char *s, char c);
// char	**ft_split(char const *s, char c);
// // -----------------------------------------------------------
// ---- delete_later_funcs.c ---------------------------------
void 	put_cross(t_data *x_data,int x, int y);
void 	print_case(t_data *x_data, double slow_f, double fast_f);
void 	print_factor(double fast_f, double slow_f);
// ------------------------------------------------------------

#endif