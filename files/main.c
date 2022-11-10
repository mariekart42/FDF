/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/10 16:20:00 by mmensing         ###   ########.fr       */
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

    data.colour = 0xfff8dc;
    
    data.x[0] = 10;
    data.y[0] = 10;
    
    // init_matrix(&fdf);
    
    // draw_2d_rasta(&fdf, &data);
    // draw_map(&data, &fdf);
    

    // printf("map: %s\n", fdf.map[0]);
    // printf("map: %s\n", fdf.map[1]);
    // printf("map: %s\n", fdf.map[2]);
    // printf("map: %s\n", fdf.map[3]);
    // printf("map: %s\n", fdf.map[4]);
    // printf("map: %s\n", fdf.map[5]);
    // printf("map: %s\n", fdf.map[6]);
    // printf("map: %s\n", fdf.map[7]);
    // printf("map: %s\n", fdf.map[8]);
    // printf("map: %s\n", fdf.map[9]);
    // printf("map: %s\n", fdf.map[10]);
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



    int x1=12; int y1=HIGHT-80;
    int x2=991; int y2=HIGHT-41;

    
    put_cross(&data, x1, y1);
    put_cross(&data, x2, y2);
    
    init_x(&data, x1, x2);
    init_y(&data, y1, y2);
    
    put_line(&data);
    
    
    
    
    mlx_loop(data.mlx);
}