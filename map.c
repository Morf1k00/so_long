/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:57:07 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/10 18:31:17 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int count_line(int fd)
{
	int i;
	char *line;
	
	i = 0;
	line = get_next_line(fd);
	while (1)
	{
		if(line != NULL)
		{
			line = get_next_line(fd);
			i++;
		}
		else
			break ;
	}
	return (i);
}
static int count_columns(int fd)
{
	int i;
	char *line;

	i = 0;
	line = get_next_line(fd);
	while(line !='\0')
	{
		line++;
		i++;
	}
	return(i);
}

void map_read(t_data *game, char **argv)
{
	char readmap;
	int i;
	
	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return(0);
	i = 0;
	game->height = count_line(game->fd);
	game->width = count_columns(game->fd);
	game->map = (char **)malloc(sizeof(char *) * game->height + 1);
	while (i < game->height)
	{
		game->map = (char *)malloc((game->width + 1) * sizeof(char));
		i++;
	}
	close(game->fd);
}