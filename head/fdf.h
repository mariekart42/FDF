/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/04 11:50:18 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

# define WIDHT 1000
# define HIGHT 700

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
# include <stdbool.h>

// defines macros for exit func (EXIT_SUCCESS and EXIT_FAILURE)
# include <stdlib.h>

typedef struct	s_data
{
    float     x[2];
    float     y[2];
	
	
	// put line
	float	slow[2];
	float fast[2];

    
    void	*mlx;
	void	*mlx_win;
    
	// void	*img;
	// char	*addr;
	// int		bits_per_pixel;
	// int		line_length;
	// int		endian;
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


//		delete_later_funcs.c
void put_cross(t_data *x_data,int x, int y);
void print_case(t_data *x_data, float slow_f, float fast_f);
void print_factor(float fast_f, float slow_f);

//		include_libft.c
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


//		not_compile_funcs.c
void put_rectangle(t_data *x_data, int colour);
void shift_rectangle(t_data *x_data, int colour, bool right, bool up, int times, int sep);

//		math.c
float m(t_data *x_data);
float b(t_data *x_data, int case);



//		test_mlx.c
void init_y(t_data *x_data, int y1, int y2);
void init_x(t_data *x_data, int x1, int x2);
void put_vertical_line(t_data *x_data, int colour);
void put_horizontal_line(t_data *x_data, int colour);


//		put_line.c
// float get_go_factor(t_data *x_data);
float get_slow_factor(t_data *x_data);
float get_fast_factor(t_data *x_data);
void init_koordinates(t_data *x_data);
float find_x(t_data *x_data, char *y1_or_y2);
float find_y(t_data *x_data, char *y1_or_y2);
bool reached_second_point(t_data *x_data);
void init_direction_speed(t_data *x_data);
void bresenham_algo(t_data *x_data, int32_t colour);
void put_line(t_data *x_data, int32_t colour);


//		error.c
void	error_msg(char *msg);

#endif