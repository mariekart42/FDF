/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/21 19:02:11 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int	keyboard_hook(int key)
{
	// if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
	// 	key_move(key, content);
	// else if (key == ANGLE_UP || key == ANGLE_DOWN || key == ANGLE_LEFT
	// 	|| key == ANGLE_RIGHT)
	// 	key_angle(key, content);
	// else if (key == RESET)
	// 	data_generator(content);
	// else if (key == 6 || key == 7 || key == 8 || key == 9 || key == 11
	// 	|| key == 45 || key == 46)
	// 	key_color(key, content);
	// else if (key == 24 || key == 27) 
	// 	key_zoom(key, content);
	// else if (key == Z_SCALE_UP || key == Z_SCALE_DOWN)
	// 	key_z_scale(key, content);
	if (key == ESCAPE)
	{
		// free_content(data);
		exit(0);
	}

	// handle_event(content);
	// draw(content);
    // draw_map()
	return (0);
}

int main(int argc, char *argv[])
{
    t_data  data;
    t_fdf   fdf;
    if (argc != 2)
        error_msg("input args incorrect! --> usage:  ./exec <map>\n");
    data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.mlx_win = init_window(&data);
	if (data.mlx_win == NULL)
	{
		free(data.mlx_win);
		return (MLX_ERROR);
	}
    data.colour = 0xf5fffa;
    fdf.argv_map = argv[1];
    init_matrix(&fdf, &data);
    draw_map(&fdf, &data);  
    
    
    // mlx_hook(data.mlx_win, 2, 1L<<0, close, &data);
    // mlx_key_hook(data.mlx_win, key_hook, &data);
	// mlx_loop_hook(data.mlx, &handle_no_event, &data);
	// mlx_hook(data.mlx_win, 'D', (1L<<0), &handle_keypress(1, &data), &data);

mlx_key_hook(data.mlx_win, keyboard_hook, &data);

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