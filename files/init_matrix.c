/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:36:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/19 15:52:30 by mmensing         ###   ########.fr       */
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
 * function caounts the amount of single arguments in one line
 */
int32_t wordcount(char *argv_map)
{
	int32_t fd;
	int32_t count;
	char	*line;
	int32_t	i;

	i = 0;
	line = NULL;
	count = 0;
	fd = open(argv_map, O_RDONLY, 0);
	if (fd < 0)
		error_msg("unable to open file!\n");
	line = get_next_line(fd);
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (i == 0 && line[i] != ' ')
			count++;
		else if (line[i] != ' ' && line[i-1] == ' ')
			count++;
		i++;
	}
	return (count);
}

/*
 * function initialize the matrix with the current map
 * as an 2d array of type int
 */
void init_matrix(t_fdf *fdf, t_data *data)
{
	int32_t	fd;
	int32_t	i;
	int32_t k = 0;
	char **tmp;

	i = 0;
	data->linecount_map = linecount(fdf->argv_map);
	data->wordcount_map = wordcount(fdf->argv_map);
	fd = open(fdf->argv_map, O_RDONLY, 0);
	if (fd < 0)
		error_msg("unable to open file!\n");
	fdf->matrix = malloc(sizeof(t_fdf *) * data->linecount_map);
	while (data->linecount_map > i)
	{
		tmp = ft_split(get_next_line(fd), ' ');
		fdf->matrix[i] = malloc(sizeof(t_fdf) * data->wordcount_map);
		while (data->wordcount_map > k)
		{
			fdf->matrix[i][k] = ft_atoi(tmp[k]) * 10;
			k++;
		}
		k = 0;
		if (tmp)
			free(tmp);
		i++;
	}
}
