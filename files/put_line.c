/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:40:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/30 18:56:37 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function checks if the first point is below or above the second point
 *  
 * y^ 										y^
 *	| P1 x       							 |           x P2
 *  |            							 |
 *  |           x P2						 | P1 x		
 *  I-------------->x						 I-------------->x
 *   -> y[0] > y[1] 						  -> y[0] < y[1]
 *   -> P1 is ABOVE P2						  -> P1 is BELOW P2
 * => go_factor is -1 cause in 				=> go_factor needs to be +1
 * 	  the bresenham-algo, y always 
 * 	  needs to get substarcted 
 *    by 1 to reach P2
 */
float get_go_factor(t_data *x_data)
{
	if (x_data->y[0] < x_data->y[1])
		return (1);
	else
		return (-1);
}

/*
 * function checks if P1 is always on the right side from P2 (P2 always left side)
 * if that's not the case, the two points swap positions
 */
void init_koordinates(t_data *x_data)
{
	int32_t	swap_variable;

	if (x_data->x[0] > x_data->x[1])
	{
		swap_variable = x_data->x[0];
		x_data->x[0] = x_data->x[1];
		x_data->x[1] = swap_variable;
		swap_variable = x_data->y[0];
		x_data->y[0] = x_data->y[1];
		x_data->y[1] = swap_variable;
	}
}

/*
 * function returns the x_value that is either fast[0] or slow[0]
 */
float find_x(t_data *x_data)
{
	if (x_data->slow[1] == 120)
		return (x_data->slow[0]);
	else
		return (x_data->fast[0]);
}

/*
 * function returns the y_value that is either fast[0] or slow[0]
 */
float find_y(t_data *x_data)
{
	if (x_data->slow[1] == 121)
		return (x_data->slow[0]);
	else
		return (x_data->fast[0]);
}

/*
 * function returns 'true' if the given x and y values
 * are identical with the second Point (end-point)
 * reutrns false if not
 */
bool reached_second_point(t_data *x_data)
{
	if (find_x(x_data) == x_data->x[1] && find_y(x_data) == x_data->y[1])
		return (true);
	else
		return (false);
}

/*
 * fast and slow direction:
 * - fast direction means, that the distance between 
 *   eg. x1 - x0 is bigger then y1 - y0
 * 
 * y ^							(x2/y2)
 * 	 |							x P2
 * 	 |   						.
 * 	 | (x1/y1)					.
 * 	 |   P1 x . . . . . . . . . .
 * 	 I------------------------------>
 * 									x
 * => while we alwyas need to make a step in the fast direction, 
 * 	  making a step to the slow direction is not always needed
 * fast/slow[0] is the content of the 'fast' or 'slow' direction (either x or y)
 * fast/slow[1] is either 120 for 'x' or 121 for 'y'
 */
void init_direction_speed(t_data *x_data)
{
	int32_t tmp_x;
	int32_t tmp_y;
	
	// init difference of both Points to tmp, 
	// if val is negative -> make pos 
	// (cause comparing diferences only works with pos numbers)
	tmp_x = x_data->x[1] - x_data->x[0];
	tmp_y = x_data->y[1] - x_data->y[0];
	if (tmp_x < 0)
		tmp_x *= -1;
	if (tmp_y < 0)
		tmp_y *= -1;
	
	// means x is the fast direction and y the slow one or they're both the same
	if (tmp_x >= tmp_y)
	{
		x_data->slow[0] = x_data->y[0];
		x_data->slow[1] = 121;
		x_data->fast[0] = x_data->x[0];
		x_data->fast[1] = 120;
	}
	else // else y is the fast direction and x slow
	{
		x_data->slow[0] = x_data->x[0];
		x_data->slow[1] = 120;
		x_data->fast[0] = x_data->y[0];
		x_data->fast[1] = 121;
	}
}

/*
 * go_factor:	
 * - is +1 if P1 is below P2, is -1 if P1 is above P2
 *	(check out get_go_factor() for more information)
 *
 * fast and slow direction:
 * - fast/slow[0] is the content of the 'fast' or 'slow' direction (either x or y)
 * - fast/slow[1] is either 120 for 'x' or 121 for 'y'
 *   (check out init_direction_speed() for more information)
 * 			
 */
void bresenham_algo(t_data *x_data, int32_t colour)
{
	float	go_factor;// eigentlich int aber villeicht nen problem beim rechnen later
	float	diff;
	float tmp_diff;

	init_koordinates(x_data);
	init_direction_speed(x_data);
	go_factor = get_go_factor(x_data);
	diff = find_x(x_data) / 2;
	tmp_diff = 0;
	
	int i = 300;
	// error here in while loop -> reached_second_point never turns true
	while (i > 0)//reached_second_point(x_data) == false)
	{
		// printf("in while loop\n");
		x_data->fast[0]++;
		// always if the difference is below 0, i calculate the new difference 
		// and slow direction gets substracted/additioned(go_factor) by one 
		printf("find x: %f\n", find_x(x_data));
		printf("diff: %f\n", diff);
		printf("dif - find x: %f\n\n", diff - find_x(x_data));
		if ((diff - x_data->y[1]) < 0)
		{
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, find_x(x_data), find_y(x_data), colour);
			x_data->slow[0] += go_factor;
			tmp_diff = diff + x_data->x[1];
			diff = tmp_diff;
			tmp_diff = 0;
		}
		i--;
	}
	mlx_pixel_put(x_data->mlx, x_data->mlx_win, find_x(x_data), find_y(x_data), colour);
}

// explaination different if-statements:
// 1. if bot dots are exactly the same -> just put the one pixel
// 2. if both dots have the same x-val -> its just a vertical line
// 3. if both dots have the same y-val -> its just a horizontal line
// 4. else we need to put the line with the bresenham algo
void put_line(t_data *x_data, int32_t colour)
{
	if (x_data->x[0] == x_data->x[1] && x_data->y[0] == x_data->y[1])
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[0], x_data->y[0], colour);
	else if (x_data->x[0] == x_data->x[1])
		put_vertical_line(x_data, colour);
	else if (x_data->y[0] == x_data->y[1])
		put_horizontal_line(x_data, colour);
	else
	{
		bresenham_algo(x_data, colour);

	}

}
