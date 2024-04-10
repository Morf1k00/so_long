/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:00:56 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/10 18:11:00 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include <gnl/get_next_line.h>

typedef struct s_data{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*exit;
	void	*player;
	void	*item;
	void	*enemy;
	
	char	**map;
	
	int		fd;
	int		colecteble;
	int		height;
	int		width;
	int		score;
	int		countscore;
	int		steps;

	
}			t_data;
#endif