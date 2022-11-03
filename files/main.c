/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/03 18:29:13 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int main(void)
{
    printf(YEL"\n>------- start -------\n"RESET);
    void *mlx = 0;
    void *mlx_win = 0;
    t_data x;
    
    x.mlx = mlx;
    x.mlx_win = mlx_win;

    x.mlx = mlx_init();
	x.mlx_win = mlx_new_window(x.mlx, WIDHT, HIGHT, "bullshit world!");
    

    // CASE 1 (x fast, P1 below P2) => WORKS
    // int x1=100;  int y1=HIGHT-100;
    // int x2=800;  int y2=HIGHT-300;
    
    
    // CASE 2 (y fast, P1 below P2) => not working
    int x1=200; int y1=HIGHT-100;
    int x2=500; int y2=HIGHT-500;
// is working now make some if statements when to use it

    // CASE 3 (x fast, P1 above P2) => not working
    // int x1=300; int y1=HIGHT-300;
    // int x2=800; int y2=HIGHT-100;

    
    // CASE 4 (y fast, P1 above P2) => WORKS
    // int x1=100; int y1=HIGHT-500;
    // int x2=300; int y2=HIGHT-100;

    
    put_cross(&x, x1, y1);
    put_cross(&x, x2, y2);
    
    init_x(&x, x1, x2);
    init_y(&x, y1, y2);

    put_line(&x, 0xeec900);
    
    mlx_loop(x.mlx);
}