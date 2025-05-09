/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 20:26:39 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/09 23:28:16 by alejogogi        ###   ########.fr       */
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
int	main(int av, char **args)
{
	t_tools	tools;
	
	check_args(av, args);
	open_map(args[1], &tools);
	return (0);
}