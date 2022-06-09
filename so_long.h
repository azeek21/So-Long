#ifndef SO_LONG_H
#define SO_LONG_H
#define RED 0xCC0000
#define BLUE 0x0b5394
#define WHITE 0xffffff
#define GREEN 0x449620

#include <stdio.h>
#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_img;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	t_img	*img;
	int		height;
	int		width;
	int		counter_location[2];
	int		img_location[2];
	int		counter;
}	t_mlx;


typedef struct s_map{
	char	**map;
	char	*map_str;
	int		player;
	int		enemy;
	int		collectible;
	int		map_length;
	int		width;
	int		height;
	int		player_position[2];
}	t_map;


// typedef struct s_e_m {
// 	int	ON_KEYDOWN = 2;
// 	int	ON_DESTROY = 17;
// 	int	KeyPressMask = 1L<<0;
// }	t_e_m;


// Utils

char	*ft_itoa(int n);
int		ft_strchr(char *s, char c, char stop);
int		char_count(char *str, char c, char stop);
int		ft_strlen(char *s, char stop);
int		map_check(t_map *MAP);
void	get_map(char *path, t_map *MAP);
int		walls_check(t_map *MAP);


// EVENTS
int		listener(int keycode, t_mlx *mlx);
int		my_close(t_mlx *MLX);
int		clear(t_mlx *MLX);
void	move_right(t_mlx *MLX);
void	move_down(t_mlx *MLX);
void	move_left(t_mlx *MLX);
void	move_up(t_mlx *MLX);
int		new_img(t_mlx *MLX, int is_blank);
int		init_hooks(t_mlx *MLX);
int		update_counter(t_mlx *MLX, int color);



// DRAWERS
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_square(t_mlx *MLX, int width, int height, int color);



#endif