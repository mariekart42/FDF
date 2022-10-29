/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/29 13:11:03 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int main(void)
{
    void *mlx = 0;
    void *mlx_win = 0;
    t_data x;
    
    
    x.mlx = mlx;
    x.mlx_win = mlx_win;

    x.mlx = mlx_init();
	x.mlx_win = mlx_new_window(x.mlx, 1000, 700, "bullshit world!");
    
    init_x(&x, 10, 500);
    init_y(&x, 10, 300);
    put_line(&x, 0xeec900);
    put_cross(&x, 10, 10);
    put_cross(&x, 500, 300);
    mlx_loop(x.mlx);
}