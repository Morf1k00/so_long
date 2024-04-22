/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:09:13 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/22 18:31:31 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int msg(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	exit(1);
}

void	map_checker(t_data *game)
{
	if (map_len(game) != 1)
		msg(ERR_MAP_REC);
	if (close_map(game) != 1)
		msg(ERR_CLOSE);
	if (exit_point(game) != 1)
		msg(ERR_EXIT);
	if (check_player(game) != 1)
		msg(ERR_PLAYER);
	if (check_coin(game) < 1)
		msg(ERR_COIN);
}
