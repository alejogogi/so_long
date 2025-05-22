/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:30:28 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/22 15:50:39 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_key(int key, t_tools *tools)
{
	if (key == 65362 || key == 119)
		w_key(tools);
	else if (key == 65363 || key == 100)
		d_key(tools);
	else if (key == 65364 || key == 115)
		s_key(tools);
	else if (key == 65361 || key == 97)
		a_key(tools);
	else if (key == 65307)
		close_game("Finish game", tools);
	return (0);
}

void	replace_exit(t_tools *tools, int coord)
{
	if (tools->cpy_map[tools->player_y][tools->player_x] == 'E')
	{
		mlx_put_image_to_window(tools->mlx, tools->window, 
			tools->back, tools->player_y, tools->player_x);
		coord--;		
		mlx_put_image_to_window(tools->mlx, tools->window, tools->exit_2, 
			tools->player_y, tools->player_x);
	}
	else 
	{
		mlx_put_image_to_window(tools->mlx, tools->window, 
			tools->back, tools->player_y, tools->player_x);
		coord--;
		mlx_put_image_to_window(tools->mlx, tools->window, 
			tools->player, tools->player_y, tools->player_x);
	}
}

void	w_key(t_tools *tools)
{
	if (tools->cpy_map[tools->player_y - 1][tools->player_x] != '1')
	{
		if (tools->cpy_map[tools->player_y - 1][tools->player_x] == 'E'
			&& tools->coins == 0)
			close_game("Finish game", tools);
		else if (tools->cpy_map[tools->player_y - 1][tools->player_x] != 
			'E' || tools->cpy_map[tools->player_y - 1][tools->player_x] 
			== 'E' && tools->coins != 0)
			replace_exit(tools, tools->player_y);
		if (tools->cpy_map[tools->player_y][tools->player_x] == 'C')
		{
			tools->coins--;
			tools->cpy_map[tools->player_y][tools->player_x] = '0';
		}
	}
}
