/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:17:02 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/06 19:35:39 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function calculates the gradient m (y = [m]x+b)
 * 			y2 - y1
 * 		m = -------
 * 			x2 - x1
 */
float m(t_data *x_data, int case_)
{
	float m;
	
	m = (x_data->y[1] - x_data->y[0]) / (x_data->x[1] - x_data->x[0]);
	if (case_ == 2 && m < 0)
		m *= -1;
	// if (case_ == 3 && m > 0)
	// 	m *= -1;
	return (m);
}

/*
 * function calculates the y-intercept b (y = mx+[b])
 * 		b = m * x1 - y1
 *  or  b = m * x2 - y1
 * (i always take x2 and y2 cause they don't change during the algo)
 */
float b(t_data *x_data, int case_)
{
	float b;
	// float m_;
	
	if (case_ == 1 || case_ == 4)
	{
		b = m(x_data, 1) * x_data->x[1] - x_data->y[1];
		return (b * (-1));
	}
	else if (case_ == 3)
	{
		// m_ = m(x_data, 1);
		// if (m_ > 0)
		// 	m_ *= -1;
		b = m(x_data, 3) * x_data->x[1] - (HIGHT - x_data->y[1]);
		return (b);
	}
	else 
	{
		b = m(x_data, 2) * x_data->x[1] - (HIGHT - x_data->y[1]);
		if (b<0)
			b*=-1;
		return (b);
	}
}
