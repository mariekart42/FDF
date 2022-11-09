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

void draw_2d_rasta(t_fdf *fdf, t_data *data)
{
	int32_t i = 0;
	
	int32_t x = 10;
	int32_t y = 10;
	fdf->val = 4;
	
	// horizontal lines
	init_x(data, x, x+500);
	while (i < 11)
	{
		init_y(data, y, y);
		put_horizontal_line(data);
		y += 50;
		i++;
	}
	y = 10;
	i = 0;
	
	// vertikal lines
	init_y(data, y, y+500);
	while (i < 11)
	{
		init_x(data, x, x);
		put_vertical_line(data);
		x+=50;
		i++;
	}
}