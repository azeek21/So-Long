/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:16:25 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 05:16:26 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(t_mlx *MLX, int from[2], int to[2])

{
	MLX->map->map[from[1]][from[0]] = '0';
	if (MLX->map->map[to[1]][to[0]] == 'E')
		MLX->map->map[to[1]][to[0]] = 'W';
	else
		MLX->map->map[to[1]][to[0]] = 'P';
	MLX->map->player_position[0] = to[0];
	MLX->map->player_position[1] = to[1];
	return (0);
}

void	move_right(t_mlx *MLX)
{
	int	next[2];

	next[0] = MLX->map->player_position[0] + 1;
	next[1] = MLX->map->player_position[1];
	if (is_safetomove(MLX, next))
	{
		move(MLX, MLX->map->player_position, next);
		update_counter(MLX, WHITE);
	}
}

void	move_down(t_mlx *MLX)
{
	int	next[2];

	next[0] = MLX->map->player_position[0];
	next[1] = MLX->map->player_position[1] + 1;
	if (is_safetomove(MLX, next))
	{
		move(MLX, MLX->map->player_position, next);
		update_counter(MLX, WHITE);
	}
}

void	move_left(t_mlx *MLX)
{
	int	next[2];

	next[0] = MLX->map->player_position[0] - 1;
	next[1] = MLX->map->player_position[1];
	if (is_safetomove(MLX, next))
	{
		move(MLX, MLX->map->player_position, next);
		draw_map(MLX);
		update_counter(MLX, WHITE);
	}
}

void	move_up(t_mlx *MLX)
{
	int	next[2];

	next[0] = MLX->map->player_position[0];
	next[1] = MLX->map->player_position[1] - 1;
	if (is_safetomove(MLX, next))
	{
		move(MLX, MLX->map->player_position, next);
		update_counter(MLX, WHITE);
	}
}
