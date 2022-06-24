/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 04:08:54 by malton            #+#    #+#             */
/*   Updated: 2022/06/18 04:08:57 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define RED 0xCC0000
# define BLUE 0x0b5394
# define WHITE 0xffffff
# define GREEN 0x449620
# define PURPLE 0xaa52ed
# define FLOOR 0xEFB632
# define UP_MAC 13
# define LEFT_MAC 0
# define DOWN_MAC 1
# define RIGHT_MAC 2
# define ESCAPE 53
# define BACKSPACE_MAC 51
# define BONUS 1

# include <stdio.h>
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		x;
	int		y;
}				t_img;

typedef struct s_images
{
	void	*wall;
	void	*player;
	void	*collectible;
	void	*door;
	void	*out;
	void	*enemy;
	void	*win;
	void	*p[5];
	void	*e[5];
	void	*c[5];
	void	*o[5];
	void	*w[5];
	int		width;
	int		height;
}	t_images;

typedef struct s_map{
	char	**map;
	char	*map_str;
	int		player;
	int		enemy;
	int		collectible;
	int		map_length;
	int		width;
	int		height;
	int		gap;
	int		*player_position;
	int		*door_position;
}	t_map;

typedef struct s_mlx {
	void		*mlx;
	void		*win;
	t_img		*img;
	t_images	*images;	
	t_map		*map;
	int			height;
	int			width;
	int			counter_location[2];
	int			img_location[2];
	int			counter;
	int			block_width;
	int			block_height;
	int			cur_col;
	int			won;
	int			status;
	int			substatus;
}	t_mlx;

char	*ft_itoa(int n);
int		ft_printf(char *s);
int		ft_strchr(char *s, char c, char stop);
int		char_count(char *str, char c, char stop);
int		ft_strlen(char *s, char stop);
int		map_check(t_map *MAP);
int		walls_check(t_map *MAP);
void	initialize_mlx(t_mlx *MLX, char *file);
int		open_map(char *path, char *buf);
int		walls_check(t_map *MAP);
void	map_copy(t_map *MAP);
int		init_map(t_map *MAP);
int		get_map(char *path, t_map *MAP);
int		is_safetomove(t_mlx *MLX, int next_p[2]);
void	intit_bg(t_mlx *MLX, int color);
void	init_images(t_mlx *MLX);
int		listener(int keycode, t_mlx *mlx);
int		my_close(t_mlx *MLX);
int		clear(t_mlx *MLX);
void	move_right(t_mlx *MLX);
void	move_down(t_mlx *MLX);
void	move_left(t_mlx *MLX);
void	move_up(t_mlx *MLX);
int		new_img(t_mlx *MLX, int is_new);
void	init_hooks(t_mlx *MLX);
int		update_counter(t_mlx *MLX, int color);
int		put_counter(t_mlx *MLX, int color);
int		loop_hook(t_mlx *MLX);
void	ft_exit(t_mlx *MLX, int err);
int		move(t_mlx *MLX, int from[2], int to[2]);
void	put_pixel(t_img *img, int x, int y, int color);
void	draw_map(t_mlx *MLX);
void	init_bg(t_mlx *MLX, int color);
void	put_block(t_mlx *MLX, unsigned long int x, unsigned long int y, char c);
void	status_update(t_mlx *MLX);
void	locate_c2d(char *str, char c, int location[2]);

// loaders
int		load_images(t_mlx *MLX);
int		load_player(t_mlx *MLX);
int		load_enemy(t_mlx *MLX);
int		load_collectible(t_mlx *MLX);
int		load_out(t_mlx *MLX);
int		load_win(t_mlx *MLX);

#endif
