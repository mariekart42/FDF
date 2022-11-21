/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_factors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:23:46 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/21 19:46:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 *	function checks first if the slow direction is x, if yes the slow_factor is
 *	alway +1 but if the slow direction is y, it could either be -1 or +1
 *	then function checks if the first point is below or above the second point
 * MIND: 	in mlx the origin is not with ([x] 0/[y] 0) in the left-down corner
 * 			y0 is in the left-up corner
 * 			x0 is in the left-down corner
 *   y									y 
 *  0_^ 							   0_^
 *	1_| P1 x       					   1_|           x P2
 *  2_|            					   2_|
 *  3_|           x P2				   3_| P1 x		
 *  4_I-------------->x				   4_I-------------->x
 *    0 1 2 3 4 5 6 7 					 0 1 2 3 4 5 6 7
 * 	 
 * -> y[0] < y[1] 						  -> y[0] > y[1]
 *   -> P1 is ABOVE P2						-> P1 is BELOW P2
 * => slow_factor is +1 cause in 		  => slow_factor needs to be -1
 * 	  the bresenham-algo, y always 	     	 always needs to subtract
 * 	  needs to get added 					 one to reach P2
 *    by 1 to reach P2
 */
double	get_slow_factor(t_data *data)
{
	if (data->slow[1] == 120)
		return (1);
	else if (data->slow[1] == 121 && data->y[0] > data->y[1])
		return (-1);
	if (data->slow[1] == 121 && data->y[0] < data->y[1])
		return (1);
	else
		error_msg("not able to access slow_factor ---> exit here\n");
	exit(EXIT_FAILURE);
}

/*
 * same as get_slow_fatcor() but for the fast factor
 * check out get_slow_factor() for more information
 */
double	get_fast_factor(t_data *data)
{
	if (data->fast[1] == 120)
		return (1);
	else if (data->fast[1] == 121 && data->y[0] > data->y[1])
		return (-1);
	else if (data->fast[1] == 121 && data->y[0] < data->y[1])
		return (1);
	else
		error_msg("not able to access fast_factor ---> exit here\n");
	exit(EXIT_FAILURE);
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
void	init_direction_speed(t_data *data)
{
	double	tmp_x;
	double	tmp_y;

	tmp_x = data->x[1] - data->x[0];
	tmp_y = data->y[1] - data->y[0];
	if (tmp_x < 0)
		tmp_x *= -1;
	if (tmp_y < 0)
		tmp_y *= -1;
	if (tmp_x >= tmp_y)
	{
		data->slow[0] = data->y[0];
		data->slow[1] = 121;
		data->fast[0] = data->x[0];
		data->fast[1] = 120;
	}
	else
	{
		data->slow[0] = data->x[0];
		data->slow[1] = 120;
		data->fast[0] = data->y[0];
		data->fast[1] = 121;
	}
}

/*
 * function checks if P1 is always on the right side from P2 
 * (P2 always left side)
 * if that's not the case, the two points swap positions
 */
void	check_koordinates(t_data *data)
{
	int32_t	swap_variable;

	if (data->x[0] > data->x[1])
	{
		swap_variable = data->x[0];
		data->x[0] = data->x[1];
		data->x[1] = swap_variable;
		swap_variable = data->y[0];
		data->y[0] = data->y[1];
		data->y[1] = swap_variable;
	}
}
