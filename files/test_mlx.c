/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:33:14 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/29 14:11:17 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"
#include "../mlx/mlx.h"

void put_horizontal_line(t_data *x_data, int colour, int iter)
{
	int x1 = x_data->x[0];
	
	if (x1 <= x_data->x[1])
	{
		while (x1 <= x_data->x[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[0], colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[1], colour);
			x1++;
		}
	}
	else
	{
		while (x1 >= x_data->x[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[0], colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[1], x_data->y[0], colour);
			x1--;
		}
	}
}

void put_vertical_line(t_data *x_data, int colour, int iter)
{
	int y1 = x_data->y[0];
	if (y1 <= x_data->y[1])
	{
		while (y1 <= x_data->y[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[0], y1, colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[1], y1, colour);
			y1++;
		}
	}
	else
	{
		while (y1 >= x_data->y[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[0], y1, colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[1], y1, colour);
			y1--;
		}
	}
}

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
	len = 3;
	len++;
	minus_len = len * (-1);
	x += len;
	y -= len;
	while (len - 1 > minus_len)
	{
		x -= 1;
		y += 1;
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y, 0xee6a50);
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y - 2 + (len * 2), 0xee6a50);
		len--;
	}
	// middle point
	mlx_pixel_put(x_data->mlx, x_data->mlx_win, save_x, save_y, 0XFF0000);
}

void put_rectangle(t_data *x_data, int colour)
{
	put_horizontal_line(x_data, colour, 1);
	put_horizontal_line(x_data, colour, 2);
	put_vertical_line(x_data, colour, 1);
	put_vertical_line(x_data, colour, 2);
}

void shift_rectangle(t_data *x_data, int colour, bool right, bool up, int times, int sep)
{
	while (times > 0)
	{
		if (right == true)
		{
			x_data->x[0] -= sep;
			x_data->x[1] -= sep;
		}
		else
		{
			x_data->x[0] += sep;
			x_data->x[1] += sep;
		}
		if (up == true)
		{
			x_data->y[0] -= sep;
			x_data->y[1] -= sep;
		}
		else
		{
			x_data->y[0] += sep;
			x_data->y[1] += sep;
		}
		put_rectangle(x_data, colour);
		times--;
	}
}

void init_x(t_data *x_data, int x1, int x2)
{
	x_data->x[0] = x1;
	x_data->x[1] = x2;
}

void init_y(t_data *x_data, int y1, int y2)
{
	x_data->y[0] = y1;
	x_data->y[1] = y2;
}
