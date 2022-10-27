/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:33:14 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/27 20:49:19 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"
#include "../mlx/mlx.h"

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void put_horizontal_line(t_data *x_data, int colour, int iter)
{
	int x1 = x_data->x[0];
	
	if (x1 <= x_data->x[1])
	{
		while (x1 <= x_data->x[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[0], colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[1], colour);
			x1++;
		}
	}
	else
	{
		while (x1 >= x_data->x[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x1, x_data->y[0], colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[1], x_data->y[0], colour);
			x1--;
		}
	}
}

void put_vertical_line(t_data *x_data, int colour, int iter)
{
	int y1 = x_data->y[0];
	if (y1 <= x_data->y[1])
	{
		while (y1 <= x_data->y[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[0], y1, colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[1], y1, colour);
			y1++;
		}
	}
	else
	{
		while (y1 >= x_data->y[1])
		{
			if (iter == 1)
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[0], y1, colour);
			else
				mlx_pixel_put(x_data->mlx, x_data->mlx_win, x_data->x[1], y1, colour);
			y1--;
		}
	}
}


// // x and y are the middle point of the cross
// // len is the pixel len of the lines
// void put_cross(t_data *x_data,int x, int y, int colour, int len)
// {
// 	int save_x;
// 	int save_y;
// 	int minus_len;
	
// 	save_x = x;
// 	save_y = y;
// 	len++;
// 	minus_len = len * (-1);
// 	x += len;
// 	y -= len;
// 	while (len - 1 > minus_len)
// 	{
// 		x -= 1;
// 		y += 1;
// 		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y, colour);
// 		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y - 2 + (len * 2), colour);
// 		len--;
// 	}
// 	// middle point
// 	mlx_pixel_put(x_data->mlx, x_data->mlx_win, save_x, save_y, 0XFF0000);
// }

void put_rectangle(t_data *x_data, int colour)
{
	put_horizontal_line(x_data, colour, 1);
	put_horizontal_line(x_data, colour, 2);
	put_vertical_line(x_data, colour, 1);
	put_vertical_line(x_data, colour, 2);
}

void shift_rectangle(t_data *x_data, int colour, bool right, bool up, int times, int sep)
{
	while (times > 0)
	{
		if (right == true)
		{
			x_data->x[0] -= sep;
			x_data->x[1] -= sep;
		}
		else
		{
			x_data->x[0] += sep;
			x_data->x[1] += sep;
		}
		if (up == true)
		{
			x_data->y[0] -= sep;
			x_data->y[1] -= sep;
		}
		else
		{
			x_data->y[0] += sep;
			x_data->y[1] += sep;
		}
		put_rectangle(x_data, colour);
		times--;
	}
}

// void put_line(t_data *x_data)
// {

// }

void init_x(t_data *x_data, int x1, int x2)
{
	x_data->x[0] = x1;
	x_data->x[1] = x2;
}
void init_y(t_data *x_data, int y1, int y2)
{
	x_data->y[0] = y1;
	x_data->y[1] = y2;
}

int	main(void)
{
	t_data	x;
	
	// t_data	img;

	x.mlx = mlx_init();
	x.mlx_win = mlx_new_window(x.mlx, 1000, 700, "bullshit world!");
	// img.img = mlx_new_image(mlx, 1000, 700);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	

	// // put_horizontal_line(mlx, mlx_win, 50, 50, 20, 0xf5fffa);
	// put_vertical_line(mlx, mlx_win, 400, 20, 300, 0xff00ff); //magenta
	// // put_vertical_line(mlx, mlx_win, 401, 20, 300, 0xff00ff);
	

	// put_horizontal_line(mlx, mlx_win, 20, 400, 20, 0xf5fffa);

	init_x(&x, 50, 400);
	init_y(&x, 20, 50);
	// put_rectangle(&x, 0xFF0000);
	// put_horizontal_line(&x, 0xf5fffa, 1);
	// put_horizontal_line(&x, 0xf5fffa, 2);
	

	// put_vertical_line(mlx, mlx_win, 20, 20, 300, 0x87ceeb); // blue
	shift_rectangle(&x, 0x87ceeb, false, false, 30, 11);

	// put_rectangle(&x, 0xFF0000);
	// put_rectangle(mlx, mlx_win, 60, 410, 40, 490, 0x00FF00);
	// put_rectangle(mlx, mlx_win, 65, 415, 35, 485, 0xFF0000);
	// put_rectangle(mlx, mlx_win, 70, 420, 30, 480, 0xFF0000);
	
	// put_line(mlx, mlx_win, )
	// put_vertical_line(&x, 0x87ceeb);
	
	// put_cross(mlx, mlx_win, 20, 20, 0xbbffff, 4);

	// int x = 25;
	// while(x < 600)
	// {
	// 	mlx_pixel_put(mlx, mlx_win, x, 5, 0xfffafa);
	// 	mlx_pixel_put(mlx, mlx_win, x, 50, 0xfffafa);
		
	// 	x++;
	// 	// mlx_pixel_put(mlx, mlx_win, x, 5, 0x0000FF00);
	// }
	mlx_loop(x.mlx);
	// mlx_pixel_put(mlx, mlx_win, 5, 6, 0x00FF0000);
	// mlx_pixel_put(mlx, mlx_win, 5, 7, 0x0000FF00);
	// mlx_pixel_put(mlx, mlx_win, 5, 8, 0x0000FF00);
	// my_mlx_pixel_put(&img, 5, 50, 0x0000FF00);
	// my_mlx_pixel_put(&img, 55, 5, 0x00FF0000);
	// my_mlx_pixel_put(&img, 500, 5, 0x0000FF00);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}