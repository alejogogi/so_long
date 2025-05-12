/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:42:40 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/12 21:06:57 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cpy_map(t_tools *tools, char **map)
{
	int	i;

	i = 0;
	map = (char **)malloc((tools->rows + 1) * sizeof(char *));
	if (!map)
		exit_message("Error", tools);
	while (map[i] < tools->rows)
	{
		map[i] = ft_strdup(tools->cpy_map[i]);
		i++;
	}
}

void	floot_fill(t_tools *tools)
{
	char	**map;
	int		i;

	i = 0;
	cpy_map(tools, map);
	fill(tools, map, tools->player_x, tools->player_y);//quedo aqui para hacer el fill que rellena el mapa, no quiero copiarme :).
	while (map[i])
	{
		if (ft_strchr(map[i], 'C') || ft_strchr(map[i], 'E'))
			exit_message("Error: Not playable", tools);
		i++;
	}
}

void	check_ber(char *maps)
{
	int		i;
	char	*ber;

	ber = ".ber";
	i = ft_strlen(maps);
	//ft_strncmp(&maps[ì -4]) se desplaza a la posicion desde la que quiero que compare.
	if (i < 4 || ft_strncmp(&maps[i - 4], ber, 4) != 0)
	{
		ft_printf("Error: Invalid map (no .ber)\n");
		exit(EXIT_FAILURE);
	}
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
