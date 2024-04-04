/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:02:56 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/04 19:20:55 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
typedef struct s_data{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}			t_data;

int main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		x = 60;
	int		y = 60;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1280, 960, "Morfik");
	while(x <= 120 && y <= 120)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		x++;
		y++;
	}
	while(x <= 180 && y >= 60)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		x++;
		y--;
	}
	while (x >= 120 && y >= 0)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		x--;
		y--;
	}
	while(x>= 60 && y <= 60)
	{
		mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		x--;
		y++;
	}
	mlx_loop(mlx);
}