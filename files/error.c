/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 13:21:58 by mmensing          #+#    #+#             */
/*   Updated: 2022/10/30 16:10:31 by mmensing         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../head/fdf.h"
// #include "../libft/libft.h"

void	error_msg(char *msg)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}
