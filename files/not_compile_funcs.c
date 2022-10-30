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