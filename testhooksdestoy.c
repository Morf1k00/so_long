/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testhooksdestoy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:27:49 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/09 17:27:51 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
	
}			t_data;

int key_cross(t_data *data)// close windows when i press red cross 
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

int	key_hook(int keycode, t_data *data)
{
	int		x = 10;
	int		y = 10;
	if (keycode == 53){// exit when press ESC
		//printf("Hi , the key code of this bitton is : %d\n", keycode);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == 13)// print top line on square
	{
		while (x <= 110)
		{	mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x00FF0000);
			x++;}
	}
	if (keycode == 0) // print left line on  square
	{	while (y <= 110)
		{	mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x00FF0000);
			y++;}
	}
	if (keycode == 1) // print bootom line on square
	{
		x = 110;
		y = 110;
		while(x >= 11)
		{mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x00FF0000);
		x--;}
	}
	if (keycode == 2) // print right line on square
	{
		y = 110;
		x = 110;
		while(y >= 11)
		{	mlx_pixel_put(data->mlx, data->mlx_win, x, y, 0x00FF0000);
		y--;}
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
	
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1280, 960, "Morfik");
	
	mlx_key_hook(data.mlx_win, key_hook, &data);// reading keys
	mlx_hook(data.mlx_win, 17, 1L<<0, key_cross, &data);// waiting when someone press red cross
	mlx_loop(data.mlx);
}