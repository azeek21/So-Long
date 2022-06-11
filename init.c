#include "so_long.h"

int	new_img(t_mlx *MLX, int is_new){
	t_img *IMG;

	IMG = (t_img *)malloc(sizeof(t_img));

	printf("CREATING NEW IMG !\n");
	if (is_new){
		MLX->img = IMG;
		MLX->img->img = mlx_new_image(MLX->mlx, MLX->width, MLX->height);
    	MLX->img->addr = mlx_get_data_addr(MLX->img->img, &MLX->img->bpp, &MLX->img->line_length, &MLX->img->endian);
	}
	else{
		mlx_destroy_image(MLX->mlx, MLX->img->img);
		MLX->img->img = mlx_new_image(MLX->mlx, MLX->width, MLX->height);
    	MLX->img->addr = mlx_get_data_addr(MLX->img->img, &MLX->img->bpp, &MLX->img->line_length, &MLX->img->endian);
	}
	printf("IMG SUCCESSFULY CREATED \n!");
	return (0);
}


int	mouse_catch(int button, int x, int y, t_mlx *MLX){
	printf("M-BUTTON: %d | M-X: %d | M-Y: %d\n", button, x, y);
}


int mouse_movement_catch(int x, int y, t_mlx *MLX){
	printf("M-X: %d | M-Y: %d\n", x, y);
}


int	loop_hook_check(t_mlx *MLX){
	sleep(1);
	update_counter(MLX, BLUE);
}

int	init_hooks(t_mlx *MLX){
	mlx_key_hook(MLX->win,  listener, MLX);
	mlx_hook(MLX->win, 17, 1L<<0, my_close, MLX);
	mlx_hook(MLX->win, 6, 1L<<8, mouse_movement_catch, MLX);
	mlx_mouse_hook(MLX->win, mouse_catch, MLX);
}

void initialize_mlx(t_mlx *MLX){
    t_map *MAP;

    MLX->mlx = mlx_init();
	MAP = (t_map *)malloc(sizeof(t_map));
    MLX->MAP = MAP;
    get_map("map.bar", MLX->MAP);
    MLX->height = 300;
    MLX->width = 500;
    MLX->counter_location[0] = MLX->width / 2;
    MLX->counter_location[1] = 10;
    MLX->counter = 0;
    MLX->img_location[0] = 0;
    MLX->img_location[1] = 20;
	MLX->block_height = 30;
	MLX->block_width = 30;
	MLX->MAP->gap = 5;
	MLX->win = mlx_new_window(MLX->mlx, MLX->width, MLX->height, "GAME");
	new_img(MLX, 1);
}
