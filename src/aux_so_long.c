/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:42:40 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/20 19:50:33 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**cpy_map(t_tools *tools)
{
	int	i;
	char **map;

	i = 0;
	map = (char **)malloc((tools->rows + 1) * sizeof(char *));
	if (!map)
		exit_message("Error", tools);
	while (i < tools->rows)
	{
		map[i] = ft_strdup(tools->cpy_map[i]);
		i++;
	}
	map[i] = NULL;
	return(map);
}

void	search_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return;
 			}
			j++;
		}
		i++;
	}
}

void	aux_fill(t_tools *tools, char **map, int x, int y)
{
	if (x < 0 || x >= tools->rows || y < 0 || y >= tools->colums)
			return ;
	if (map[x][y] == '1' || map[x][y] == 'F')
			return ;
	map[x][y] = 'F';
	aux_fill(tools, map, x + 1, y);
	aux_fill(tools, map, x - 1, y);
	aux_fill(tools, map, x, y + 1);
	aux_fill(tools, map, x, y - 1);
}

void	floot_fill(t_tools *tools)
{
	char	**map;
	int		i;

	i = 0;
	map = cpy_map(tools);
	search_player(map, &tools->player_x, &tools->player_y);
	aux_fill(tools, map, tools->player_x, tools->player_y);
	while (map[i])
	{
		if (ft_strchr(map[i], 'C') || ft_strchr(map[i], 'E'))
		{
			free_map(map);
			exit_message("Error: Not playable", tools);
		}
		i++;
	}
	free_map(map);
}

void	open_map(char *args, t_tools *tools)
{
	char	*line;
	int		fd;
	char	**temp_map;

	fd = open(args, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	line = get_next_line(fd);
	tools->colums = (int)(strlen(line) - 1);
	temp_map = (char **)malloc(40 * sizeof(char *));
	if (!temp_map)
		exit(EXIT_FAILURE);
	while (line && *line != '\0')
	{
		temp_map[tools->rows] = ft_strdup(line);
		if (!temp_map[tools->rows])
			exit(EXIT_FAILURE);
		free(line);
		tools->rows++;
		line = get_next_line(fd);
	}
	temp_map[tools->rows] = NULL;
	tools->cpy_map = temp_map;
	close(fd);
}
