/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejagom <alejagom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 18:49:13 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/24 13:32:32 by alejagom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_tools *tools)
{
	int	large;
	int	down;

	tools->walls_img = mlx_xpm_file_to_image(tools->mlx, "images/pared.xpm",
			&large, &down);
	tools->back = mlx_xpm_file_to_image(tools->mlx, "images/fin.xpm", &large,
			&down);
	tools->coins_img = mlx_xpm_file_to_image(tools->mlx, "images/coin42.xpm",
			&large, &down);
	tools->player = mlx_xpm_file_to_image(tools->mlx, "images/player2.xpm",
			&large, &down);
	tools->player_move = mlx_xpm_file_to_image(tools->mlx, "images/player1.xpm",
			&large, &down);
	tools->exit_end = mlx_xpm_file_to_image(tools->mlx, "images/exit.xpm",
			&large, &down);
	tools->exit_p = mlx_xpm_file_to_image(tools->mlx, "images/exitp.xpm",
			&large, &down);
}

void	draw_img(char letter, t_tools *tools, int j, int i)
{
	if (letter == '0')
		mlx_put_image_to_window(tools->mlx, tools->window, tools->back, j * 64,
			i * 64);
	if (letter == '1')
		mlx_put_image_to_window(tools->mlx, tools->window, tools->walls_img, j
			* 64, i * 64);
	if (letter == 'C')
		mlx_put_image_to_window(tools->mlx, tools->window, tools->coins_img, j
			* 64, i * 64);
	if (letter == 'E')
		mlx_put_image_to_window(tools->mlx, tools->window, tools->exit_end, j
			* 64, i * 64);
	if (letter == 'P')
		mlx_put_image_to_window(tools->mlx, tools->window, tools->player, j
			* 64, i * 64);
}

void	draw_map(t_tools *tools)
{
	int	i;
	int	j;

	i = 0;
	while (tools->cpy_map[i])
	{
		j = 0;
		while (tools->cpy_map[i][j])
		{
			draw_img(tools->cpy_map[i][j], tools, j, i);
			j++;
		}
		i++;
	}
}

int	close_window(t_tools *tools)
{
	close_game("Close window", tools);
	return (0);
}

void	start_game(t_tools *tools)
{
	tools->mlx = mlx_init();
	tools->size_x = tools->colums * 64;
	tools->size_y = tools->rows * 64;
	tools->window = mlx_new_window(tools->mlx, tools->size_x, tools->size_y,
			"so_long");
	check_images(tools);
	draw_map(tools);
	mlx_key_hook(tools->window, move_key, tools);
	mlx_hook(tools->window, 17, 0, close_window, tools);
	mlx_loop(tools->mlx);
}
