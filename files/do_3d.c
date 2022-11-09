/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:36:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/09 18:53:49 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

void isometric(float x, float y, int32_t z)
{
    float previous_x;
    float previous_y;

    previous_x = x;
    previous_y =y;


    x = (previous_x - previous_y) cos(0.46373398);
    y = -z + (previous_x + previous_y) sin(0.46373398);
}