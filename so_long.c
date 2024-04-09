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

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	
}			t_data;

int key_cross(t_data *data)// close windows when i press red cross 
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)// exit when press ESC
	{
		//printf("Hi , the key code of this bitton is : %d\n", keycode);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, &data->img, 64, 64);

	}
	return (0);
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
int main(void)
{
	t_data	data;
	data.img = calloc();

	
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1280, 960, "Morfik");

	int w = 64;
	int h = 64;
	char	*relative_path = "../textures/pixil-frame-0.xpm";

	data.img = mlx_xpm_file_to_image(data.mlx, relative_path, &w, &h);

	mlx_xpm_file_to_image(data.mlx, relative_path, &w, &h);

	mlx_key_hook(data.mlx_win, key_hook, &data);// reading keys
	mlx_hook(data.mlx_win, 17, 1L<<0, key_cross, &data);// waiting when someone press 
	mlx_loop(data.mlx);
}