#include "so_long.h"

void	color_sorter(t_mlx *MLX, int x, int y){
	int		color;
	char	block;

	block = MLX->MAP->map[y][x];
	// printf("%c", block);
	if (block == '1')
		color = GREEN;
	else if (block == '0')
		color = WHITE;
	else if (block == 'P')
		color = BLUE;
	else if (block == 'E')
		color = RED;
	else if (block ==  'C')
		color = PURPLE;
	MLX->cur_col = color;
	// printf("COLOR CHOSEN !\n");
}


void	put_block(t_mlx *MLX, unsigned long int x, unsigned long int y, char c){
	void	*img;
	if (c == '1')
	    mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->IMAGES->wall, x + MLX->img_location[0], y + MLX->img_location[1]);

	else if (c == 'P')
	    mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->IMAGES->player, x + MLX->img_location[0], y + MLX->img_location[1]);
		
	else if (c == 'E')
	    mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->IMAGES->door, x + MLX->img_location[0], y + MLX->img_location[1]);

	else if (c == 'C')
	    mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->IMAGES->collectible, x + MLX->img_location[0], y + MLX->img_location[1]);

	// else if (c == '0')
		return ;

}


void	draw_map(t_mlx *MLX){
	printf("STARTED DRAWING MAP!\n\n\n");
	unsigned long int x;
	unsigned long int	y;
	unsigned long xstart;
	unsigned long ystart;
	// mlx_clear_window(MLX->mlx, MLX->win);
	y = 0;
	x = 0;
	// printf("HEIGHT | %d\n", MLX->MAP->height);
	printf("WIDTH = %d | %d \n", MLX->block_width, MLX->MAP->gap);
	while (y < MLX->MAP->height){
		x = 0;
		// printf("MAP AT: X: %d | Y: %d\n", x, y);
		while (x < MLX->MAP->width){
			xstart = (x * MLX->block_width) + (x * MLX->MAP->gap);
			ystart = (y * MLX->block_height) + (y * MLX->MAP->gap);
			// color_sorter(MLX, x, y);
			// draw_square(MLX, xstart, ystart, MLX->cur_col);
			put_block(MLX, xstart, ystart, MLX->MAP->map[y][x]);
			// printf("%ldx%ld ", (x * MLX->block_width) + (x * MLX->MAP->gap), ystart);
			// printf("%c", MLX->MAP->map[y][x]);
			x++;
		}

		printf("\n");
		y++;
	}
	// printf("MAP DRAWN, putting to window !\n");
	// mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->IMG->img, MLX->img_location[0], MLX->img_location[1]);
	printf("IMG SUCCESFULLY SHOWN !\n");
}
