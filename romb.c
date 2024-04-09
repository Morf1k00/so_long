/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:02:56 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/09 15:57:24 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
	
}			t_data;

// enum {
// 	ON_KEYDOWN = 2,
// 	ON_KEYUP = 3,
// 	ON_MOUSEDOWN = 4,
// 	ON_MOUSEUP = 5,
// 	ON_MOUSEMOVE = 6,
// 	ON_EXPOSE = 12,
// 	ON_DESTROY = 17
// };

int close( t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	return(0);
}

int main(void)
{
	int		x = 60;
	int		y = 60;
	t_data	data;

	// ON_KEYDOWN = close(2, data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1280, 960, "Morfik");
	while(x <= 120 && y <= 120)
	{
		mlx_pixel_put(data.mlx, data.mlx_win, x, y, 0x00FF0000);
		x++;
		y++;
	}
	while(x <= 180 && y >= 60)
	{
		mlx_pixel_put(data.mlx, data.mlx_win, x, y, 0x00FF0000);
		x++;
		y--;
	}
	while (x >= 120 && y >= 0)
	{
		mlx_pixel_put(data.mlx, data.mlx_win, x, y, 0x00FF0000);
		x--;
		y--;
	}
	while(x>= 60 && y <= 60)
	{
		mlx_pixel_put(data.mlx, data.mlx_win, x, y, 0x00FF0000);
		x--;
		y++;
	}
	// mlx_hook(data.mlx_win, 17, 1L<<8, close, data.mlx);
	mlx_key_hook(data.mlx, close, data.mlx_win);
	mlx_loop(data.mlx);
	
}