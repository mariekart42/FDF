/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:07:31 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/18 10:43:05 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function calculates the next point where the tile needs to be
 * is the coordinate for the crossing point of the two lines
 */
float get_point(float prev_x, float prev_y, int32_t prev_z, char *x_or_y)
{
	if (ft_strncmp(x_or_y, "x", 1) == 0)
		return (START_POINT_X + prev_x * (TILE_WIDHT/ LINE_LEN) - prev_y * (TILE_WIDHT / LINE_LEN));
	else
		return ((START_POINT_Y + prev_x * (TILE_HIGHT/ LINE_LEN) + prev_y * (TILE_HIGHT / LINE_LEN))-prev_z);
}

/*
 * function recieves coordinates where to draw the next two tile lines
 * 				.
 *			.
 *		.
 *	x  <---- needs this point to draw the two tile lines
 *		.
 *			.
 *				.
 */
void draw_tile(t_data *data, float x1, float y1, int32_t *z)
{	
	float x[3];
	float y[3];

	x[0] = get_point(x1, y1, z[0], "x");
	y[0] = get_point(x1, y1, z[0], "y");
	
	x[1] = get_point(x1 + 1, y1, z[1], "x");
	y[1] = get_point(x1 + 1, y1, z[1], "y");

	x[2] = get_point(x1, y1 + 1, z[2], "x"); 
	y[2] = get_point(x1, y1 + 1, z[2], "y"); 

	// positive line
	init_x(data, x[0], x[1]);
	init_y(data, y[0], y[1]);
	put_line(data);
	
	// negative line
	init_x(data, x[0], x[2]);
	init_y(data, y[0], y[2]);
	put_line(data);
}

void draw_map(t_fdf *fdf, t_data *data)
{
	int32_t x = 0;
	int32_t y = 0;
	int32_t z[3];
	
	while (fdf->linecount_map > y+1)
	{
		while (fdf->wordcount_map > x+1)
		{
			z[0] = fdf->matrix[y][x];
			z[1] = fdf->matrix[y][x+1];
			z[2] = fdf->matrix[y+1][x];
			// if (z[0] > 99)
			// 	data->colour = 0xff0000;
			// else
				data->colour = 0xfffafa;

			draw_tile(data, x, y, z);
			x++;
		}
		x = 0;
		y++;
	}
}