/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:08:14 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/14 18:24:35 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

// original
//    y = -z + (previous_x + previous_y) sin(0.46373398);
//    x = (previous_x - previous_y) cos(0.46373398);
	
// my
//    y = (previous_x + previous_y) sin(0.46373398);
//    x = -z + (previous_x - previous_y) cos(0.46373398);

// factor to get on the line: 1.166666644726
// -> f(x)= -x * cos(0.8410687) + 1.166666644726 * u (u changes the length between the copy -> should be our x or y vals (try out lol))
// -->  -x * cos(0.8410687) + (1.166666644726 * u) * c (c is some value that makes it bigger lol (rn everything is scaled to 1 i guess))

// calculated sin & cos:
// sin = (0.5235987756)  (1.5/-1)  -> for upper line
// cos = (0.46373398)    (1/0.5)  -> for above line

// void func(t_data *data, int32_t x, int32_t y, int32_t z)
// {
// 	// to get val of y-axe:
// 	float y_axe;
// y++;
// z++;
// 	y_axe = (x * 0.5) * cos(0.5);
// 	init_x(data, START_POINT_X, x*100);
// 	init_y(data, START_POINT_Y, y_axe*100);
// 	put_line(data);
// }


// calculates direction of the two vectors
// depends on the number of lines and colomns of the map
void init_vectors(t_fdf *fdf)
{
	// now just fix it but later calculate it:

	fdf->y_vector = 0.5;
	// fdf->x_vector = -0.76666644726;
	fdf->x_vector = -0.5;
}

// calculates the size of the tile len depending on the size of the window
// float single_tile_size(t_fdf *fdf)
// {
// 	// now just fix it but later calculate it:
// 	return (50);
// }

// here actually draw the tile
// void func_(t_fdf *fdf, t_data *data, int32_t x_, int32_t y_, int32_t z_)
// {
// 	init_x(data, 0, 700);
// 	init_y(data, START_POINT_Y, START_POINT_Y);
// 	// put_horizontal_line(data);


// 	init_vectors(fdf);
// 	data->cross_colour = 0xcd5c5c;
// 	put_cross(data, START_POINT_X, START_POINT_Y);
	
// 	// ( (x * vector)			=> origin is at (0/0) ! normal coordinatesystem)
// 	// ( (x * vector) + val		=> origin is at (0/0) PLUS moved upwards -> for weird coordinatsystem '-' the val)
	
// // moves the coordinates up(negative val) and down(positive val)
// // float move_up_down = START_POINT_Y;

// // move the coordinates left and rigth
// // for moving left and right only the x val needs to chang
// // float move_left_right = START_POINT_X;

// // // factor that increases the len of the line of a tile (x_ * line_len)
// // float line_len = 50;

// 	z_++;

// 	y_++;

	
// 	//---------------------------------------------------------------------------------------------
// 	// y line:
// // 	data->cross_colour = 0xffff00;
// // 	x_ = 0;
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->y_vector));
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->x_vector));
	
	
// // 	x_ = 1;
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->y_vector));
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->x_vector));
	
// // init_x(data, move_left_right+ 0 * line_len, move_left_right+ 1 * line_len);
// // init_y(data, move_up_down + 0 * line_len * fdf->y_vector, move_up_down + 1 * line_len * fdf->y_vector);
// // 	put_line(data);



// // 	x_ = 2;
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->y_vector));
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->x_vector));
	
// // init_x(data, move_left_right+ 1 * line_len, move_left_right+ 2 * line_len);
// // init_y(data, move_up_down + 1 * line_len * fdf->y_vector, move_up_down + 2 * line_len * fdf->y_vector);
// // 	put_line(data);
	
	

