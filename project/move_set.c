/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 13:27:43 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/26 18:02:27 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	move_s(t_data *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	i--;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i + 1][j] = '0';
	return (1);
}

int	move_w(t_data *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	i++;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i - 1][j] = '0';
	return (1);
}

int	move_a(t_data *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	j--;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i][j + 1] = '0';
	return (1);
}

int	move_d(t_data *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	j++;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i][j - 1] = '0';
	return (1);
}
