/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:40:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/31 17:21:20 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"
#include "../libft/libft.h"


// float get_go_factor(t_data *x_data)
// {
// 	if (x_data->y[0] > x_data->y[1])
// 		return (-1);
// 	else
// 		return (1);
// }

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
 * - if i need the value of the second x (of P2), 
 *   string needs to be "x2"
 * - function returns the x_value that is either fast[0] or slow[0]
 */
float find_x(t_data *x_data, char *y1_or_y2)
{
	if (ft_strncmp(y1_or_y2, "x2", 2) == 0)
		return (x_data->x[1]);
	else if (x_data->slow[1] == 120)
		return (x_data->slow[0]);
	else
		return (x_data->fast[0]);
}

/*
 * - if i need the value of the second y (of P2), 
 *   string needs to be "y2"
 * - function returns the y_value that is either fast[0] or slow[0]
 */
float find_y(t_data *x_data, char *y1_or_y2)
{
	if (ft_strncmp(y1_or_y2, "y2", 2) == 0)
		return (x_data->y[1]);
	else if (x_data->slow[1] == 121)
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
	if (find_x(x_data, "x1") == x_data->x[1] && find_y(x_data, "y1") == x_data->y[1])
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
	float tmp_x;
	float tmp_y;
	
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
		printf("direction_speed: x\n");
		x_data->slow[0] = x_data->y[0];
		x_data->slow[1] = 121;
		x_data->fast[0] = x_data->x[0];
		x_data->fast[1] = 120;
	}
	else // else y is the fast direction and x slow
	{
		printf("direction_speed: y\n");
		x_data->slow[0] = x_data->x[0];
		x_data->slow[1] = 120;
		x_data->fast[0] = x_data->y[0];
		x_data->fast[1] = 121;
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
float get_slow_factor(t_data *x_data)
{
	if (x_data->slow[1] == 120)
		return (1);
	else if (x_data->slow[1] == 121 && x_data->y[0] > x_data->y[1])
		return (-1);
	else if (x_data->slow[1] == 121 && x_data->y[0] < x_data->y[1])
		return (1);
	else
		error_msg("not able to access slow_factor ---> exit here\n");
	exit(EXIT_FAILURE);
}

/*
 * same as get_slow_fatcor() but for the fast factor
 * check out get_slow_factor() for more information
 */
float get_fast_factor(t_data *x_data)
{
	if (x_data->fast[1] == 120)
		return (1);
	else if (x_data->fast[1] == 121 && x_data->y[0] > x_data->y[1])
		return (-1);
	else if (x_data->fast[1] == 121 && x_data->y[0] < x_data->y[1])
		return (1);
	else
		error_msg("not able to access fast_factor ---> exit here\n");
	exit(EXIT_FAILURE);
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
	float	slow_factor;// eigentlich int aber villeicht nen problem beim rechnen later
	float	fast_factor;
	float	diff;

	init_koordinates(x_data);
	init_direction_speed(x_data);
	slow_factor = get_slow_factor(x_data);
	fast_factor = get_fast_factor(x_data);
	diff = find_x(x_data, "x2") / 2;
	mlx_pixel_put(x_data->mlx, x_data->mlx_win, find_x(x_data, "x1"), find_y(x_data, "y1"), colour);
	
	int i = 100;
	// error here in while loop -> reached_second_point never turns true
	while (i > 0)//reached_second_point(x_data) == false)
	{
		x_data->fast[0] += fast_factor;
		// if statement asks if the differnce between the last y value and the y value
		// on the actual line is smoler then 0.5
		printf("m = %f\nx[1] = %f\nb = %f\n\n", m(x_data), x_data->x[1], b(x_data));
		printf("");
		if ( (m(x_data) * x_data->x[1] + b(x_data)) - ( find_y(x_data, "y1")  ) < 0.5 )
		{
			printf("i'm in\n");
			x_data->slow[0] += slow_factor;
			mlx_pixel_put(x_data->mlx, x_data->mlx_win, find_x(x_data, "x1"), find_y(x_data, "y1"), colour);
		}
		i--;
	}
	mlx_pixel_put(x_data->mlx, x_data->mlx_win, find_x(x_data, "x1"), find_y(x_data, "y1"), colour);
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
printf("done\n");
return ;
}
