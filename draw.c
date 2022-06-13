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


void	put_block_at(t_mlx *MLX, int x,  int y, char *path){
	void	*img;
	int	width;
	int	height;

	img = mlx_xpm_file_to_image(MLX->mlx, path, &width, &height);
    mlx_put_image_to_window(MLX->mlx, MLX->win, img, x, y);
}


void	draw_map(t_mlx *MLX){
	printf("STARTED DRAWING MAP!\n");
	int x;
	int	y;
	int xstart;
	int	ystart;
	// mlx_clear_window(MLX->mlx, MLX->win);
	y = 0;
	// printf("HEIGHT | %d\n", MLX->MAP->height);
	// printf("WIDTH | %d\n", MLX->MAP->width);

	while (y < MLX->MAP->height){
		x = 0;
		// printf("MAP AT: X: %d | Y: %d\n", x, y);
		while (x < MLX->MAP->width){
			xstart = (x * MLX->block_width) + (x * MLX->MAP->gap);
			ystart = (y * MLX->block_height) + (y * MLX->MAP->gap);
			// color_sorter(MLX, x, y);
			// draw_square(MLX, xstart, ystart, MLX->cur_col);
			if (MLX->MAP->map[y][x] == '1')
				put_block_at(MLX, xstart, ystart, "images/wall.xpm");
			// printf("%c", MLX->MAP->map[y][x]);
			x++;
		}
		// printf("\n");
		y++;
	}
	// printf("MAP DRAWN, putting to window !\n");
	// mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->IMG->img, MLX->img_location[0], MLX->img_location[1]);
	// printf("IMG SUCCESFULLY SHOWN !\n");
}
