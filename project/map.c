/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:57:07 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/16 15:20:19 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void count(int fd, t_data *game)
{
	int l;
	int s;
	char *line;
	
	l = 0;
	s = 0;
	line = get_next_line(fd);
	while(line[s] != '\0')
		s++;
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		l++;
	}
	game->width = s;
	game->height = l;
}

static void alocc_map(t_data *game, int fd)
{
	int i;
	char *line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = line;
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

int map_read(t_data *game, char **argv)
{
	int fd;
	int i;
 
	fd = open(argv[1], O_RDONLY);
	i = 0;
	//game = ft_calloc(sizeof(t_data), 1);
	count(fd, game);
	game->map = (char **)malloc(sizeof(char *) * game->height + 1);
	while (i <= game->height)
	{
		game->map[i] = malloc((game->width + 1) * sizeof(char));
		i++;
	}
	alocc_map(game, fd);
	// return_map(game);
	close(fd);
	return(0);
}
// static void return_map(t_data *game)
// {
// 	int i;
// 	int j;
// 	i = 0;

// 	while (game->map[i])
// 	{
// 		j = 0;
// 		while(game->map[i][j] != '\0')
// 		{
// 			printf("%s", game->map[i]);
// 			j++;
// 		printf("\n");
// 		}
// 		i++;
// 	}
// }