/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:26:39 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/24 00:26:10 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_args(int av, char **args)
{
	if (av != 2)
	{
		if (av == 1)
			ft_printf("Error: (add a map)\n");
		else
			ft_printf("Error: (Too many maps)\n");
		exit(EXIT_FAILURE);
	}
	check_ber(args[1]);
}

void	check_ber(char *maps)
{
	int		i;
	char	*ber;

	ber = ".ber";
	i = ft_strlen(maps);
	if (i < 4 || ft_strncmp(&maps[i - 4], ber, 4) != 0)
	{
		ft_printf("Error: Invalid map (no .ber)\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int av, char **args)
{
	t_tools		*tools;

	tools = malloc(sizeof(t_tools));
	if (!tools)
		return (0);
	check_args(av, args);
	open_map(args[1], tools);
	parc_map(tools);
	start_game(tools);
	return (0);
}
