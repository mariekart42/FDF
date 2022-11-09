/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:23:15 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/09 16:28:23 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function calculates how many lines the current map has
 */
int32_t linecount(char *argv_map)
{
	int32_t fd;
	int32_t count;
	
	count = 0;
	fd = open(argv_map, O_RDONLY, 0);
	if (fd < 0)
		error_msg("unable to open file!\n");
	while (get_next_line(fd) != NULL)
		count++;
	return (count);
}

/*
 * function initialize the matrix with the current map
 */
void init_matrix(t_fdf *fdf)
{
	int32_t	fd;
	int32_t	i;
	int32_t	lc;

	i = 0;
	lc = linecount(fdf->argv_map);
	fd = open(fdf->argv_map, O_RDONLY, 0);
	if (fd < 0)
		error_msg("unable to open file!\n");	
	fdf->matrix = malloc(sizeof(t_fdf*) * lc + 1); 
	while (lc > 0)
	{
		fdf->matrix[i] = get_next_line(fd);
		lc--;
		i++;
	}
	fdf->matrix[i] = NULL;
}

void draw_matrix_line(t_fdf *fdf, int32_t line)
{
	int32_t y = HIGHT - line;
	
}

void draw_map(t_fdf *fdf)
{
	int32_t i = 0;
	while (fdf->matrix[i] != NULL)
	{

		draw_matrix_line(fdf, i);

		i++;
	}
}