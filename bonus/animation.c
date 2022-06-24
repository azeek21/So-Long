/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:34:11 by malton            #+#    #+#             */
/*   Updated: 2022/06/18 22:34:13 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	status_update(t_mlx *MLX)
{
	if (MLX->substatus < 25)
		MLX->substatus = MLX->substatus + 1;
	else 
	{
		MLX->status = MLX->status + 1;
		MLX->substatus = 0;		
	}
	if (MLX->status > 4)
		MLX->status = 1;
}


int	load_images(t_mlx *MLX)
{
	if (!(load_player(MLX) && load_enemy(MLX) && load_win(MLX)
		&& load_out(MLX) && load_collectible(MLX)))
		ft_exit(MLX, 4);
	return (1);
}
