/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/31 15:53:54 by mmensing         ###   ########.fr       */
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


//		delete_later_funcs.c
void put_cross(t_data *x_data,int x, int y);

//		include_libft.c
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t n);


//		not_compile_funcs.c
void put_rectangle(t_data *x_data, int colour);
void shift_rectangle(t_data *x_data, int colour, bool right, bool up, int times, int sep);

//		math.c
float m(t_data *x_data);
float b(t_data *x_data);



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