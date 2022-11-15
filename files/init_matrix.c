/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:36:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/15 19:03:29 by mmensing         ###   ########.fr       */
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

int32_t count_lines_(char **str)
{
	int32_t i = 0;
	
	while (str != NULL)
	{
		i++;
		str++;
	}
	return (i + 1);
}

/*
 * converting a string to int array
 */
int32_t *stoi(char *str)
{
	char **tmp;
	int32_t i = 0;
	int32_t *result;
	int32_t count_lines;

	tmp = ft_split(str, ' ');
	count_lines = count_lines_(tmp);
	result = (int32_t *)malloc(sizeof(int32_t));
	while (i < count_lines)
	{
		result[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (result);
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
	int32_t *tmp;

	i = 0;
	lc = linecount(fdf->argv_map);
	fd = open(fdf->argv_map, O_RDONLY, 0);
	if (fd < 0)
		error_msg("unable to open file!\n");
	fdf->linecount_map = lc;
	fdf->matrix = malloc(sizeof(int32_t*) * lc + 1);
	tmp = stoi(get_next_line(fd));
	while (lc > i)
	{
		fdf->matrix[i] = tmp[i];
		i++;
	}
	fdf->matrix[i] = 0;
	free(tmp);
}
