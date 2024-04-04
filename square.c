/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:00:45 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/04 18:53:42 by rkrechun         ###   ########.fr       */
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
	int		x = 10;
	int		y = 10;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Morfik");
	while (x <= 110)
	{	mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		x++;}
	while (y <= 110)
		{mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		y++;}
	while(x >= 11)
		{mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		x--;}
	while(y >= 11)
		{mlx_pixel_put(mlx, mlx_win, x, y, 0x00FF0000);
		y--;}
	mlx_loop(mlx);
}