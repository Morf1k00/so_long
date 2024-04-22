/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:52:12 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/19 16:13:26 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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
	game->steps++;
	return (1);
}

int	keyboard_horisontal(t_data *game, int keycode)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	if (keycode == 13)
	{
		i--;
		if (game->map[i][j] == '1')
			return (0);
		wall = check_event(game, i, j);
		if (!wall)
			return (0);
		game->map[i + 1][j] = '0';
	}
	else if (keycode == 1)
	{
		i++;
		if (game->map[i][j] == '1')
			return (0);
		wall = check_event(game, i, j);
		if (!wall)
			return (0);
		game->map[i - 1][j] = '0';
	}
	ft_printf("\t\033[0;34m\033[1mSteps taken: %i\n", game->steps);
	return (1);
}

int	keyboard_vertical(t_data *game, int keycode)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	if (keycode == 0)
	{
		j--;
		if (game->map[i][j] == '1')
			return (0);
		wall = check_event(game, i, j);
		if (!wall)
			return (0);
		game->map[i][j + 1] = '0';
	}
	else if (keycode == 2)
	{
		j++;
		if (game->map[i][j] == '1')
			return (0);
		wall = check_event(game, i, j);
		if (!wall)
			return (0);
		game->map[i][j - 1] = '0';
	}
	ft_printf("\t\033[0;34m\033[1mSteps taken: %i\n", game->steps);
	return (1);
}
