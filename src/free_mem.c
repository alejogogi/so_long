/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 19:31:14 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/24 00:20:12 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_tools(t_tools *tools)
{
	int	i;

	i = 0;
	if (tools->cpy_map)
	{
		while (tools->cpy_map[i])
		{
			free(tools->cpy_map[i]);
			i++;
		}
		free(tools->cpy_map);
		tools->cpy_map = NULL;
	}
	free(tools);
}

void	exit_message(char *error, t_tools *tools)
{
	free_tools(tools);
	ft_printf("%s\n", error);
	exit(EXIT_FAILURE);
}

void	close_game(char *str, t_tools *tools)
{
	if (!tools)
		return ;
	mlx_destroy_image(tools->mlx, tools->back);
	mlx_destroy_image(tools->mlx, tools->coins_img);
	mlx_destroy_image(tools->mlx, tools->exit_p);
	mlx_destroy_image(tools->mlx, tools->player);
	mlx_destroy_image(tools->mlx, tools->player_move);
	mlx_destroy_image(tools->mlx, tools->exit_end);
	mlx_destroy_image(tools->mlx, tools->walls_img);
	mlx_destroy_window(tools->mlx, tools->window);
	mlx_destroy_display(tools->mlx);
	exit_message(str, tools);
}
