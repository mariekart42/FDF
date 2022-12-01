/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:40:16 by mmensing          #+#    #+#             */
/*   Updated: 2022/12/01 17:09:48 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * go_factor:	
 * - is +1 if P1 is below P2, is -1 if P1 is above P2
 *	(check out get_go_factor() for more information)
 *
 * fast and slow direction:
 * - fast/slow[0] is the content of the 'fast' or 'slow' direction 
 * 		(either x or y)
 * - fast/slow[1] is either 120 for 'x' or 121 for 'y'
 *   (check out init_direction_speed() for more information)	
 */
void	line_algo(t_data *data)
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
		if (distance_to_line(data, slow_factor, fast_factor) > 0.5)
			data->slow[0] += slow_factor;
		mlx_pixel_put(data->mlx, data->mlx_win, find_x(data, "x1"), \
						find_y(data, "y1"), data->colour);
	}
}

// explaination different if-statements:
// 1. if bot dots are exactly the same -> just put the one pixel
// 2. if both dots have the same x-val -> its just a vertical line
// 3. if both dots have the same y-val -> its just a horizontal line
// 4. else we need to put the line with the line algo
void	put_line(t_data *data)
{
	if (data->x[0] == data->x[1] && data->y[0] == data->y[1])
		mlx_pixel_put(data->mlx, data->mlx_win, data->x[0], \
					data->y[0], data->colour);
	else if (data->x[0] == data->x[1])
		put_vertical_line(data);
	else if (data->y[0] == data->y[1])
		put_horizontal_line(data);
	else
		line_algo(data);
}
