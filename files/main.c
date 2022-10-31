/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/31 17:01:45 by mmensing         ###   ########.fr       */
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
	x.mlx_win = mlx_new_window(x.mlx, WIDHT, HIGHT, "bullshit world!");
    
    init_x(&x, 30, 110);
    init_y(&x, HIGHT-30, HIGHT-60);
    
    // put_cross(&x, 10, HIGHT - 10);
    // put_cross(&x, 40, HIGHT - 10);
    // put_cross(&x, 40, HIGHT - 40);
    // put_cross(&x, 500,HIGHT - 300);

    put_cross(&x, 30, HIGHT-30);
    put_cross(&x, 110, HIGHT-60);
    // put_cross(&x, 40, 10);
    // put_cross(&x, 40, 40);
    // put_cross(&x, 650,650);
    
    put_line(&x, 0xeec900);
    
    mlx_loop(x.mlx);
}