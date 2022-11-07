/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_2d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:23:15 by mmensing          #+#    #+#             */
/*   Updated: 2022/11/07 20:01:37 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../head/fdf.h"

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained 
 * by splitting ’s’ using the character ’c’ as a delimiter. 
 * The array must end with a NULL pointer.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split.
 * NULL if the allocation fails.
 */
int	*sub_dup(char *str, int start, int finish)
{
	int	*word;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	word = malloc((finish - start + 1) * sizeof(int));
	if (!word)
		return (NULL);
	while (start < finish)
		word[i++] = ft_atoi(&str[start++]);
	word[i] = '\0';
	return (word);
}

int	amount_subs(const char *s, char c)
{
	int		i;
	int		subs;

	if (!s)
		return (0);
	i = 0;
	subs = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			subs++;
		i++;
	}
	return (subs);
}

t_fdf	*new_node(int32_t content)
{
	t_fdf	*new;

	new = NULL;
	new = malloc(sizeof(t_fdf));
	if (!new)
		return (NULL);
	new->val = content;
	new->next = NULL;
	// new->all = NULL;
	return (new);
}

/*
 * function returns one line of the file as an int string
 */
int32_t	*map_split(t_fdf *fdf,  char  *str, char c)
{
	char **line_2d;
	int *return_;
	int32_t i;
	
	i = 0;
	line_2d = ft_split(str, c);
	while (line_2d != NULL)
	{
		fdf->content = new_node(ft_atoi(line_2d[i]));
		fdf->content = fdf->content.ne
		// fdf->content[i] = );
		i++;
	}
	
}

int32_t wordcount()
{
	int32_t fd;
	int32_t count;
	
	count = 0;
	fd = open("../maps/42.fdf", O_RDONLY, 0);
	while (get_next_line(fd) != NULL)
		count++;
	return (count);
}

void init_matrix(t_fdf *fdf)
{
	int32_t fd;
	int32_t i;
	int32_t wc;

	fd = open("../maps/42.fdf", O_RDONLY, 0);
	i = 0;
	wc = wordcount();
	while (wc > 0)
	{
		fdf->matrix[i] = map_split(fdf, get_next_line(fd), ' ');
		wc--;
		i++;
	}
}




// void init_matrix(t_fdf *fdf)
// {
// 	int32_t		fd;
// 	// int32_t		i;
// 	char **store;	

// 	fd = open("../maps/42.fdf", O_RDONLY, 0);
// 	while ()
// 	{
// 		fdf->matrix[][] = ft_split(get_next_line(fd), ' ');
		
// 	}
// }

// void do_2d(t_data *x)
// {
// 	t_fdf	fdf;

// 	init_matrix(&fdf);
	
	



	
// }