/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 21:32:33 by malton            #+#    #+#             */
/*   Updated: 2022/06/19 21:32:35 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	locate_c2d(char *str, char c, int location[2])
{
	int	x;
	int	y;
	int	len;

	len = ft_strlen(str, '\n');
	x = 0;
	y = 0;
	while (str[x])
	{
		if (str[x] == '\n')
			y++;
		if (str[x] == c)
		{
			x = x - ((len + 1) * y);
			break ;
		}
		x++;
	}
	location[0] = x;
	location[1] = y;	
}

// 	MAP->player_position[0] = 0;
// 	MAP->player_position[1] = 0;
// 	while (MAP->map_str[MAP->player_position[0]])
// 	{
// 		if (MAP->map_str[MAP->player_position[0]] == '\n')
// 			MAP->player_position[1] = MAP->player_position[1] + 1;
// 	if (MAP->map_str[MAP->player_position[0]] == 'P')
// 	{
// 		MAP->player_position[0] = MAP->player_position[0]
// 			- ((MAP->width + 1) * MAP->player_position[1]);
// 		break ;
// 	}
// 	MAP->player_position[0] = MAP->player_position[0] + 1;
// }