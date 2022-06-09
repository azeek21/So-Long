
#include "so_long.h"

void	put_pixel(t_img *img, int x, int y, int color){
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_mlx *MLX, int width, int height, int color){
	int tw;

	tw = width;
	printf("Drawing square\n\tx: %d, y: %d\n", MLX->img->x, MLX->img->y);
	while (height){
		width = tw;
		while (width)
		{
			put_pixel(MLX->img, MLX->img->x + width, MLX->img->y + height, color);
			width--;
		}
		height--;
	}
}
