/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 14:47:08 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/23 23:30:13 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(t_tools *tools)
{
	tools->moves++;
	ft_printf("Total movements: %d\n", tools->moves);
}

void	replace_exit_w(t_tools *kit)
{
	if (kit->player_y > 0 && kit->cpy_map[kit->player_y
			- 1][kit->player_x] != '1')
	{
		mlx_put_image_to_window(kit->mlx, kit->window, kit->back, kit->player_x
			* 64, kit->player_y * 64);
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_end,
				kit->player_x * 64, kit->player_y * 64);
		kit->player_y--;
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_p,
				kit->player_x * 64, kit->player_y * 64);
		else if (kit->img_moves % 2 == 0)
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player_move,
				kit->player_x * 64, kit->player_y * 64);
		else
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player,
				kit->player_x * 64, kit->player_y * 64);
		kit->img_moves++;
	}
}

void	replace_exit_s(t_tools *kit)
{
	if (kit->player_y > 0 && kit->cpy_map[kit->player_y
			+ 1][kit->player_x] != '1')
	{
		mlx_put_image_to_window(kit->mlx, kit->window, kit->back, kit->player_x
			* 64, kit->player_y * 64);
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_end,
				kit->player_x * 64, kit->player_y * 64);
		kit->player_y++;
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_p,
				kit->player_x * 64, kit->player_y * 64);
		else if (kit->img_moves % 2 == 0)
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player_move,
				kit->player_x * 64, kit->player_y * 64);
		else
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player,
				kit->player_x * 64, kit->player_y * 64);
		kit->img_moves++;
	}
}

void	replace_exit_a(t_tools *kit)
{
	if (kit->player_y > 0 && kit->cpy_map[kit->player_y][kit->player_x
		- 1] != '1')
	{
		mlx_put_image_to_window(kit->mlx, kit->window, kit->back, kit->player_x
			* 64, kit->player_y * 64);
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_end,
				kit->player_x * 64, kit->player_y * 64);
		kit->player_x--;
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_p,
				kit->player_x * 64, kit->player_y * 64);
		else if (kit->img_moves % 2 == 0)
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player_move,
				kit->player_x * 64, kit->player_y * 64);
		else
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player,
				kit->player_x * 64, kit->player_y * 64);
		kit->img_moves++;
	}
}

void	replace_exit_d(t_tools *kit)
{
	if (kit->player_y > 0 && kit->cpy_map[kit->player_y][kit->player_x
		+ 1] != '1')
	{
		mlx_put_image_to_window(kit->mlx, kit->window, kit->back, kit->player_x
			* 64, kit->player_y * 64);
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_end,
				kit->player_x * 64, kit->player_y * 64);
		kit->player_x++;
		if (kit->cpy_map[kit->player_y][kit->player_x] == 'E')
			mlx_put_image_to_window(kit->mlx, kit->window, kit->exit_p,
				kit->player_x * 64, kit->player_y * 64);
		else if (kit->img_moves % 2 == 0)
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player_move,
				kit->player_x * 64, kit->player_y * 64);
		else
			mlx_put_image_to_window(kit->mlx, kit->window, kit->player,
				kit->player_x * 64, kit->player_y * 64);
		kit->img_moves++;
	}
}
