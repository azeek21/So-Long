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
	printf("BYE \n");
	mlx_destroy_window(MLX->mlx, MLX->win);
	exit(1);
}

int	clear(t_mlx *MLX){
	mlx_clear_window(MLX->mlx, MLX->win);
	MLX->counter = 0;
	MLX->img->x = 0;
	MLX->img->y = 0;
}
