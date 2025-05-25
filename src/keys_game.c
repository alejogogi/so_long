/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 14:30:28 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/24 18:37:34 by alejogogi        ###   ########.fr       */
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

void	w_key(t_tools *tools)
{
	if (tools->cpy_map[tools->player_y - 1][tools->player_x] != '1')
	{
		moves(tools);
		if (tools->cpy_map[tools->player_y - 1][tools->player_x] == 'E'
			&& tools->coins == 0)
			close_game("Finish game", tools);
		else
			replace_exit_w(tools);
		if (tools->cpy_map[tools->player_y][tools->player_x] == 'C')
		{
			tools->coins--;
			tools->cpy_map[tools->player_y][tools->player_x] = '0';
		}
	}
}

void	s_key(t_tools *tools)
{
	if (tools->cpy_map[tools->player_y + 1][tools->player_x] != '1')
	{
		moves(tools);
		if (tools->cpy_map[tools->player_y + 1][tools->player_x] == 'E'
			&& tools->coins == 0)
			close_game("Finish game", tools);
		else if ((tools->cpy_map[tools->player_y + 1][tools->player_x] != 'E')
			|| (tools->cpy_map[tools->player_y + 1][tools->player_x] == 'E'
				&& tools->coins != 0))
			replace_exit_s(tools);
		if (tools->cpy_map[tools->player_y][tools->player_x] == 'C')
		{
			tools->coins--;
			tools->cpy_map[tools->player_y][tools->player_x] = '0';
		}
	}
}

void	a_key(t_tools *tools)
{
	if (tools->cpy_map[tools->player_y][tools->player_x - 1] != '1')
	{
		moves(tools);
		if (tools->cpy_map[tools->player_y][tools->player_x - 1] == 'E'
			&& tools->coins == 0)
			close_game("Finish game", tools);
		else if ((tools->cpy_map[tools->player_y][tools->player_x - 1] != 'E')
			|| (tools->cpy_map[tools->player_y][tools->player_x - 1] == 'E'
				&& tools->coins != 0))
			replace_exit_a(tools);
		if (tools->cpy_map[tools->player_y][tools->player_x] == 'C')
		{
			tools->coins--;
			tools->cpy_map[tools->player_y][tools->player_x] = '0';
		}
	}
}

void	d_key(t_tools *tools)
{
	if (tools->cpy_map[tools->player_y][tools->player_x + 1] != '1')
	{
		moves(tools);
		if (tools->cpy_map[tools->player_y][tools->player_x + 1] == 'E'
			&& tools->coins == 0)
			close_game("Finish game", tools);
		else if ((tools->cpy_map[tools->player_y][tools->player_x + 1] != 'E')
			|| (tools->cpy_map[tools->player_y][tools->player_x + 1] == 'E'
				&& tools->coins != 0))
			replace_exit_d(tools);
		if (tools->cpy_map[tools->player_y][tools->player_x] == 'C')
		{
			tools->coins--;
			tools->cpy_map[tools->player_y][tools->player_x] = '0';
		}
	}
}
