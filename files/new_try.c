/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_try.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:20:45 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/16 19:29:49 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function calculates the next point where the tile needs to be
 * is the coordinate for the crossing point of the two lines
 */
float get_point(float prev_x, float prev_y, char *x_or_y)
{
	if (ft_strncmp(x_or_y, "x", 1) == 0)
		return (START_POINT_X + prev_x * (TILE_WIDHT / 2) - prev_y * (TILE_WIDHT / 2));
	else
		return (START_POINT_Y + prev_x * (TILE_HIGHT / 2) + prev_y * (TILE_HIGHT / 2));
}

/*
 * function recieves coordinates where to draw the next 'half' tile
 * 				.
 *			.
 *		.
 *	x  <---- needs this point to draw the two tile lines
 *		.
 *			.
 *				.
 */
void draw_tile(t_data *data, float x1, float y1)
{
	// calculate x2/y2 and x3/y3 here
	float x[3];
	float y[3];

	x[0] = get_point(x1, y1, "x");
	y[0] = get_point(x1, y1, "y");
	
	x[1] = get_point(x1 + 1, y1, "x");
	y[1] = get_point(x1 + 1, y1, "y");

	x[2] = get_point(x1, y1 + 1, "x"); 
	y[2] = get_point(x1, y1 + 1, "y"); 

	// x2 = (x1 * LINE_LEN) + START_POINT_X;
	// y2 = ((x1 * LINE_LEN) * ANGLE) + START_POINT_Y;
	
	// x3 = x2;
	// y3 = ((x1 * LINE_LEN) * (-1 * ANGLE)) + START_POINT_Y;

	// positive line
	init_x(data, x[0], x[1]);
	init_y(data, y[0], y[1]);
	put_line(data);
	
	// negative line
	init_x(data, x[0], x[2]);
	init_y(data, y[0], y[2]);
	put_line(data);
	
}