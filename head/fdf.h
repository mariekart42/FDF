/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:34:10 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/27 16:48:23 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FDF_H
#define FDF_H

// #include "../mlx/include/MLX42/MLX42_Input.h"
// #include "../mlx/include/MLX42/MLX42_Int.h"
#include "../mlx/mlx.h"
// #include <stdlib.h>
// #include <stdio.h>
# include <stdbool.h>

typedef struct s_my_data
{
	int x1;
	int x2;
	int y1;
	int y2;
}			t_my_data;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif