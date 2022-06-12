#include "so_long.h"


int	listener(int keycode, t_mlx *MLX)
{

	printf("\n%d\n", keycode);
	printf("SIZE:%li\n", sizeof((*MLX)));
	if (keycode == 65307)
		my_close(MLX);
	else if (keycode == 100)
		move_right(MLX);
	else if (keycode == 115)
		move_down(MLX);
	else if (keycode == 97)
		move_left(MLX);
	else if (keycode == 119)
		move_up(MLX);
	else if (keycode == 65288)
		clear(MLX);
	return (0);
}

int my_close(t_mlx *MLX){
	int	i;

	i = 0;
	printf("BYE \n");
	mlx_destroy_window(MLX->mlx, MLX->win);

	while (i < MLX->MAP->height){
		free(MLX->MAP->map[i]);
		MLX->MAP->map[i] = ((void *)0);
		i++;
	}
	free(MLX->MAP->map);
	free(MLX->MAP);
	free(MLX->MAP->map_str);
	free(MLX->IMG);
	MLX->IMG = ((void *)0);
	MLX->MAP->map_str = ((void *)0);
	MLX->MAP->map = ((void *)0);
	exit(1);
}

int	clear(t_mlx *MLX){
	mlx_clear_window(MLX->mlx, MLX->win);
	MLX->counter = 0;
	MLX->IMG->x = 0;
	MLX->IMG->y = 0;
}
