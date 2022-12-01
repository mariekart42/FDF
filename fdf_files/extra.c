/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:21:58 by mmensing          #+#    #+#             */
/*   Updated: 2022/12/01 17:08:09 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../head/fdf.h"

void	error_msg(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	keyboard_hook(int key)
{
	if (key == ESCAPE)
		exit(0);
	return (0);
}

void	save_free(void *to_free)
{
	if (to_free)
		free(to_free);
}