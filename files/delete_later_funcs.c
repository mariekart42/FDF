#include "../head/fdf.h"

// x and y are the middle point of the cross
// len is the pixel len of the lines
void put_cross(t_data *x_data,int x, int y)
{
	int save_x;
	int save_y;
	int minus_len;
	int len;
	
	save_x = x;
	save_y = y;
	len = 4;
	len++;
	minus_len = len * (-1);
	x += len;
	y -= len;
	while (len - 1 > minus_len)
	{
		x -= 1;
		y += 1;
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y, x_data->cross_colour);
		mlx_pixel_put(x_data->mlx, x_data->mlx_win, x, y - 2 + (len * 2), x_data->cross_colour);
		len--;
	}
	// middle point
	mlx_pixel_put(x_data->mlx, x_data->mlx_win, save_x, save_y, 0XFF0000);
}

void print_case(t_data *x_data, float slow_f, float fast_f)
{
	if (x_data->slow[1] == 121 && slow_f ==-1)
		printf("case:"MAG" 1\n"YEL"-  -  -  -  -  -  -  -\n\n"RESET);
	else if (x_data->slow[1]==120 && slow_f==1 && fast_f==-1)
		printf("case:"MAG" 2\n"YEL"-  -  -  -  -  -  -  -\n\n"RESET);
	else if (x_data->slow[1]==121 && slow_f==1)
		printf("case:"MAG" 3\n"YEL"-  -  -  -  -  -  -  -\n\n"RESET);
	else if (x_data->slow[1]==120 && slow_f==1 && fast_f==1)
		printf("case:"MAG" 4\n"YEL"-  -  -  -  -  -  -  -\n\n"RESET);
	else
		printf(RED"something wrong with print case_func\n\n"RESET);
}

void print_factor(float fast_f, float slow_f)
{
	if (slow_f==1)
		printf("slow_factor: "YEL"+1\n"RESET);
	else if (slow_f==-1)
		printf("slow_factor: "YEL"-1\n"RESET);
	if (fast_f==1)
		printf("fast_factor: "YEL"+1\n"RESET);
	else if (fast_f==-1)
		printf("fast_factor: "YEL"-1\n"RESET);

}