/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_start_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:42:15 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/22 14:22:18 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_img(char letter, t_tools *tools, int j, int i)
{
	if (letter == '0')
		mlx_put_image_to_window(tools->mlx, tools->window,
				tools->back, j * 64, i * 64);
	if (letter == '1')
		mlx_put_image_to_window(tools->mlx, tools->window,
					tools->walls_img, j * 64, i * 64);
	if (letter == 'C')
		mlx_put_image_to_window(tools->mlx, tools->window,
					tools->coins_img, j * 64, i * 64);
	if (letter == 'E')
		mlx_put_image_to_window(tools->mlx, tools->window,
					tools->exit_end, j * 64, i * 64);
	if (letter == 'P')
		mlx_put_image_to_window(tools->mlx, tools->window, 
					tools->player, j * 64, i * 64);
}
