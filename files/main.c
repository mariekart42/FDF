/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/31 19:33:11 by mmensing         ###   ########.fr       */
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
    

    // CASE 1 (x fast, P1 below P2) => WORKS
    // put_cross(&x, 300, HIGHT-100);
    // put_cross(&x, 800, HIGHT-300);
    //     init_x(&x, 300, 800);
    //     init_y(&x, HIGHT-100, HIGHT-300);
    
    
    // CASE 2 (y fast, P1 below P2) => not working
    // put_cross(&x, 400, HIGHT-100);
    // put_cross(&x, 600, HIGHT-500);
    //     init_x(&x, 400, 600);
    //     init_y(&x, HIGHT-100, HIGHT-500);
    

    // CASE 3 (x fast, P1 above P2) => not working
    // put_cross(&x, 300, HIGHT-300);
    // put_cross(&x, 800, HIGHT-100);
    //     init_x(&x, 300, 800);
    //     init_y(&x, HIGHT-300, HIGHT-100);
    
    
    // CASE 4 (y fast, P1 above P2) => WORKS
    put_cross(&x, 400, HIGHT-500);
    put_cross(&x, 600, HIGHT-100);
        init_x(&x, 400, 600);
        init_y(&x, HIGHT-500, HIGHT-100);
    

    
    put_line(&x, 0xeec900);
    
    mlx_loop(x.mlx);
}