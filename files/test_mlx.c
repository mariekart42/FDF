/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:33:14 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/30 16:09:34 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"
#include "../mlx/mlx.h"

void put_horizontal_line(t_data *x_data, int colour)
{
	int x1 = x_data->x[0];
	
	if (x1 <= x_data->x[1])
	{
		while (x1 <= x_data->x[1])
		{
			mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[0], colour);
			x1++;
		}
	}
	else
	{
		while (x1 >= x_data->x[1])
		{
			mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[0], colour);
			x1--;
		}
	}
}

void put_vertical_line(t_data *x_data, int colour)
{
	int y1 = x_data->y[0];
	if (y1 <= x_data->y[1])
	{
		while (y1 <= x_data->y[1])
		{
			mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[0], y1, colour);
			y1++;
		}
	}
	else
	{
		while (y1 >= x_data->y[1])
		{
			mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[0], y1, colour);
			y1--;
		}
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
