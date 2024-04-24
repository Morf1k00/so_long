/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:26:55 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/24 17:49:40 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_position(t_data *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player, w * 64, h * 64);
	game->x = w;
	game->y = h;
}

void	place_coin(t_data *game, int w, int h)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->item, w * 64, h * 64);
	game->colecteble++;
	mlx_string_put(game->mlx, game->mlx_win, (game->width * 64 / 2),((game->height + 1) * 64 + 15),  0xFFFFFF, ft_itoa(game->colecteble));
}

void	image_in_window(t_data *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &i, &j);
	game->item = mlx_xpm_file_to_image(game->mlx,
			"textures/coin.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &i, &j);
	game->bl = mlx_xpm_file_to_image(game->mlx, "textures/black.xpm", &i, &j);
}

static void	help_map(t_data *game, int w, int h)
{
	if (game->map[h][w] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall, w * 64, h * 64);
	else if (game->map[h][w] == '0')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->floor, w * 64, h * 64);
	else if (game->map[h][w] == 'X')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->enemy, w * 64, h * 64);
	else if (game->map[h][w] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, w * 64, h * 64);
}

void	graphics_map(t_data *game)
{
	int	h;
	int	w;
	int c;

	h = 0;
	game->colecteble = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == '1'
				|| game->map[h][w] == '0'
				|| game->map[h][w] == 'X'
				|| game->map[h][w] == 'E')
				help_map(game, w, h);
			else if (game->map[h][w] == 'C')
				place_coin(game, w, h);
			else if (game->map[h][w] == 'P')
				player_position(game, w, h);
			w++;
		}
		h++;
	}
	c = game->colecteble;
	if (game->colecteble != 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->bl, (game->width * 64 / 2) - 15  ,(game->height + 1) * 64 );
		mlx_string_put(game->mlx, game->mlx_win, (game->width * 64 / 2),((game->height + 1) * 64 + 15),  0xFFFFFF, ft_itoa(c));
	}
		
}