// // 	x_ = 3;
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->y_vector));
// // 	put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->x_vector));
// // init_x(data, move_left_right+ 2 * line_len, move_left_right+ 3 * line_len);
// // init_y(data, move_up_down + 2 * line_len * fdf->y_vector, move_up_down + 3 * line_len * fdf->y_vector);
// // 	put_line(data);
// 	//---------------------------------------------------------------------------------------------
	
	
// 	// //---------------------------------------------------------------------------------------------
// 	// // x line:
// 	// data->cross_colour = 0x2e8b57;
// 	// y_ = 0;
// 	// x_ = 0;
// 	// // put_cross(data, move_left_right+ x_ * line_len, (move_up_down + x_ * line_len * fdf->y_vector));
// 	// put_cross(data, move_left_right+ x_ * line_len, move_up_down + x_ * fdf->y_vector);
// 	// x_ = 1;
// 	// y_ = 1;
// 	// put_cross(data, move_left_right+ x_ * line_len, move_up_down + x_ * fdf->y_vector);
// 	// x_ = 2;
// 	// y_ = 2;
// 	// put_cross(data, move_left_right+ x_ * line_len, move_up_down + x_ * fdf->y_vector);
// 	// x_ = 3;
// 	// y_ = 3;
// 	// put_cross(data, move_left_right+ x_ * line_len, move_up_down + x_ * fdf->y_vector);
	
// 	// print_grit(data);


// 	//---------------------------------------------------------------------------------------------
// 	// init_x(data, START_POINT_X, fdf->x_vector*START_POINT_X);
// 	// init_y(data, START_POINT_Y, fdf->y_vector*START_POINT_Y);
// 	// put_line(data);
// }


// print grit with 10 lines and 10 coloumns
// void print_grit(t_data *data, t_fdf *fdf)
// {
// 	// moves the coordinates up(negative val) and down(positive val)
// 	float move_up_down = START_POINT_Y;
	
// 	// move the coordinates left and rigth
// 	// for moving left and right only the x val needs to chang
// 	float move_left_right = START_POINT_X;
	
// 	// factor that increases the len of the line of a tile (x_ * line_len)
// 	float line_len = 50;

// 	int32_t i = 0;
// 	int32_t curr = 0;
// 	int32_t next = 1;
	
// 	init_vectors(fdf);

// 	// print_coordinate(0, 0, 0);

// 	// while (i < 10)
// 	// {
// 	// 	put_cross(data, move_left_right+  curr  *line_len, move_up_down+  curr  *line_len*fdf->y_vector);
// 	// 	// for x-axe
// 	// 	init_x(data,move_left_right+  curr  *line_len,move_left_right+  next  *line_len);
// 	// 	init_y(data,move_up_down+  curr  *line_len*fdf->y_vector,move_up_down+  next  *line_len*fdf->y_vector);
// 	// 	put_line(data);

// 	// 	put_cross(data, move_left_right+  curr  *line_len, move_up_down+  curr  *line_len*fdf->x_vector);
// 	// 	// for y-axe
// 	// 	init_x(data,move_left_right+  curr  *line_len,move_left_right+  next  *line_len);
// 	// 	init_y(data,move_up_down+  curr  *line_len*fdf->x_vector,move_up_down+  next  *line_len*fdf->x_vector);
// 	// 	put_line(data);
		
// 	// 	curr++;
// 	// 	next++;
// 	// 	i++;
// 	// }
// }

void print_coordinate(t_data *data, t_fdf *fdf, int32_t x, int32_t y, int32_t z)
{
	// implement z later
	z++;
	x++;
	
// y++;
	// moves the coordinates up(negative val) and down(positive val)
	float move_up_down = START_POINT_Y;
	
	// move the coordinates left and rigth
	// for moving left and right only the x val needs to chang
	float move_left_right = START_POINT_X;
	
	// factor that increases the len of the line of a tile (x_ * line_len)
	float line_len = 50;
	
	put_cross(data, move_left_right+  y  *line_len, move_up_down+  y  *line_len*fdf->y_vector);
	init_x(data, move_left_right+  y  *line_len, move_left_right+  y  *line_len);
	init_y(data,  move_up_down+  y  *line_len*fdf->y_vector, move_up_down+  y  *line_len*fdf->x_vector);
	put_line(data);
	put_cross(data, move_left_right+  y  *line_len, move_up_down+  y  *line_len*fdf->x_vector);
}