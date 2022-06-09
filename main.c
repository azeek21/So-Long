#include "so_long.h"

int main(){
    t_mlx   MLX;

    MLX.mlx = mlx_init();
	MLX.win = mlx_new_window(MLX.mlx, 400, 300, "G A M E");

    printf("Window created!\n");
    MLX.img->img = mlx_new_image(MLX.mlx, 400, 300);
    MLX.img->addr = mlx_get_data_addr(MLX.img->img, &MLX.img->bpp, &MLX.img->line_length, &MLX.img->endian);
    printf("Img created!\n");

    MLX.img->x = 20;
    MLX.img->y = 20;
    MLX.width = 400;
    MLX.height = 300;
    MLX.counter_location[0] = MLX.width / 2;
    MLX.counter_location[1] = 10;
    MLX.counter = 0;
    printf("X: %d, Y: %d\n", MLX.img->x, MLX.img->y);
	mlx_put_image_to_window(MLX.mlx, MLX.win, MLX.img->img, 0, 0);
    printf("Img shown\n");
    init_hooks(&MLX);
    // init_hooks(&MLX);
    printf("Hook init!\n");
	mlx_loop(MLX.mlx);
}