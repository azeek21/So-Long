/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:16:18 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 05:16:19 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map(char *path, char *buf)
{
	int	fd;
	int	rd;

	fd = open(path, O_RDONLY);
	if (!fd || fd <= 0)
		return (0);
	rd = read(fd, buf, 1000);
	if (!rd || fd <= 0)
		return (0);
	close(fd);
	return (1);
}

int	walls_check(t_map *MAP)
{
	int	y;
	int	top;
	int	bot;

	y = 0;
	top = char_count(&MAP->map_str[0], '1', '\n');
	bot = char_count(&MAP->map_str[MAP->map_length - MAP->width], '1', '\0');
	if ((bot != top || top != MAP->width))
		return (0);
	while (y < MAP->map_length)
	{
		if (MAP->map_str[y] != '1' || MAP->map_str[y + MAP->width - 1] != '1')
			return (0);
		y = y + MAP->width + 1;
	}
	return (1);
}

void	map_copy(t_map *MAP)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	MAP->map = (char **)malloc(sizeof(char *) * MAP->height);
	while (y < MAP->height)
	{
		MAP->map[y] = (char *)malloc(sizeof(char) * (MAP->width + 1));
		MAP->map[y][MAP->width] = '\0';
		y++;
	}
	y = 0;
	i = 0;
	while (y < MAP->height)
	{
		x = 0;
		while (x < MAP->width)
			MAP->map[y][x++] = MAP->map_str[i++];
		i++;
		y++;
	}
}

int	init_map(t_map *MAP)
{
	MAP->player = char_count(MAP->map_str, 'P', '\0');
	MAP->enemy = char_count(MAP->map_str, 'E', '\0');
	MAP->collectible = char_count(MAP->map_str, 'C', '\0');
	MAP->height = char_count(MAP->map_str, '\n', '\0') + 1;
	MAP->width = ft_strlen(MAP->map_str, '\n');
	MAP->map_length = ft_strlen(MAP->map_str, '\0');
	if (!map_check(MAP))
		return (0);

	MAP->player_position = (int *)malloc(sizeof(int) * 2);
	MAP->door_position = (int *)malloc(sizeof(int) * 2);
	locate_c2d(MAP->map_str, 'P', MAP->player_position);
	locate_c2d(MAP->map_str, 'E', MAP->door_position);
	map_copy(MAP);
	return (1);
}

int	get_map(char *path, t_map *MAP)
{
	MAP->map_str = (char *)malloc(sizeof(char) * 1000);
	if (!MAP->map_str)
		return (0);
	if (!open_map(path, MAP->map_str))
		return (0);
	if (!init_map(MAP))
		return (0);
	return (1);
}
