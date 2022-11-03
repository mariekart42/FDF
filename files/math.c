/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:17:02 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/03 18:24:01 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function calculates the gradient m (y = [m]x+b)
 * 			y2 - y1
 * 		m = -------
 * 			x2 - x1
 */
float m(t_data *x_data)
{
	float m;
	

	m = (x_data->y[1] - x_data->y[0]) / (x_data->x[1] - x_data->x[0]);
	
	if (m < 0)
		m *= -1;
	return (m);
}

/*
 * function calculates the y-intercept b (y = mx+[b])
 * 		b = m * x1 - y1
 *  or  b = m * x2 - y1
 * (i always take x2 and y2 cause they don't change during the algo)
 */
float b(t_data *x_data)
{
	float b;

	b = m(x_data) * x_data->x[1] - (HIGHT - x_data->y[1]); //origninal
	if(b<0)
		b*=-1;
	return (b);
}
