/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/30 16:09:53 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <unistd.h>
#include <stdio.h>
# include <stdbool.h>

// defines macros for exit func (EXIT_SUCCESS and EXIT_FAILURE)
# include <stdlib.h>

typedef struct	s_data
{
    int     x[2];
    int     y[2];
	
	
	// put line
	int32_t	slow[2];
	int32_t fast[2];

    
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


//		not_compile_funcs.c
void put_rectangle(t_data *x_data, int colour);
void shift_rectangle(t_data *x_data, int colour, bool right, bool up, int times, int sep);


//		test_mlx.c
void init_y(t_data *x_data, int y1, int y2);
void init_x(t_data *x_data, int x1, int x2);
void put_vertical_line(t_data *x_data, int colour);
void put_horizontal_line(t_data *x_data, int colour);


//		put_line.c
int8_t get_go_factor(t_data *x_data);
void init_koordinates(t_data *x_data);
int find_x(t_data *x_data);
int find_y(t_data *x_data);
bool reached_second_point(t_data *x_data);
void init_direction_speed(t_data *x_data);
void bresenham_algo(t_data *x_data, int32_t colour);
void put_line(t_data *x_data, int32_t colour);


//		error.c
void	error_msg(char *msg);

#endif