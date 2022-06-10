#include "so_long.h"

void map_print(t_mlx *MLX){
    int x; 
    int y;

    y = 0;
    printf("Y: %d | X: %d\n", MLX->MAP->height, MLX->MAP->width);
    while (y < MLX->MAP->height)
    {
        x = 0;
        while (x < MLX->MAP->width)
        {
            printf(" %c |", MLX->MAP->map[y][x]);
            x++;
        }
        printf("\n");
        y++;
    }
    
}


int main(){
    t_mlx   MLX;
    
    initialize_mlx(&MLX);
    map_print(&MLX);
    // printf("Height: %d\n", MLX.MAP->height);

    // while (y < MLX.MAP->height){
    //     printf("%s\n", MLX.MAP->map[y]);
    //     y++;
    // }

    // new_img(&MLX, 1);
    // draw_map(&MLX);
    // // init_hooks(&MLX);
	// mlx_loop(MLX.mlx);
}