
#include "so_long.h"

void	put_pixel(t_img *img, int x, int y, int color){
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_mlx *MLX, int	xstart, int ystart,int color){
	int x;
	int	y;

	y = 0;
	while (y <= MLX->block_height){
		x = 0;
		while (x <= MLX->block_width)
		{
			put_pixel(MLX->img->img, xstart + x, ystart + y, color);
			x++;
		}
		y++;
	}
}
