/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/16 19:31:42 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int main(int argc, char *argv[])
{
    printf(YEL"\n>------- start -------\n\n\n"RESET);
    
    t_data  data;
    t_fdf   fdf;

    if (argc != 2)
        error_msg("input args incorrect! --> usage:  ./exec <map>\n");

    data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, WIDHT, HIGHT, "bullshit world!");
    
    argc++;

    data.cross_colour = 0xff6347;

    data.colour = 0xffefd5;
    
    fdf.argv_map = argv[1];

    put_cross(&data, 200, 200);
    // init_matrix(&fdf);
    // init_points(&fdf, &data);
    
    data.colour = 0x708090; //grey
    draw_tile(&data, 0, 0);
    data.colour = 0xffffff;
    draw_tile(&data, 0, 1);
    draw_tile(&data, 0, 2);
    draw_tile(&data, 0, 3);
    draw_tile(&data, 1, 0);
    draw_tile(&data, 1, 1);
    draw_tile(&data, 1, 2);
    draw_tile(&data, 1, 3);
    draw_tile(&data, 2, 0);
    draw_tile(&data, 2, 1);
    draw_tile(&data, 2, 2);
    draw_tile(&data, 2, 3);
    draw_tile(&data, 3, 0);
    draw_tile(&data, 3, 1);
    draw_tile(&data, 3, 2);
    draw_tile(&data, 3, 3);
    data.colour = 0xffefd5;
    // draw_tile(&data, 0, 1);
    // draw_tile(&data, 1, 0);


    // print_coordinate(&data, &fdf, 0, 0, 0);
    // print_coordinate(&data, &fdf, 0, 0, 0);


    



    

    // put_cross(&data, START_POINT_X, START_POINT_Y);
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