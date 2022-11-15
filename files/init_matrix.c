/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:36:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/15 18:04:19 by mmensing         ###   ########.fr       */
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
 * then calculates the coordinates with given angle
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
	fdf->linecount_map = lc;
	fdf->matrix = malloc(sizeof(t_fdf*) * lc + 1);
	while (lc > i)
	{
		fdf->matrix[i] = get_next_line(fd);
		i++;
	}
	fdf->matrix[i] = NULL;
}
