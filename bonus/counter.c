/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:14:47 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 05:14:52 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	update_counter(t_mlx *MLX, int color)
{
	(void) color;
	if (MLX->counter >= 0)
		MLX->counter = MLX->counter + 1;
	return (0);
}

int	put_counter(t_mlx *MLX, int color)
{
	int		x;
	int		y;
	char	*string;

	x = MLX->counter_location[0];
	y = MLX->counter_location[1];
	if (BONUS)
	{
		if (MLX->won)
			mlx_string_put(MLX->mlx, MLX->win, x, y, GREEN, "YOU WON !");
		else
		{
			string = ft_itoa(MLX->counter);
			mlx_string_put(MLX->mlx, MLX->win, x, y, color, string);
			free(string);
			return (0);
		}
	}
	if (MLX->counter >= 0)
	{
		string = ft_itoa(MLX->counter);
		ft_printf("\r");
		ft_printf(string);
	}
	else if (MLX->counter == -1)
		ft_printf("\rYOU WON !");
	return (0);
}
