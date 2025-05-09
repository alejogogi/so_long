/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 06:56:58 by alejogogi         #+#    #+#             */
/*   Updated: 2025/05/09 22:54:58 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	ln;
	size_t	i;
	char	*cop;

	ln = 0;
	i = 0;
	ln = ft_strlen(str);
	cop = (char *)malloc((ln + 1) * sizeof(char));
	if (!cop)
	{
		return (0);
	}
	while (i <= ln)
	{
		cop[i] = str[i];
		i++;
	}
	return (cop);
}

/*
int	main(void)
{
	const char	*orig = "hola mundo";
	char		*cop;

	cop = ft_strdup(orig);
	if (cop != NULL)
	{
		printf("cadena original %s\n", orig);
		printf("cadena copiada %s\n", cop);
		free(cop);
	}
	else
	{
		printf("error al duplicar la cadena. \n");
	}
	return(0);
}
*/