/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:26:55 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/17 14:11:15 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void image_in_window(t_data *game)
{
	int i;
	int j;
	
	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &i, &j);
	game->item = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlx, "textures/enemy.xpm", &i, &j);
}

void graphics_map(t_data *game)
{
	int h;
	int w;

	
	w = 0;
	h = 0;
	while(h <= game->height)
	{
		w = 0;
		while(w <= game->width)
		{
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->wall, w * 64, h * 64);
			else if(game->map[h][w] == '0')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->floor, w * 64, h * 64);
			if(game->map[h][w] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->enemy, w * 64, h * 64);
			else if (game->map[h][w] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->item, w * 64, h * 64);
			else if (game->map[h][w] == 'X')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->exit, w * 64, h * 64);
			else if (game->map[h][w] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win, game->player, w * 64, h * 64);
			w++;
		}
		h++;
	}
}