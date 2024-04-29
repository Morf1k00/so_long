/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 14:59:38 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/29 10:40:16 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	game_steps(t_data *game)
{
	char * c;
	
	c = ft_itoa(game->colecteble);
	if (game->colecteble > 0)
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
			(15), 0xFF0000, c);
	}
	free(c);
}

void	game_counter(t_data *game)
{
	char *c;

	c = ft_itoa(game->steps);
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
		(15), 0xFF0000, c);
	free(c);
	game_steps(game);
}
