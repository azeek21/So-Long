/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:16:03 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 05:16:05 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	listener(int keycode, t_mlx *MLX)
{
	if (keycode == ESCAPE)
		my_close(MLX);
	else if (keycode == RIGHT_MAC)
		move_right(MLX);
	else if (keycode == DOWN_MAC)
		move_down(MLX);
	else if (keycode == LEFT_MAC)
		move_left(MLX);
	else if (keycode == UP_MAC)
		move_up(MLX);
	else if (keycode == BACKSPACE_MAC)
		clear(MLX);
	return (0);
}
