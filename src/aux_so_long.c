/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:42:40 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/09 23:16:55 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ber(char *maps)
{
	int	i;
	char *ber = ".ber";

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
	int	fd;
	char	**temp_map;

	fd = open(args, O_RDONLY);
	line = get_next_line(fd);
	if (!line)
		exit(EXIT_FAILURE);
	tools->colums = (int)(strlen(line) - 1);
	temp_map = (char **)malloc(40 * sizeof(char *));
	if (!temp_map)
		exit(EXIT_FAILURE);
	while (line != NULL)
	{
		temp_map[tools->rows] = ft_strdup(line);
		free(line);
		tools->rows++;
		line = get_next_line(fd);
	}
	temp_map[tools->rows] = NULL;
	tools->cpy_map = temp_map;
	close(fd);
}