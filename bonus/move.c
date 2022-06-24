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
	if (MLX->map->map[to[1]][to[0]] == 'O')
	{
		MLX->map->map[to[1]][to[0]] = 'W';
		MLX->won = 1;
	}
	else if (!MLX->won)
		MLX->map->map[to[1]][to[0]] = 'P';
	if (MLX->won)
		MLX->map->map[MLX->map->door_position[1]][MLX->map->door_position[1]] = 'W';
	MLX->map->player_position[0] = to[0];
	MLX->map->player_position[1] = to[1];
	if (MLX->map->collectible < 1 && !MLX->won)
		MLX->map->map[MLX->map->door_position[1]][MLX->map->door_position[1]] = 'O';
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
