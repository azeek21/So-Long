#include "so_long.h"



int main(){
    t_mlx   MLX;
  
    initialize_mlx(&MLX);
    draw_map(&MLX);

    mlx_loop(MLX.mlx); 
    return (0);
}