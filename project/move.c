/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:52:12 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/23 14:18:04 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_event_help(t_data *game, int i, int j)
{
	if (game->map[i][j] == '0' || game->map[i][j] == 'C')
	{
		game->map[i][j] = 'P';
		game->x = i;
		game->y = j;
	}
	if (game->map[i][j] == 'C')
	{
		game->map[i][j] = 'P';
		game->x = i;
		game->y = j;
		game->colecteble--;
	}
}

static void	died_player(t_data *game, int i, int j)
{
	if (game->map[i][j] == 'X')
	{
		ft_printf("\n\t\033[0;31m\033[1m   YOU DIED\n");
		key_cross(game);
	}
}

int	check_event(t_data *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		if (game->colecteble != 0)
			return (0);
		game->map[i][j] = 'P';
		game->x = i;
		game->y = j;
		ft_printf("\n\t\033[0;32m\033[1mYOU WIN\n\n");
		key_cross(game);
	}
	if (game->map[i][j] == '0')
		check_event_help(game, i, j);
	if (game->map[i][j] == 'C')
		check_event_help(game, i, j);
	if (game->map[i][j] == 'X')
		died_player(game, i, j);
	game->steps++;
	return (1);
}

int	keyboard_vertical(t_data *game, int keycode)
{
	int	i;

	i = 0;
	if (keycode == 13)
		i = move_s(game);
	else if (keycode == 1)
		i = move_w(game);
	ft_printf("\t\033[0;34m\033[1mSteps taken: %i\n", game->steps);
	return (i);
}

int	keyboard_horisontal(t_data *game, int keycode)
{
	int	i;

	i = 0;
	if (keycode == 0)
		i = move_a(game);
	else if (keycode == 2)
		i = move_d(game);
	ft_printf("\t\033[0;34m\033[1mSteps taken: %i\n", game->steps);
	return (i);
}
