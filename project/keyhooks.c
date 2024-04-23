/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:27:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/23 13:52:31 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_cross(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	while (i <= data->height)
		free(data->map[i++]);
	exit(0);
}

int	key_hook(int keycode, t_data *game)
{
	int	move;
	int	i;

	if (keycode == 53)
	{
		i = 0;
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_printf("\n CLOSE GAME \n\n");
		free(game->mlx);
		while (i <= (game->height))
			free(game->map[i++]);
		exit(0);
	}
	if (keycode == 13)
		move = keyboard_vertical(game, keycode);
	if (keycode == 1)
		move = keyboard_vertical(game, keycode);
	if (keycode == 0)
		move = keyboard_horisontal(game, keycode);
	if (keycode == 2)
		move = keyboard_horisontal(game, keycode);
	graphics_map(game);
	return (1);
}
