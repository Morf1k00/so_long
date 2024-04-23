/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:56 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/23 17:26:45 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include "../gnl/get_next_line.h"

# define ERR_MAP_REC "MAP NOT RECTANGULAR"
# define ERR_CLOSE "MAP NOT CLOSE"
# define ERR_EXIT "MAP HAVE 0 OR MORE 1 EXIT"
# define ERR_PLAYER "MAP DONT HAVE PLAYER OR MORE 1 ON MAP"
# define ERR_MAP "PROBLEM WITH MAP"
# define ERR_WAY "WRONG WAY TO MAP OR MAP DOESNT EXISTS\n"
# define ERR_COIN "0 COIN ON MAP or coin closed by walls"
# define ERR_EXIT2 "CLOSE EXIT"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*player;
	void	*item;
	void	*enemy;

	char	**map;

	int		x;
	int		y;
	int		fd;
	int		colecteble;
	int		height;
	int		width;
	int		score;
	int		countscore;
	int		steps;

}			t_data;

void	map_read(t_data *game, char **argv);
void	image_in_window(t_data *game);
void	graphics_map(t_data *game);
int		key_cross(t_data *data);
int		key_hook(int keycode, t_data *data);
void	player_position(t_data *game, int w, int h);
int		ft_printf(const char *s, ...);
int		keyboard_horisontal(t_data *game, int keycode);
int		keyboard_vertical(t_data *game, int keycode);
void	map_checker(t_data *game);
int		map_len(t_data *game);
int		close_map(t_data *game);
int		exit_point(t_data *game);
int		check_player(t_data *game);
int		check_coin(t_data *game);
int		msg(char *err);
int 	move_a(t_data *game);
int 	move_d(t_data *game);
int		move_s(t_data *game);
int		move_w(t_data *game);
int		check_event(t_data *game, int i, int j);
int 	close_coin(t_data *game, int h, int w);

#endif