/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:27:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/18 18:03:18 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int key_cross(t_data *data)// close windows when i press red cross 
{
	int i;

	i = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	while(i <= data->height)
		free(data->map[i++]);
	free(data->mlx);
	exit(0);
}

int	key_hook(int keycode, t_data *game)
{
	int	move;

	if (keycode == 53)// exit when press ESC
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_printf("\n CLOSE GAME \n\n");
		exit(0);
	}
	if (keycode == 13) // go top 
		move = keyboard_horisontal(game, keycode);
	if (keycode == 1) // go bootom
		move = keyboard_horisontal(game, keycode);
	if (keycode == 0) // go left
		move = keyboard_vertical(game, keycode);
	if (keycode == 2) // go right
		move = keyboard_vertical(game, keycode);
	graphics_map(game);
	return (1);
}

// w is keycode 13
// s is keycode 1
// a is keycode 0
// d is caycode 2
// enum {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_MOUSEDOWN = 4,
// 	ON_MOUSEUP = 5,
// 	ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17
// };
// int main(void)
// {
// 	t_data	data;
	
// 	data.mlx = mlx_init();
// 	data.mlx_win = mlx_new_window(data.mlx, 1280, 960, "Morfik");
	
// 	mlx_key_hook(data.mlx_win, key_hook, &data);// reading keys
// 	mlx_hook(data.mlx_win, 17, 1L<<0, key_cross, &data);// waiting when someone press red cross
// 	mlx_loop(data.mlx);
// }