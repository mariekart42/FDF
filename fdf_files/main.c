/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/21 15:13:27 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->mlx_win);

	printf("Keypress: %d\n", keysym);
	return (0);
}

// int	handle_keyrelease(int keysym, void *data)
// {
// 	printf("Keyrelease: %d\n", keysym);
// 	return (0);
// }

int main(int argc, char *argv[])
{
    t_data  data;
    t_fdf   fdf;
    if (argc != 2)
        error_msg("input args incorrect! --> usage:  ./exec <map>\n");
    data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (1);
	data.mlx_win = init_window(&data);
	if (data.mlx_win == NULL)
	{
		free(data.mlx_win);
		return (2);
	}
    fdf.argv_map = argv[1];
    init_matrix(&fdf, &data);
    draw_map(&fdf, &data);  
    
    
    // mlx_hook(data.mlx_win, 2, 1L<<0, close, &data);
    // mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_hook(data.mlx_win, 'D', (1L<<0), &handle_keypress(XK_Escape, &data), &data);



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