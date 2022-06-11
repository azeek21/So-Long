#include "so_long.h"

void	color_sorter(t_mlx *MLX, int x, int y){
	int		color;
	char	block;

	printf("SORTING COLOR! CHAR = %c\n", MLX->MAP->map[x][y]);
	block = MLX->MAP->map[y][x];
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
	printf("COLOR CHOSEN !\n");
}


void	draw_map(t_mlx *MLX){
	printf("STARTED DRAWING MAP!\n");
	int x;
	int	y;
	int xstart;
	int	ystart;

	y = 0;
	printf("HEIGHT | %d\n", MLX->MAP->height);
	printf("WIDTH | %d\n", MLX->MAP->width);

	while (y < MLX->MAP->height){
		x = 0;
		printf("MAP AT: X: %d | Y: %d\n", x, y);
		while (x < MLX->MAP->width){
			xstart = (x * MLX->block_width) + (x * MLX->MAP->gap);
			ystart = (y * MLX->block_height) + (y * MLX->MAP->gap);
			color_sorter(MLX, x, y);
			draw_square(MLX, xstart, ystart, MLX->cur_col);
			x++;
		}
		y++;
	}
	printf("MAP DRAWN, putting to window !\n");
	mlx_put_image_to_window(MLX->mlx, MLX->win, MLX->img->img, 0, 0);
	printf("IMG SUCCESFULLY SHOWN !\n");
}
