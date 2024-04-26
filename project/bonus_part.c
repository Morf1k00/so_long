/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:59:38 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/26 17:16:16 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	game_steps(t_data *game)
{
	int	c;

	c = game->colecteble;
	if (c > 0)
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->bl, 120, 0);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->bl, 150, 0);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->bl, 180, 0);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->bl, 210, 0);
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->bl, 240, 0);
		mlx_string_put(game->mlx, game->mlx_win, 145,
			(15), 0xFF0000, ("coin left :"));
		mlx_string_put(game->mlx, game->mlx_win, 245,
			(15), 0xFF0000, ft_itoa(c));
	}
}

void	game_counter(t_data *game)
{
	int	c;

	c = game->steps;
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->bl, 0, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->bl, 30, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->bl, 60, 0);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->bl, 90, 0);
	mlx_string_put(game->mlx, game->mlx_win, 0,
		(15), 0xFF0000, ("Steps taken:"));
	mlx_string_put(game->mlx, game->mlx_win, 100,
		(15), 0xFF0000, ft_itoa(c));
	game_steps(game);
}

// void ani_coin(t_data *game, size_t t)
// {
// 	int i;
// 	int j;

// 	if (t % 3 == 1)
// 	{
// 		game->item = mlx_xpm_file_to_image(game->mlx,
// 				"textures/coin.xpm", &i, &j);
// 	}
// 	else if (t % 3 == 2)
// 	{
// 		game->item = mlx_xpm_file_to_image(game->mlx,
// 			"textures/coin2.xpm", &i, &j);
// 	}
// 	else if (t % 3 == 3)
// 	{
// 		game->item = mlx_xpm_file_to_image(game->mlx,
// 			"textures/coin3.xpm", &i, &j);
// 	}
// }
