/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:40:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/18 15:02:12 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function checks if P1 is always on the right side from P2 (P2 always left side)
 * if that's not the case, the two points swap positions
 */
void check_koordinates(t_data *data)
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

/*
 * - if i need the value of the second x (of P2), 
 *   string needs to be "x2"
 * - function returns the x_value that is either fast[0] or slow[0]
 */
double find_x(t_data *data, char *y1_or_y2)
{
	if (ft_strncmp(y1_or_y2, "x2", 2) == 0)
		return (data->x[1]);
	else if (data->slow[1] == 120)
		return (data->slow[0]);
	else
		return (data->fast[0]);
}

/*
 * - if i need the value of the second y (of P2), 
 *   string needs to be "y2"
 * - function returns the y_value that is either fast[0] or slow[0]
 */
double find_y(t_data *data, char *y1_or_y2)
{
	if (ft_strncmp(y1_or_y2, "y2", 2) == 0)
		return (data->y[1]);
	else if (data->slow[1] == 121)
		return (data->slow[0]);
	else
		return (data->fast[0]);
}

/*
 * function returns 'true' if the given x and y values
 * are identical with the second Point (end-point)
 * reutrns false if not
 */
bool reached_second_point(t_data *data)
{
	if (find_x(data, "x1") == data->x[1] && find_y(data, "y1") == data->y[1])
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
void init_direction_speed(t_data *data)
{
	double tmp_x;
	double tmp_y;
	
	// init difference of both Points to tmp, 
	// if val is negative -> make pos 
	// (cause comparing diferences only works with pos numbers)
	tmp_x = data->x[1] - data->x[0];
	tmp_y = data->y[1] - data->y[0];
	if (tmp_x < 0)
		tmp_x *= -1;
	if (tmp_y < 0)
		tmp_y *= -1;
	
	// means x is the fast direction and y the slow one or they're both the same
	if (tmp_x >= tmp_y)
	{
		data->slow[0] = data->y[0];
		data->slow[1] = 121;
		data->fast[0] = data->x[0];
		data->fast[1] = 120;
	}
	else // else y is the fast direction and x slow
	{
		data->slow[0] = data->x[0];
		data->slow[1] = 120;
		data->fast[0] = data->y[0];
		data->fast[1] = 121;
	}
}

/*
 * function checks first if the slow direction is x, if yes the slow_factor is alway +1
 *		but if the slow direction is y, it could either be -1 or +1
 *		then function checks if the first point is below or above the second point
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
double get_slow_factor(t_data *data)
{
	if (data->slow[1] == 120)
		return (1);
	else if (data->slow[1] == 121 && data->y[0] > data->y[1])
		return (-1);
	// case 3
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
double get_fast_factor(t_data *data)
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
 * function calculates the disctance between the current coordinate and 
 * either:    the point on the line with the same y-value (y = mx+b)
 * 		   or the point on the line with the same x-value (x = [y-b]/m)
 * 	=>	depends on the gradient and the fast/slow-direction of the line (4 cases)
 * CASE 1: 					   |  CASE 2:
 * - negative gradient		   |  - negative gradient
 * - fast direction = x	       |  - fast_direction = y
 *   y						   |	y 
 *  0_^ 					   |   0_^			x P2
 *	1_|      		 		   |   1_|           
 *  2_|              x P2	   |   2_|
 *  3_| P1 x            	   |   3_|   P1 x		
 *  4_I-------------->x		   |   4_I-------------->x
 *    0 1 2 3 4 5 6 7 		   |	 0 1 2 3 4 5 6 7
 * 	    => y = mx+b			   |	   => x = [y-b]/m
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - -
 * CASE 3:					   |  CASE 4:
 * - positive gradient		   |  - positive gradient
 * - fast direction = x		   |  - fast direction = y 
 *   y						   |    y 
 *  0_^ 					   |  0_^   P2 x		
 *	1_|        				   |  1_|           
 *  2_| P1 x            	   |  2_|
 *  3_|              x P2	   |  3_|   		x P1
 *  4_I-------------->x		   |  4_I-------------->x
 *    0 1 2 3 4 5 6 7 		   |    0 1 2 3 4 5 6 7
 * 		=> x = [y-b]/m		   | 	  => y = mx+b	
 */
double distance_to_line(t_data *data, double slow_factor, double fast_factor)
{
	// if case 1 or 4
	if ((data->slow[1] == 121 && slow_factor == -1 && fast_factor == 1) \
		|| (data->slow[1] == 120 && slow_factor == 1 && fast_factor == 1))
		return (find_y(data, "y1") - (m(data, 1) * find_x(data, "x1") + b(data, 1)));

	// if case 3
	if (data->slow[1] == 121 && slow_factor == 1 && fast_factor == 1)
	{
		return ((HIGHT-find_y(data, "y1")) - (m(data, 3) * find_x(data, "x1") + b(data, 3)));
	}
	// if case 2
	if (data->slow[1] == 120 && slow_factor == 1 && fast_factor == -1)
	{
		return (((HIGHT - find_y(data, "y1") + b(data, 2)) / m(data, 2)) - find_x(data, "x1"));
	}
	else
		error_msg("failed to execute distance_to_line\n");
		return (0);
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
 */
void bresenham_algo(t_data *data)
{
	double	slow_factor;
	double	fast_factor;

	check_koordinates(data);
	init_direction_speed(data);
	slow_factor = get_slow_factor(data);
	fast_factor = get_fast_factor(data);
	while (reached_second_point(data) == false)
	{
		data->fast[0] += fast_factor;

		// if statement asks if the differnce between the last y value and the y value
		// on the actual line is bigger then 0.5
		if (distance_to_line(data, slow_factor, fast_factor) > 0.5)
		{
			data->slow[0] += slow_factor;
		}
		mlx_pixel_put(data->mlx, data->mlx_win, find_x(data, "x1"), find_y(data, "y1"), data->colour);
	}
}
	
// explaination different if-statements:
// 1. if bot dots are exactly the same -> just put the one pixel
// 2. if both dots have the same x-val -> its just a vertical line
// 3. if both dots have the same y-val -> its just a horizontal line
// 4. else we need to put the line with the bresenham algo
void put_line(t_data *data)
{
	// update following 3 functions for colour in struct now
	if (data->x[0] == data->x[1] && data->y[0] == data->y[1])
		mlx_pixel_put(data->mlx, data->mlx_win, data->x[0], data->y[0], data->colour);
	else if (data->x[0] == data->x[1])
		put_vertical_line(data);
	else if (data->y[0] == data->y[1])
		put_horizontal_line(data);
	else
		bresenham_algo(data);
}

