/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/19 15:53:41 by mmensing         ###   ########.fr       */
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
    
    // mlx_new_window(data.mlx, WIDHT, HIGHT, WINDOW_NAME);

    data.cross_colour = 0xff6347;

    data.colour = 0x708090; //grey
    data.colour = 0xffefd5;
    
    fdf.argv_map = argv[1];
    

    init_matrix(&fdf, &data);
    
	data.mlx_win = init_window(&data);
    
    draw_map(&fdf, &data);    

    // colouring();

    mlx_loop(data.mlx);
}





void *init_window(t_data *data)
{
    // if (AUTO_SIZING == true)
    //     return (calc_size(data));
    // else
        return (mlx_new_window(data->mlx, WIDHT, HIGHT, WINDOW_NAME));
}

// void *calc_size(t_data *data)
// {
//     int32_t widht;
//     int32_t hight;    

// return NULL;
//     // return (mlx_new_window(data->mlx, widht, hight, WINDOW_NAME));
// }