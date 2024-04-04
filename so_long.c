/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:00:45 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/04 16:02:16 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int main(void)
// {
// 	void *mlx_ptr;
// 	void *win_ptr;
 
// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
// 	win_ptr = mlx_new_window(mlx_ptr, 600, 400, "hi :)");
// 	if (!win_ptr)
// 		return (free(mlx_ptr), 1);
// 	mlx_destroy_window(mlx_ptr, win_ptr);
// 	mlx_destroy_display(mlx_ptr);
// 	free(mlx_ptr);
// 	return (0);
// }
int main(void)
{
	void *mlx;
	void *mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
}