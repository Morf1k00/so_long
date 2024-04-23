/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:50:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/23 17:32:27 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int	main(int argc, char **argv)
{
	t_data	game;

	if (argc != 2)
		msg(ERR_WAY);
	ft_memset(&game, 0, sizeof(t_data));
	map_read(&game, argv);
	map_checker(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, game.width * 64,
			(game.height + 1) * 64, "so_long");
	image_in_window(&game);
	graphics_map(&game);
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, key_cross, &game);
	mlx_loop(game.mlx);
}
