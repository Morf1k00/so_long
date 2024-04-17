/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:56 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/17 11:26:44 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
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
	
	int		fd;
	int		colecteble;
	int		height;
	int		width;
	int		score;
	int		countscore;
	int		steps;

	int		img_h;
	int		img_w;
	
}			t_data;

//-void	*ft_calloc(size_t count, size_t size);
void 	map_read(t_data *game, char **argv);
void	image_in_window(t_data *game);
void	graphics_map(t_data *game);
int		key_cross(t_data *data);
int		key_hook(int keycode, t_data *data);

#endif