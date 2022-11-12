/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/12 18:17:52 by mmensing         ###   ########.fr       */
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
    
    fdf.argv_map = argv[1];
    printf("argv: %s\n", fdf.argv_map);
    
    argc++;

    

    data.cross_colour = 0xff6347;
    
    // init_matrix(&fdf);
    

    
    data.colour = 0xffefd5;
    func_(&fdf, &data, 0, 0, 0);
    // isometric(&data, 20, 10, 1);
    data.colour = 0xffffff;
    // isometric(&data, 30, 10, 1);
    // isometric(&data, 1, 2, 2);
    // isometric(&data, 1, 3, 3);
    // isometric(&data, 1, 4, 4);
    // isometric(&data, 1, 5, 5);
    // isometric(&data, 1, 6, 6);
    
    data.colour = 0x708090; //grey
    // isometric(&data, 10, 990, 60);
    // isometric(&data, 100, 900, 40);
    // isometric(&data, 100, 900, 50);
    // isometric(&data, 100, 900, 60);
    // isometric(&data, 100, 900, 70);
    // isometric(&data, 100, 900, 80);
    // isometric(&data, 100, 900, 90);
    // draw_2d_rasta(&fdf, &data);
    // draw_map(&data, &fdf);
    

    // printf("map: %s\n", fdf.matrix[0]);
    // printf("map: %s\n", fdf.matrix[1]);
    // printf("map: %s\n", fdf.matrix[2]);
    // printf("map: %s\n", fdf.matrix[3]);
    // printf("map: %s\n", fdf.matrix[4]);
    // printf("map: %s\n", fdf.matrix[5]);
    // printf("map: %s\n", fdf.matrix[6]);
    // printf("map: %s\n", fdf.matrix[7]);
    // printf("map: %s\n", fdf.matrix[8]);
    // printf("map: %s\n", fdf.matrix[9]);
    // printf("map: %s\n", fdf.matrix[10]);
    // printf("map: %s\n", fdf.map[11]);


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
    
    // put_line(&data);
    
    
    
    // START_POINT
    // data.cross_colour = 0x90ee90;
    // put_cross(&data, START_POINT_X, START_POINT_Y);
    put_cross(&data, START_POINT_X, START_POINT_Y);
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