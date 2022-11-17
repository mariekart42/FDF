/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:07:31 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/17 18:21:57 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

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