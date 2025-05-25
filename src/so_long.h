/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:46:04 by alejagom          #+#    #+#             */
/*   Updated: 2025/05/24 19:00:59 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tools
{
	void	*window;
	void	*back;
	void	*player;
	void	*player_move;
	void	*walls_img;
	void	*coins_img;
	void	*exit_p;
	void	*exit_end;
	void	*mlx;
	int		moves;
	int		img_moves;
	int		coins;
	int		colums;
	int		rows;
	int		size_x;
	int		size_y;
	int		player_x;
	int		player_y;
	char	**cpy_map;
}			t_tools;

void		check_ber(char *maps);
void		open_map(char *args, t_tools *tools);
void		parc_map(t_tools *tools);
void		valid_args(t_tools *tools);
void		free_map(char **map);
void		free_tools(t_tools *tools);
void		start_game(t_tools *tools);
void		draw_img(char letter, t_tools *tools, int i, int j);
void		exit_message(char *error, t_tools *tools);
void		floot_fill(t_tools *tools);
void		check_images(t_tools *tools);
void		draw_map(t_tools *tools);
int			move_key(int key, t_tools *tools);
void		close_game(char *str, t_tools *tools);
void		replace_exit_w(t_tools *kit);
void		w_key(t_tools *tools);
void		replace_exit_s(t_tools *kit);
void		s_key(t_tools *tools);
void		replace_exit_a(t_tools *tools);
void		a_key(t_tools *tools);
void		replace_exit_d(t_tools *tools);
void		d_key(t_tools *tools);
void		moves(t_tools *tools);

#endif
