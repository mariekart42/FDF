/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:36:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/21 19:56:09 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function calculates how many lines the current map has
 */
int32_t	linecount(char *argv_map)
{
	int32_t	fd;
	int32_t	count;

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
int32_t	wordcount(char *argv_map)
{
	int32_t	fd;
	int32_t	count;
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
		else if (line[i] != ' ' && line[i - 1] == ' ')
			count++;
		i++;
	}
	return (count);
}

/*
 * function that opnes the file of the map and checks for errors
 * calls error_msg function that exits the program if something went wrong
 * returns the filedescriptor of the file
 */
int32_t	open_file(char *argv_map, int32_t open_macro)
{
	fd = open(fdf->argv_map, O_RDONLY);
	if (fd < 0)
		error_msg("unable to open file!\n");
	return (fd);
}

/*
 * function initialize the matrix with the current map
 * as an 2d array of type int
 */
void	init_matrix(t_fdf *fdf, t_data *data)
{
	int32_t	fd;
	int32_t	i;
	int32_t	k;
	char	**tmp;

	k = 0;
	i = 0;
	data->linecount_map = linecount(fdf->argv_map);
	data->wordcount_map = wordcount(fdf->argv_map);
	fd = open_file(fdf->argv_map, O_RDONLY, 0);
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
