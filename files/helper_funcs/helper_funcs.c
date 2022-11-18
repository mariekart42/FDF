/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:37:09 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/18 10:37:50 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../head/fdf.h"

// x and y are the middle point of the cross
// len is the pixel len of the lines
void put_cross(t_data *x_data,int x, int y)
{
	int save_x;
	int save_y;
	int minus_len;
	int len;
	
	save_x = x;
	save_y = y;
	len = 4;
	len++;
	minus_len = len * (-1);
	x += len;
	y -= len;
	while (len - 1 > minus_len)
	{
		x -= 1;
		y += 1;
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y, x_data->cross_colour);
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y - 2 + (len * 2), x_data->cross_colour);
		len--;
	}
	// middle point
	mlx_pixel_put(x_data->mlx, x_data->mlx_win, save_x, save_y, 0XFF0000);
}