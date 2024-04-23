/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_help_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:30:41 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/23 17:32:22 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_len(t_data *game)
{
	int	w;
	int	h;
	int	w1;

	h = 0;
	w = 0;
	while (h <= game->height - 1)
	{
		if (w == 0)
			w = ft_strlen(game->map[h]);
		h++;
		w1 = ft_strlen(game->map[h]);
		if (w != w1)
			return (0);
	}
	return (1);
}

int	close_map(t_data *game)
{
	int	w;
	int	h;

	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w + 1] != '\0')
		{
			if (game->map[h][w] != '1')
				return (0);
			w++;
		}
		while (h++ < game->height)
			if (game->map[h][0] != '1' && game->map[h][w - 1] != '1')
				return (0);
		w = 0;
		while (h == game->height && game->map[h][w + 1] != '\0')
		{
			if (game->map[h][w] != '1')
				return (0);
			w++;
		}
	}
	return (1);
}

int	exit_point(t_data *game)
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

int	check_player(t_data *game)
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

int	check_coin(t_data *game)
{
	int	c;
	int	w;
	int	h;

	c = 0;
	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'C')
			{
				if (close_coin(game, h, w) != 1)
					return (0);
				c++;
			}
			w++;
		}
		h++;
	}
	return (c);
}
