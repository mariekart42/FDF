/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/17 18:17:26 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int main(int argc, char *argv[])
{
    t_data  data;
    t_fdf   fdf;
    if (argc != 2)
        error_msg("input args incorrect! --> usage:  ./exec <map>\n");
    
    printf(YEL"\n>------- start -------\n\n\n"RESET);

    data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDHT, HIGHT, "bullshit world!");

    data.cross_colour = 0xff6347;

    data.colour = 0x708090; //grey
    data.colour = 0xffefd5;
    
    fdf.argv_map = argv[1];

    put_cross(&data, START_POINT_X, START_POINT_Y);
    init_matrix(&fdf);
    
    draw_map(&fdf, &data);    

    // data.colour = 0xffffff;
    // int32_t z[3];
    // z[0] = 0;   // current point
    // z[1] = 0;  // x_axe point(right one)
    // z[2] = 0;   // y_axe point(left one)
    // draw_tile(&data, 0, 0, z);
        
    // data.colour = 0x708090; //grey
    // z[0] = 0;
    // z[1] = 0;
    // z[2] = 0;
    // draw_tile(&data, 1, 0, z);
    
    // data.colour = 0x708090; //grey
    // z[0] = 0;
    // z[1] = 0;
    // z[2] = 0;
    // draw_tile(&data, 2, 0, z);

    mlx_loop(data.mlx);
}



    // ---------------------------------------
    // nice pic lol
    // int i = 1;
    // while (i < 500)
    // {
    //     isometric(&data, 100, 900, i*(-10));
    // i++;
    // }
    // ---------------------------------------
    
    // // for testing put_line for all cases:
    // ---------------------------------------
    // // CASE 1 (x fast, P1 below P2) => WORKS
    // // int x1=100;  int y1=HIGHT-100;
    // // int x2=800;  int y2=HIGHT-300;
    // // CASE 2 (y fast, P1 below P2) => WORKS
    // // int x1=200; int y1=HIGHT-100;
    // // int x2=500; int y2=HIGHT-500;
    // // CASE 3 (x fast, P1 above P2) => WORKS
    // int x1=110; int y1=HIGHT-400;
    // int x2=500; int y2=HIGHT-300;
    // // CASE 4 (y fast, P1 above P2) => WORKS
    // // int x1=100; int y1=HIGHT-500;
    // // int x2=300; int y2=HIGHT-100;
    // int x1=12; int y1=HIGHT-80;
    // int x2=991; int y2=HIGHT-41;
    // put_cross(&data, x1, y1);
    // put_cross(&data, x2, y2);
    // init_x(&data, x1, x2);
    // init_y(&data, y1, y2);
    // ---------------------------------------