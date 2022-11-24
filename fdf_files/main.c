/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:52:51 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/24 14:21:29 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

int	keyboard_hook(int key)
{
	if (key == ESCAPE)
	{
		exit(0);
	}
	return (0);
}

void free_content(t_fdf *fdf, t_data *data)
{
	int i = 0;
	while (fdf->matrix[i] != NULL)
	{
		if(fdf->matrix[i])
			free(fdf->matrix[i]);
		i++;
	}
	if (fdf->matrix)
		free(fdf->matrix);
	if (data->mlx_win)
		free(data->mlx_win);
}

int32_t	main(int argc, char *argv[])
{
	t_data	data;
	t_fdf	fdf;

	if (argc != 2)
		error_msg("input args incorrect! --> usage:  ./exec <map>\n");
	data.mlx = mlx_init();
	if (data.mlx == NULL)
		return (MLX_ERROR);
	data.mlx_win = mlx_new_window(data.mlx, WIDHT, HIGHT, WINDOW_NAME);
	if (data.mlx_win == NULL)
	{
		free(data.mlx_win);
		return (MLX_ERROR);
	}
	data.colour = 0xf5fffa;
	fdf.argv_map = argv[1];
	init_matrix(&fdf, &data);
	draw_map(&fdf, &data);
	mlx_key_hook(data.mlx_win, keyboard_hook, &data);
	free_content(&fdf, &data);
	exit(0);
	mlx_loop(data.mlx);
	mlx_destroy_window(data.mlx, data.mlx_win);
}
