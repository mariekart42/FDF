/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:40:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/29 13:55:32 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

void init_slow_fast(t_data *x_data)
{

}

// logic from bresenham algorithm
void put_line(t_data *x_data, int colour)
{
	float	var;
	float	tmp_var;

	if (x_data->x[0] == x_data->x[1] && x_data->y[0] == x_data->y[1])
		error_msg("error in 'put_line' ----> two koordinates have the same value\n");
	init_slow_fast(x_data);
	while (fast != x_data->x[1] && tmp_y != x_data->y[1])
	{
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, tmp_x, tmp_y, colour);
		tmp_x++;
		if ((var - x_data->x[0]) < 0)
		{
			tmp_y++;
			tmp_var = var - x_data->y[0];
			var = tmp_var;
			tmp_var = 0;
		}
	}
	mlx_pixel_put(x_data->mlx, x_data->mlx_win, tmp_x, tmp_y, colour);
	

}