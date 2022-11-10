/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:08:14 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/10 18:01:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

float isometric(float x, float y, int32_t z, char x_or_y)
{
    float previous_x;
    float previous_y;

    previous_x = x;
    previous_y =y;


    x = (previous_x - previous_y) * cos(0.46373398);
    y = -z + (previous_x + previous_y) * sin(0.46373398);
	if (x_or_y == 'x')
		return (x);
	return (y);
		
}


// // init current and next x and y values
// // in data x and y there needs to be the correct calculared values(with angle)
// void init_coords(t_data *fdf, t_data *data)
// {	
// 	// always previouse coordinates
// 	data->x[0] = data->x[1];
// 	data->y[0] = data->y[1];
	
// 	data->x[1] = 
// 	data->y[1] =
// }

// void first_line(t_fdf *fdf, t_data *data)
// {
// 	data->x[0] = START_POINT;
// 	data->y[0] = START_POINT;
// 	data->x[1] = START_POINT;
	
// 	data->y[1] = isometric(START_POINT, LINE_LEN, fdf->matrix[0][1], 'y');
// }

void draw_map(t_data *data, t_fdf *fdf)
{
	// int32_t i = 0;
	// int32_t line = 0;
	// int32_t col = 0;
	
	// first_line(fdf, data);
	// put_line(data);
	data->x[0] = START_POINT;
	data->y[0] = START_POINT;

// display tile
	
	init_put_line(START_POINT, isometric(1+LINE_LEN, 1+LINE_LEN, fdf->matrix[0][1], 'x'), START_POINT, START_POINT);
	put_line(data);
	
	init_put_line(START_POINT, START_POINT, START_POINT, isometric(1+LINE_LEN, 1+LINE_LEN, fdf->matrix[0][1], 'x'));
	put_line(data);




	// while (fdf->matrix[line] != NULL)
	// {
	// 	while (fdf->matrix[line][col] != '\0')
	// 	{
	// 		init_coords(fdf, data);
	// 		put_line(data);
	// 		col++;
	// 	}
	// 	col = 0;
	// 	line++;
	// }
}