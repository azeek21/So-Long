/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 13:23:37 by malton            #+#    #+#             */
/*   Updated: 2022/06/19 13:23:38 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_player(t_mlx *MLX)
{	
	int			width;
	int			height;
	t_images	*i;
	void		*m;

	i = MLX->images;
	m = MLX->mlx;
	i->p[0] = mlx_xpm_file_to_image(m, "../images/cat1.xpm", &width, &height);
	i->p[1] = mlx_xpm_file_to_image(m, "../images/cat2.xpm", &width, &height);
	i->p[2] = mlx_xpm_file_to_image(m, "../images/cat3.xpm", &width, &height);
	i->p[3] = mlx_xpm_file_to_image(m, "../images/cat4.xpm", &width, &height);
	i->p[4] = mlx_xpm_file_to_image(m, "../images/cat5.xpm", &width, &height);
	if (!(i->p[0] && i->p[1] && i->p[2] && i->p[3] && i->p[4]))
		ft_exit(MLX, 4);
	return (1);
}

int	load_enemy(t_mlx *MLX)
{	
	int			width;
	int			height;
	t_images	*i;
	void		*m;

	i = MLX->images;
	m = MLX->mlx;
	i->e[0] = mlx_xpm_file_to_image(m, "../images/dog1.xpm", &width, &height);
	i->e[1] = mlx_xpm_file_to_image(m, "../images/dog2.xpm", &width, &height);
	i->e[2] = mlx_xpm_file_to_image(m, "../images/dog3.xpm", &width, &height);
	i->e[3] = mlx_xpm_file_to_image(m, "../images/dog4.xpm", &width, &height);
	i->e[4] = mlx_xpm_file_to_image(m, "../images/dog5.xpm", &width, &height);
	if (!(i->e[0] && i->e[1] && i->e[2] && i->e[3] && i->e[4]))
		ft_exit(MLX, 4);
	return (1);
}

int	load_collectible(t_mlx *MLX)
{	
	int			width;
	int			height;
	t_images	*i;
	void		*m;

	i = MLX->images;
	m = MLX->mlx;
	i->c[0] = mlx_xpm_file_to_image(m, "../images/mouse1.xpm", &width, &height);
	i->c[1] = mlx_xpm_file_to_image(m, "../images/mouse2.xpm", &width, &height);
	i->c[2] = mlx_xpm_file_to_image(m, "../images/mouse3.xpm", &width, &height);
	i->c[3] = mlx_xpm_file_to_image(m, "../images/mouse4.xpm", &width, &height);
	i->c[4] = mlx_xpm_file_to_image(m, "../images/mouse5.xpm", &width, &height);
	if (!(i->c[0] && i->c[1] && i->c[2] && i->c[3] && i->c[4]))
		ft_exit(MLX, 4);
	return (1);
}

int	load_out(t_mlx *MLX)
{	
	int			width;
	int			height;
	t_images	*i;
	void		*m;

	i = MLX->images;
	m = MLX->mlx;
	i->o[0] = mlx_xpm_file_to_image(m, "../images/out1.xpm", &width, &height);
	i->o[1] = mlx_xpm_file_to_image(m, "../images/out2.xpm", &width, &height);
	i->o[2] = mlx_xpm_file_to_image(m, "../images/out3.xpm", &width, &height);
	i->o[3] = mlx_xpm_file_to_image(m, "../images/out4.xpm", &width, &height);
	i->o[4] = mlx_xpm_file_to_image(m, "../images/out5.xpm", &width, &height);
	if (!(i->o[0] && i->o[1] && i->o[2] && i->o[3] && i->o[4]))
		ft_exit(MLX, 4);
	return (1);
}

int	load_win(t_mlx *MLX)
{	
	int			width;
	int			height;
	t_images	*i;
	void		*m;

	i = MLX->images;
	m = MLX->mlx;
	i->w[0] = mlx_xpm_file_to_image(m, "../images/sleep1.xpm", &width, &height);
	i->w[1] = mlx_xpm_file_to_image(m, "../images/sleep2.xpm", &width, &height);
	i->w[2] = mlx_xpm_file_to_image(m, "../images/sleep3.xpm", &width, &height);
	i->w[3] = mlx_xpm_file_to_image(m, "../images/sleep4.xpm", &width, &height);
	i->w[4] = mlx_xpm_file_to_image(m, "../images/sleep5.xpm", &width, &height);
	if (!(i->w[0] && i->w[1] && i->w[2] && i->w[3] && i->w[4]))
		ft_exit(MLX, 4);
	return (1);
}
