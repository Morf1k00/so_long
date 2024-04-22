/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:30:41 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/22 15:22:32 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	map_len(t_data *game)
{
	int	w;
	int	h;
	int	w1;

	h = 0;
	while (h <= game->height)
	{
		if (w == 0)
			w = ft_strlen(game->map[h]);
		h++;
		w1 = ft_strlen(game->map[h]);
		if (w == w1)
			return (0);
		w = w1;
	}
	return (1);
}

static int	close_map(t_data *game)
{
	int	w;
	int	h;

	h = 0;
	while (game->map[h][w])
	{
		w = 0;
		while (game->map[h][w] != '\0')
		{
			if (game->map[h][w] != '1')
				return (0);
			w++;
		}
		h++;
		while (h <= game->height - 1)
		{
			if (game->map[h][0] != '1' && game->map[h][w] != '1')
				return (0);
			h++;
		}
		w = 0;
		while (game->map[h][w] != '\0')
		{
			if (game->map[h][w] != '1')
				return (0);
			w++;
		}
	}
	return (1);
}

static int	exit_point(t_data *game)
{
	int	e;
	int	w;
	int	h;

	e = 0;
	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'E')
				e++;
			w++;
		}
		h++;
	}
	return (e);
}

static int	check_player(t_data *game)
{
	int	p;
	int	w;
	int	h;

	p = 0;
	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'P')
				p++;
			w++;
		}
		h++;
	}
	return (p);
}

int	map_checker(t_data *game)
{
	if (map_len(game) != 1)
		return(perror);
	if (close_map(game) != 1)
		return(perror);
	if (exit_point(game) != 1)
		return(perror);
	if (check_player(game) != 1)
		return(perror);
}
