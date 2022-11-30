/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:36:05 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/30 18:08:20 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/*
 * function calculates how many lines the current map has
 */
int32_t	linecount(char *argv_map, t_list **head)
{
	int32_t	fd;
	int32_t	count;

	count = 0;
	fd = open(argv_map, O_RDONLY, 0);
	if (fd < 0)
		error_msg("unable to open file!\n");
	char *line = get_next_line(fd);
	ft_lstadd_back(head, ft_lstnew((void *)line));
	while (line)
	{
		count++;
		line = get_next_line(fd);
		ft_lstadd_back(head, ft_lstnew((void *)line));
	}
	return (count);
}

/*
 * function caounts the amount of single arguments in one line
 */
int32_t	wordcount(char *argv_map, t_list **head)
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
	ft_lstadd_back(head, ft_lstnew((void *)line));
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
int32_t	open_file(char *argv_map)
{
	int32_t	fd;

	fd = open(argv_map, O_RDONLY, 0);
	if (fd < 0)
		error_msg("unable to open file!\n");
	return (fd);
}

/*
 * function initialize the matrix with the current map
 * as an 2d array of type int
 */
void	init_matrix(t_fdf *fdf, t_data *data, t_list **head)
{
	int32_t	fd;
	int32_t	i;
	int32_t	k;
	char	**tmp;

	k = 0;
	i = 0;
	data->linecount_map = linecount(fdf->argv_map, head);
	data->wordcount_map = wordcount(fdf->argv_map, head);
	fd = open_file(fdf->argv_map);
	fdf->matrix = malloc(sizeof(t_fdf *) * data->linecount_map);
	ft_lstadd_back(head, ft_lstnew((void *)fdf->matrix));
	while (data->linecount_map > i)
	{
		char *line = get_next_line(fd);
		ft_lstadd_back(head, ft_lstnew((void *)line));
		tmp = ft_split(line, ' ');
		ft_lstadd_back(head, ft_lstnew((void *)tmp));
		for (int j = 0; tmp[j]; j++)
			ft_lstadd_back(head, ft_lstnew((void *)tmp[j]));
		fdf->matrix[i] = malloc(sizeof(t_fdf) * data->wordcount_map);
		ft_lstadd_back(head, ft_lstnew((void *)fdf->matrix[i]));
		while (data->wordcount_map > k)
		{
			fdf->matrix[i][k] = ft_atoi(tmp[k]) * COTRAST_SIZE;
			k++;
		}
		k = 0;
		i++;
	}
}
