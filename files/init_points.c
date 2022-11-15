/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:05:13 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/15 13:54:36 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

void init_current_point(t_fdf *fdf, int32_t x, int32_t y, int32_t z)
{
	fdf->curr_point[0] = x + LINE_LEN + START_POINT_X;
	fdf->curr_point[1] = ((y + LINE_LEN) * ANGLE) + START_POINT_Y;
	fdf->curr_point[2] = z;
}

void init_lower_point(t_fdf *fdf, int32_t x, int32_t y, int32_t z)
{
	fdf->lower_point[0] = x + LINE_LEN + START_POINT_X;
	fdf->lower_point[1] = ((y + LINE_LEN) * (ANGLE * (-1))) + START_POINT_Y;
	fdf->lower_point[2] = z;
}

void init_next_right_point(t_fdf *fdf, int32_t x, int32_t y, int32_t z)
{
	fdf->right_point[0] = x + LINE_LEN + START_POINT_X;
	fdf->right_point[1] = ((y + LINE_LEN) * ANGLE) + START_POINT_Y;
	fdf->right_point[2] = z;
}

void init_points(t_fdf *fdf, t_data *data)
{
	// int32_t i = 0;
	// int32_t k = 0;

	// while (fdf->matrix[i] != NULL)
	// {
	// 	while (fdf->matrix[i][k] != '\0')
	// 	{
	// 		init_current_point(fdf, i, k, fdf->matrix[i][k]);
	// 		init_next_right_point(fdf, i, k+1, fdf->matrix[i][k+1]);
			
	// 		// very last line of the map
	// 		if (fdf->matrix[i+1] == NULL)
	// 		{
	// 			// here func that only prints right side line
	// 			draw_lines(fdf, data, true, false);
	// 		}
	// 		else
	// 		{
	// 			init_lower_point(fdf, i+1, k, fdf->matrix[i+1][k]);
	// 			// here func that prints out both lines
	// 			draw_lines(fdf, data, true, true);
	// 		}
	// 		k++;
	// 	}
	// 	k = 0;
	// 	i++;
	// }
	draw_lines(fdf, data, true, true);
}