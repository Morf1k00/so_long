/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 15:50:00 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/24 17:35:54 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static	int	ft_len(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;

	len = ft_len(n);
	num = malloc(len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
		num[0] = '-';
	if (n == -2147483648)
	{
		num[1] = '2';
		n += 2000000000;
	}
	if (n < 0)
		n *= -1;
	while (n)
	{
		num[--len] = n % 10 + '0';
		n /= 10;
	}
	return (num);
}

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
			(game.height + 1) * 64 + 30, "so_long");
	image_in_window(&game);
	graphics_map(&game);
	//mlx_string_put(game.mlx, game.mlx_win, (game.width * 64 / 2),((game.height + 1) * 64 + 15),  0xFFFFFF, ft_itoa(game.colecteble));
	mlx_hook(game.mlx_win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, key_cross, &game);
	mlx_loop(game.mlx);
}
