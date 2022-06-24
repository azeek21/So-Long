/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 05:14:58 by malton            #+#    #+#             */
/*   Updated: 2022/06/16 10:05:17 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_ber(char *s)
{
	int	len;

	len = ft_strlen(s, '\0');
	if (len <= 4)
		return (0);
	len--;
	if (s[len] != 'r' || s[len - 1] != 'e' || s[len - 2] != 'b'
		|| s[len - 3] != '.')
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
	{
		ft_printf("Wrong argc !\n");
		return (0);
	}
	if (!is_ber(av[1]))
	{
		ft_printf("Error\nWrong map file extension !\n");
		return (0);
	}
	initialize_mlx(&mlx, av[1]);
	init_images(&mlx);
	new_img(&mlx, 1);
	draw_map(&mlx);
	init_hooks(&mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
