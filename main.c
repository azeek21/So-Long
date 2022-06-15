#include "so_long.h"


void    intit_bg(t_mlx *MLX, int color){
    int x;
    int y;

    x = 0;
    y = 0;
    while (y < MLX->height){
        x = 0;
        while (x < MLX->width){
            put_pixel(MLX->IMG, x, y, GREEN);
            x++;
        }
        y++;
        printf("Y\n");
    }
    // mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->IMG->img, 0, 0);
    printf("BG PUT !\n\n");
}

void    init_images(t_mlx *MLX){
    int width;
    int height;

    printf("WIDTH: %d\n\n", MLX->block_width);
    MLX->IMAGES->wall = mlx_xpm_file_to_image(MLX->mlx, "images/wall2.xpm", &width, &height);
    MLX->IMAGES->player = mlx_xpm_file_to_image(MLX->mlx, "images/cat3.xpm", &width, &height);
    MLX->IMAGES->collectible = mlx_xpm_file_to_image(MLX->mlx, "images/mouse.xpm", &width, &height);
    MLX->IMAGES->door = mlx_xpm_file_to_image(MLX->mlx, "images/pillow.xpm", &width, &height);
}










int main(int ac, char **av){
    t_mlx   MLX;

    if (ac != 2){
        printf("Wrong argc !\n");
        return (0);
    }
    initialize_mlx(&MLX, av[1]);

    init_images(&MLX);
    // new_img(&MLX, 1);
    // intit_bg(&MLX, GREEN);
    
    draw_map(&MLX);
    init_hooks(&MLX);

    mlx_loop(MLX.mlx); 
    return (0);
}