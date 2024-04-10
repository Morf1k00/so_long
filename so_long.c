// /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:58:13 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/09 17:03:02 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

int key_cross(t_data *data)// close windows when i press red cross 
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	//printf("Hi , the key code of this bitton is : %d\n", keycode);
	if (keycode == 53)// exit when press ESC
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	return (0);
}

int main()
{
	t_data	game;
	int h = 0;
	int w = 0;
	
	memset(&game, 0, sizeof(t_data));
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1280, 960, "so_long");
	game.wall = mlx_xpm_file_to_image(game.mlx, "textures/pixil-frame-0.xpm", &w, &h);
	if (game.wall)
		mlx_put_image_to_window(game.mlx, game.mlx_win, game.wall, 0, 0);

	mlx_key_hook(game.mlx_win, key_hook, &game);// reading keys
	mlx_hook(game.mlx_win, 17, 0, key_cross, &game);// waiting when someone press cross
	mlx_loop(game.mlx);
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