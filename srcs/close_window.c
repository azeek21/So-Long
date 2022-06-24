/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:15:54 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 05:15:56 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_mlx *MLX, int err)
{
	(void)	MLX;
	ft_printf("Error\n");
	if (err == 1)
		ft_printf("Map error. Broken map or invalid file !\n");
	else if (err == 3)
		ft_printf("Can't create game essentials !\n");
	else if (err == 5)
		ft_printf("Can't create Images !\n");
	else if (err == 4)
		ft_printf("Files not found or less memory !");
	exit(1);
}

void	ft_free_images(t_images *IMAGES)
{
	free(IMAGES->wall);
	IMAGES->wall = ((void *)0);
}

int	my_close(t_mlx *MLX)
{
	int	i;

	i = 0;
	mlx_destroy_window(MLX->mlx, MLX->win);
	while (i < MLX->map->height)
	{
		free(MLX->map->map[i]);
		MLX->map->map[i] = ((void *)0);
		i++;
	}
	free(MLX->map->map);
	MLX->map->map = ((void *)0);
	free(MLX->map->map_str);
	MLX->map->map_str = ((void *)0);
	free(MLX->map);
	MLX->map = ((void *)0);
	free(MLX->img->img);
	MLX->img->img = ((void *)0);
	free(MLX->img->addr);
	MLX->img->addr = ((void *)0);
	free(MLX->map);
	MLX->img = ((void *)0);
	free(MLX->images);
	MLX->images = ((void *)0);
	ft_printf("\n");
	exit(0);
}

int	clear(t_mlx *MLX)
{
	mlx_clear_window(MLX->mlx, MLX->win);
	return (0);
}
