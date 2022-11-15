/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:07:31 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/15 13:28:12 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

void draw_lines(t_fdf *fdf, t_data *data, bool right, bool down)
{
	if (right == true && down == true)
	{
		put_cross(data, fdf->curr_point[0], fdf->curr_point[1]);
		put_cross(data, fdf->right_point[0], fdf->right_point[1]);
		put_cross(data, fdf->lower_point[0], fdf->lower_point[1]);
		
	}
}