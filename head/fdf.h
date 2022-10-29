/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/29 13:30:24 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

#include "../mlx/mlx.h"
// #include <stdlib.h>
// #include <stdio.h>
# include <stdbool.h>

typedef struct	s_data
{
    int     x[2];
    int     y[2];
	
	// put line
	int	slow;
	int fast;
	int ori_slow;
	int ori_fast;
    
    void	*mlx;
	void	*mlx_win;
    
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


//		test_mlx.c
void init_y(t_data *x_data, int y1, int y2);
void init_x(t_data *x_data, int x1, int x2);
void shift_rectangle(t_data *x_data, int colour, bool right, bool up, int times, int sep);
void put_rectangle(t_data *x_data, int colour);
void put_vertical_line(t_data *x_data, int colour, int iter);
void put_horizontal_line(t_data *x_data, int colour, int iter);
void put_cross(t_data *x_data,int x, int y);

//		put_line.c
void	put_line(t_data *x_data, int colour);

//		error.c
void	error_msg(char *msg);

#endif