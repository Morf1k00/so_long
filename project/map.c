/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrechun <rkrechun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:57:07 by rkrechun          #+#    #+#             */
/*   Updated: 2024/04/24 16:27:45 by rkrechun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int check_way(char *argv)
{
	int l;
	char *ber;
	int lb;

	ber = ".ber";
	lb = 4;
	l = ft_strlen(argv);
	while(lb > 0)
	{
		if (ber[lb] == argv[l])
		{
			lb--;
			l--;
		}
		else
			return (0);
	}
	return(1);
}

static void	count(int fd, t_data *game)
{
	int		l;
	int		s;
	char	*line;

	l = 0;
	s = 0;
	line = get_next_line(fd);
	while (line[s] != '\0')
		s++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		l++;
	}
	game->width = s - 1;
	game->height = l - 1;
}

static void	alocc_map(t_data *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	map_read(t_data *game, char **argv)
{
	int	fd;
	int	i;

	fd = open(argv[1], O_RDONLY);
	i = check_way(argv[1]);
	if (fd < 0 || i < 1)
		msg(ERR_WAY);
	count(fd, game);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	game->map = malloc(sizeof(char *) * (size_t)(game->height + 1));
	alocc_map(game, fd);
	close(fd);
}
