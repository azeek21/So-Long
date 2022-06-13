#include "so_long.h"



int main(int ac, char **av){
    t_mlx   MLX;
    void    *img;
    int width;
    int height;
    char path[] = "images/wall.xpm";
    printf("ac = %d\n", ac);
    if (ac != 2){
        printf("Wrong argc !\n");
        return (0);
    }
    initialize_mlx(&MLX, av[1]);
    draw_map(&MLX);
    if (!img)
        printf("\n\nNONE !\n\n");
    init_hooks(&MLX);

    mlx_loop(MLX.mlx); 
    return (0);
}