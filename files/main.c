/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/31 19:00:46 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int main(void)
{
    void *mlx = 0;
    void *mlx_win = 0;
    t_data x;
    
    // case 1 (P1[30/HIGHT-30], P2[510/HIGHT-160]) => WORKS
    // case 2 (P1[/], P2[/])
    
    x.mlx = mlx;
    x.mlx_win = mlx_win;

    x.mlx = mlx_init();
	x.mlx_win = mlx_new_window(x.mlx, WIDHT, HIGHT, "bullshit world!");
    
    init_x(&x, 30, 510);
    init_y(&x, HIGHT-30, HIGHT-160);
    
    // put_cross(&x, 10, HIGHT - 10);
    // put_cross(&x, 40, HIGHT - 10);
    // put_cross(&x, 40, HIGHT - 40);
    // put_cross(&x, 500,HIGHT - 300);

    put_cross(&x, 100, HIGHT-100);
    put_cross(&x, 800, HIGHT-150);
    // put_cross(&x, 40, 10);
    // put_cross(&x, 40, 40);
    // put_cross(&x, 650,650);
    
    // put_line(&x, 0xeec900);
    
    mlx_loop(x.mlx);
}