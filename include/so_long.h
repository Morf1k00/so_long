/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:56 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/18 17:11:30 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include "../gnl/get_next_line.h"


typedef struct s_data{
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

//-void	*ft_calloc(size_t count, size_t size);
void 	map_read(t_data *game, char **argv);
void	image_in_window(t_data *game);
void	graphics_map(t_data *game);
int		key_cross(t_data *data);
int		key_hook(int keycode, t_data *data);
void	player_position(t_data *game, int w, int h);
int		ft_printf(const char *s, ...);
int	keyboard_horisontal(t_data *game, int keycode);
int	keyboard_vertical(t_data *game, int keycode);

#endif