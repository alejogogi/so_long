/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:46:04 by alejagom          #+#    #+#             */
/*   Updated: 2025/05/19 16:56:58 by alejagom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "get_next_line.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"
#include "../ft_printf/ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_tools
{
	void	*mlx;
	int	colums;
	int	rows;
	int	player_x;
	int	player_y;
	char **cpy_map;
}		t_tools;

void	check_ber(char *maps);
void	open_map(char *args, t_tools *tools);
void	parc_map(t_tools *tools);
void	free_tools(t_tools *tools);
//void	start_game(t_tools *tools);
void	exit_message(char *error, t_tools *tools);
void	floot_fill(t_tools *tools);


#endif
