/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:15:40 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 05:15:41 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_mlx *MLX)
{
	int	width;
	int	height;

	MLX->images->wall = mlx_xpm_file_to_image(MLX->mlx, "images/wall2.xpm",
			&width, &height);
	MLX->images->player = mlx_xpm_file_to_image(MLX->mlx, "images/cat.xpm",
			&width, &height);
	MLX->images->collectible = mlx_xpm_file_to_image(MLX->mlx,
			"images/mouse.xpm", &width, &height);
	MLX->images->door = mlx_xpm_file_to_image(MLX->mlx, "images/pillow.xpm",
			&width, &height);
	MLX->images->win = mlx_xpm_file_to_image(MLX->mlx, "images/win.xpm",
			&width, &height);
	MLX->images->enemy = mlx_xpm_file_to_image(MLX->mlx, "images/dog.xpm",
			&width, &height);
	if (!MLX->images->wall || !MLX->images->player || !MLX->images->collectible
		|| !MLX->images->door || !MLX->images->enemy || !MLX->images->win)
		ft_exit(MLX, 4);
}

int	new_img(t_mlx *MLX, int is_new)
{
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img));
	if (!img)
		return (0);
	if (is_new)
	{
		MLX->img = img;
		MLX->img->img = mlx_new_image(MLX->mlx, MLX->width, MLX->height);
		MLX->img->addr = mlx_get_data_addr(MLX->img->img,
				&MLX->img->bpp, &MLX->img->line_length, &MLX->img->endian);
	}
	else
	{
		mlx_destroy_image(MLX->mlx, MLX->img->img);
		MLX->img->img = mlx_new_image(MLX->mlx, MLX->width, MLX->height);
		MLX->img->addr = mlx_get_data_addr(MLX->img->img, &MLX->img->bpp,
				&MLX->img->line_length, &MLX->img->endian);
	}
	if (!MLX->img->img || !MLX->img->addr)
		return (0);
	return (1);
}

int	loop_hook(t_mlx *MLX)
{
	draw_map(MLX);
	return (0);
}

void	init_hooks(t_mlx *MLX)
{
	mlx_key_hook(MLX->win, listener, MLX);
	mlx_hook(MLX->win, 17, 0, my_close, MLX);
	mlx_loop_hook(MLX->mlx, loop_hook, MLX);
}

void	initialize_mlx(t_mlx *MLX, char *file)
{
	MLX->map = (t_map *)malloc(sizeof(t_map));
	if (!get_map(file, MLX->map))
		ft_exit(MLX, 1);
	MLX->mlx = mlx_init();
	MLX->images = (t_images *)malloc(sizeof(t_images));
	MLX->block_height = 75;
	MLX->block_width = 75;
	MLX->map->gap = 0;
	MLX->img_location[0] = 50;
	MLX->img_location[1] = 30;
	MLX->height = MLX->map->height * MLX->block_height + MLX->map->gap
		+ (MLX->img_location[1]) + 10;
	MLX->width = MLX->map->width * MLX->block_height + MLX->map->gap
		+ (MLX->img_location[0] * 2);
	MLX->counter = 0;
	MLX->won = 0;
	MLX->win = mlx_new_window(MLX->mlx, MLX->width, MLX->height, "GAME");
	if (!MLX->win || !MLX->mlx)
		ft_exit(MLX, 3);
	if (!new_img(MLX, 1) || !MLX->images)
		ft_exit(MLX, 5);
}
