/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:26:39 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/11 22:44:59 by alejogogi        ###   ########.fr       */
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
	}
	free(tools);
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
	free_tools(tools);
	return (0);
}
