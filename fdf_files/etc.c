/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:33:14 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/21 19:43:55 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

void	put_horizontal_line(t_data *data)
{
	int	x1;

	x1 = data->x[0];
	if (x1 <= data->x[1])
	{
		while (x1 <= data->x[1])
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x1, data->y[0], \
				data->colour);
			x1++;
		}
	}
	else
	{
		while (x1 >= data->x[1])
		{
			mlx_pixel_put(data->mlx, data->mlx_win, x1, data->y[0], \
				data->colour);
			x1--;
		}
	}
}

void	put_vertical_line(t_data *data)
{
	int	y1;

	y1 = data->y[0];
	if (y1 <= data->y[1])
	{
		while (y1 <= data->y[1])
		{
			mlx_pixel_put(data->mlx, data->mlx_win, data->x[0], y1, \
				data->colour);
			y1++;
		}
	}
	else
	{
		while (y1 >= data->y[1])
		{
			mlx_pixel_put(data->mlx, data->mlx_win, data->x[0], y1, \
				data->colour);
			y1--;
		}
	}
}

void	init_x(t_data *data, int x1, int x2)
{
	data->x[0] = x1;
	data->x[1] = x2;
}

void	init_y(t_data *data, int y1, int y2)
{
	data->y[0] = y1;
	data->y[1] = y2;
}
