#include "so_long.h"

int	new_img(t_mlx *MLX, int is_blank){

	if (is_blank){
		mlx_destroy_image(MLX->mlx, MLX->img->img);
		MLX->img->img = mlx_new_image(MLX->mlx, 400, 300);
    	MLX->img->addr = mlx_get_data_addr(MLX->img->img, &MLX->img->bpp, &MLX->img->line_length, &MLX->img->endian);
	}

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
	// mlx_hook(MLX->win, 6, 1L<<6, mouse_movement_catch, MLX);
	// mlx_mouse_hook(MLX->win, mouse_catch, MLX);
}
