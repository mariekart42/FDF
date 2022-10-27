/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:33:14 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/27 17:02:00 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"
#include "../mlx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void put_horizontal_line(void *mlx, void *mlx_win, int x1, int x2, int y,  int colour)
{
	if (x1 <= x2)
	{
		while (x1 <= x2)
		{
			mlx_pixel_put(mlx, mlx_win, x1, y, colour);
			x1++;
		}
	}
	else
	{
		while (x1 >= x2)
		{
			mlx_pixel_put(mlx, mlx_win, x1, y, colour);
			x1--;
		}
	}
}

void put_vertical_line(void *mlx, void *mlx_win, int x, int y1, int y2,  int colour)
{
	if (y1 <= y2)
	{
		while (y1 <= y2)
		{
			mlx_pixel_put(mlx, mlx_win, x, y1, colour);
			y1++;
		}
	}
	else
	{
		while (y1 >= y2)
		{
			mlx_pixel_put(mlx, mlx_win, x, y1, colour);
			y1--;
		}
	}
}


// x and y are the middle point of the cross
// len is the pixel len of the lines
void put_cross(void *mlx, void *mlx_win, int x, int y, int colour, int len)
{
	int save_x;
	int save_y;
	int minus_len;
	
	save_x = x;
	save_y = y;
	len++;
	minus_len = len * (-1);
	x += len;
	y -= len;
	while (len - 1 > minus_len)
	{
		x -= 1;
		y += 1;
		mlx_pixel_put(mlx, mlx_win, x, y, colour);
		mlx_pixel_put(mlx, mlx_win, x, y - 2 + (len * 2), colour);
		len--;
	}
	// middle point
	mlx_pixel_put(mlx, mlx_win, save_x, save_y, 0XFF0000);
}

void put_rectangle(void *mlx, void *mlx_win, int x1, int x2, int y1, int y2, int colour)
{
	put_horizontal_line(mlx, mlx_win, x1, x2, y1, colour);
	put_horizontal_line(mlx, mlx_win, x1, x2, y2, colour);
	put_vertical_line(mlx, mlx_win, x1, y1, y2, colour);
	put_vertical_line(mlx, mlx_win, x2, y1, y2, colour);
}

void shift_rectangle(void *mlx, void *mlx_win, int x1, int x2, int y1, int y2, int colour, bool right, bool up, int times, int sep)
{
	int x_factor = 0;
	int y_factor = 0;
	while (times > 0)
	{
		if (right == true)
			x_factor -= sep;
		else
			x_factor += sep;
		if (up == true)
			y_factor -= sep;
		else
			y_factor += sep;
		put_rectangle(mlx, mlx_win, x1 + x_factor, x2 + x_factor, y1 + y_factor, y2 + y_factor, colour);
		times--;
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	
	// t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 700, "bullshit world!");
	// img.img = mlx_new_image(mlx, 1000, 700);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	

	// // put_horizontal_line(mlx, mlx_win, 50, 50, 20, 0xf5fffa);
	// put_vertical_line(mlx, mlx_win, 400, 20, 300, 0xff00ff); //magenta
	// // put_vertical_line(mlx, mlx_win, 401, 20, 300, 0xff00ff);
	

	// put_horizontal_line(mlx, mlx_win, 20, 400, 20, 0xf5fffa);
	// put_horizontal_line(mlx, mlx_win, 20, 400, 300, 0xf5fffa);
	

	// put_vertical_line(mlx, mlx_win, 20, 20, 300, 0x87ceeb); // blue
	

	shift_rectangle(mlx, mlx_win, 20, 150, 10, 160, 0x87ceeb, false, false, 30, 11);

	// put_rectangle(mlx, mlx_win, 50, 400, 50, 500, 0xFF0000);
	// put_rectangle(mlx, mlx_win, 55, 405, 45, 495, 0xFF0000);
	// put_rectangle(mlx, mlx_win, 60, 410, 40, 490, 0x00FF00);
	// put_rectangle(mlx, mlx_win, 65, 415, 35, 485, 0xFF0000);
	// put_rectangle(mlx, mlx_win, 70, 420, 30, 480, 0xFF0000);
	
	// put_line(mlx, mlx_win, )
	// put_vertical_line(mlx, mlx_win, 21, 20, 300, 0x87ceeb);
	
	// put_cross(mlx, mlx_win, 20, 20, 0xbbffff, 4);

	// int x = 25;
	// while(x < 600)
	// {
	// 	mlx_pixel_put(mlx, mlx_win, x, 5, 0xfffafa);
	// 	mlx_pixel_put(mlx, mlx_win, x, 50, 0xfffafa);
		
	// 	x++;
	// 	// mlx_pixel_put(mlx, mlx_win, x, 5, 0x0000FF00);
	// }
	mlx_loop(mlx);
	// mlx_pixel_put(mlx, mlx_win, 5, 6, 0x00FF0000);
	// mlx_pixel_put(mlx, mlx_win, 5, 7, 0x0000FF00);
	// mlx_pixel_put(mlx, mlx_win, 5, 8, 0x0000FF00);
	// my_mlx_pixel_put(&img, 5, 50, 0x0000FF00);
	// my_mlx_pixel_put(&img, 55, 5, 0x00FF0000);
	// my_mlx_pixel_put(&img, 500, 5, 0x0000FF00);
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
}