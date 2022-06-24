/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:15:25 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 05:15:27 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_bg(t_mlx *MLX, int color)
{
	int	xstart;
	int	ystart;
	int	xstop;
	int	ystop;

	xstart = MLX->img_location[0];
	ystart = MLX->img_location[1];
	xstop = MLX->block_width * MLX->map->width;
	ystop = MLX->block_height * MLX->map->height;
	while (ystart < ystop)
	{
		xstart = 0;
		while (xstart < xstop)
		{
			put_pixel(MLX->img, xstart, ystart, color);
			xstart++;
		}
		ystart++;
	}
	mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->img->img,
		MLX->img_location[0], MLX->img_location[1]);
}

void	put_block(t_mlx *MLX, unsigned long int x, unsigned long int y, char c)
{
	int	i;
	i = MLX->status;
	if (c == '1')
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->images->wall,
			x + MLX->img_location[0], y + MLX->img_location[1]);
	else if (c == 'P')
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->images->p[i],
			x + MLX->img_location[0], y + MLX->img_location[1]);
	else if (c == 'E')
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->images->door,
			x + MLX->img_location[0], y + MLX->img_location[1]);
	else if (c == 'C')
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->images->c[i],
			x + MLX->img_location[0], y + MLX->img_location[1]);
	else if (c == 'W')
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->images->w[i],
			x + MLX->img_location[0], y + MLX->img_location[1]);
	else if (c == 'F')
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->images->e[i],
			x + MLX->img_location[0], y + MLX->img_location[1]);
	else if (c == 'O')
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->images->o[i],
			x + MLX->img_location[0], y + MLX->img_location[1]);
}



void	draw_map(t_mlx *MLX)
{
	int		x;
	int		y;
	int		xstart;
	int		ystart;
	clear(MLX);
	init_bg(MLX, FLOOR);
	y = 0;
	x = 0;
	while (y < MLX->map->height)
	{
		x = 0;
		while (x < MLX->map->width)
		{
			xstart = (x * MLX->block_width) + (x * MLX->map->gap);
			ystart = (y * MLX->block_height) + (y * MLX->map->gap);
			put_block(MLX, xstart, ystart, MLX->map->map[y][x]);
			x++;
		}
		y++;
	}
	status_update(MLX);
	put_counter(MLX, WHITE);
}
