/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parc_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 12:47:23 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/20 19:33:27 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	aux_check_walls(t_tools *tools)
{
	int	o;
	int	i;
	
	o = 1;
	i = 0;
	while (o < tools->rows)
	{
		i = 0;
		if (tools->cpy_map[o][i] != '1')
			exit_message("Error: Invalid map.", tools);
		i = tools->colums - 1;
		if (tools->cpy_map[o][i] != '1')
			exit_message("Error: Invalid map.", tools);
		o++;
	}
}

void	check_walls(t_tools *tools)
{
	int	i;
	int	o;

	o = 0;
	i = 0;
	if (!tools->cpy_map || !tools->cpy_map[0])
		exit_message("Error.", tools);
	while (tools->cpy_map[0][i] != '\n')
	{
		if (tools->cpy_map[0][i] != '1')
			exit_message("Error: Invalid map.", tools);
		i++;
	}
	aux_check_walls(tools);
	i = 0;
	o = tools->rows - 1;
	while (tools->cpy_map[o][i] != '\0')
	{
		if (tools->cpy_map[o][i] != '1')
			exit_message("Error: Invalid map.", tools);
		i++;
	}
}

void	check_coins(t_tools *tools)
{
	int	check;
	int	i;
	int	o;

	check = 0;
	i = 0;
	while (tools->cpy_map[i] != NULL)
	{
		o = 0;
		while (tools->cpy_map[i][o])
		{
			if (tools->cpy_map[i][o] == 'C')
				check++;
			o++;
		}
		i++;
	}
	tools->coins = check;
	if (check == 0)
		exit_message("Error: Coins not found.", tools);
}

void	doubble_items(t_tools *tools, char letter, char *message)
{
	int	check;
	int	i;
	int	o;

	check = 0;
	i = 0;
	while (tools->cpy_map[i] != NULL)
	{
		o = 0;
		while (tools->cpy_map[i][o])
		{
			if (tools->cpy_map[i][o] == letter)
				check++;
			if (check > 1)
				exit_message(message, tools);
			o++;
		}
		i++;
	}
}

void	parc_map(t_tools *tools)
{
	int	i;
	int	ln;

	i = 0;
	while (tools->cpy_map[i] != NULL)
	{
		ln = 0;
		ln = ft_strlen(tools->cpy_map[i]);
		if (tools->cpy_map[i][ln - 1] == '\n')
			ln--;
		if (ln != tools->colums)
			exit_message("Error: Invalid map.", tools);
		i++;
	}
	doubble_items(tools, 'P', "Error: Doubble player.");
	doubble_items(tools, 'E', "Error: Doubble exit.");
	check_coins(tools);
	check_walls(tools);
	floot_fill(tools);
}
