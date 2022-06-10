#include "so_long.h"

void	move_right(t_mlx *MLX){

	if (MLX->width > MLX->img->x + 70){
		// new_img(MLX, 0);
		printf("RIGHT\n\tX: %d, Width: %d\n", MLX->img->x, MLX->width);
		(MLX->img->x) = MLX->img->x + 40;
		draw_square(MLX, 30, 30, 0x781bf2);
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->img->img, 0, 0);
		update_counter(MLX, BLUE);
	}
	else
		printf("Nah Bro!");
}

void	move_down(t_mlx *MLX){

	if (MLX->height > MLX->img->y + 50){
		// new_img(MLX, 0);
		(MLX->img->y) = MLX->img->y + 40;
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->img->img, 0, 0);
		draw_square(MLX, 30, 30, 0x781bf2);
		update_counter(MLX, BLUE);
	}
	else
		printf("Nah Bro!");
}


void	move_left(t_mlx *MLX){

	printf("LEFT\n");
	if (MLX->img->x - 30 >= 10){
		// new_img(MLX, 0);
		(MLX->img->x) = MLX->img->x - 40;
		draw_square(MLX, 30, 30, 0x781bf2);
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->img->img, 0, 0);
		update_counter(MLX, BLUE);
	}
	else
		printf("Nah Bro!");
}

void	move_up(t_mlx *MLX){

	if (MLX->img->y - 30 >= 10){
		// new_img(MLX, 0);
		(MLX->img->y) = MLX->img->y - 40;
		draw_square(MLX, 30, 30, 0x781bf2);
		mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->img->img, 0, 0);
		update_counter(MLX, BLUE);
	}
	else
		printf("Nah Bro!");
}

int	update_counter(t_mlx *MLX, int color){
	int	x;
	int	y;

	x = MLX->counter_location[0];
	y = MLX->counter_location[1];
	MLX->counter = MLX->counter + 1;
	char *string;

	string = ft_itoa(MLX->counter);
	mlx_string_put(MLX->mlx, MLX->win, x, y, color, string);
	printf("COUNTER UPDATE: %d\n", MLX->counter);
}