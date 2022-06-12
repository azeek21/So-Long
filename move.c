#include "so_long.h"

int	is_safetomove(t_mlx *MLX, int next_p[2]){
	char next_c;

	next_c = MLX->MAP->map[next_p[1]][next_p[0]];
	printf("NEXT-> %c\n", next_c);
	if (next_c == '1')
		return (0);
	else if (next_c == 'E')
		// winning
	return (1);
}

int	move(t_mlx *MLX, int from[2], int to[2]){
	MLX->MAP->map[from[1]][from[0]] = '0';
	MLX->MAP->map[to[1]][to[0]] = 'P';
	MLX->MAP->player_position[0] = to[0];
	MLX->MAP->player_position[1] = to[1];
}







void	move_right(t_mlx *MLX){
	int	next[2];

	next[0] = MLX->MAP->player_position[0] + 1;
	next[1] = MLX->MAP->player_position[1];
	if (is_safetomove(MLX, next))
	{
		move(MLX, MLX->MAP->player_position, next);
		new_img(MLX, 0);
		draw_map(MLX);
		update_counter(MLX, BLUE);
	}
	else
		printf("NAAH !\n");
}

void	move_down(t_mlx *MLX){
	int	next[2];

	next[0] = MLX->MAP->player_position[0];
	next[1] = MLX->MAP->player_position[1] + 1;

	if (is_safetomove(MLX, next)){
		move(MLX, MLX->MAP->player_position, next);
		new_img(MLX, 0);
		draw_map(MLX);
		update_counter(MLX, BLUE);
	}
	else
		printf("Nah Bro!");
}


void	move_left(t_mlx *MLX){
	int	next[2];

	next[0] = MLX->MAP->player_position[0] - 1;
	next[1] = MLX->MAP->player_position[1];

	if (is_safetomove(MLX, next)){
		move(MLX, MLX->MAP->player_position, next);
		new_img(MLX, 0);
		draw_map(MLX);
		update_counter(MLX, BLUE);
	}
	else
		printf("Nah Bro!");
}

void	move_up(t_mlx *MLX){
	int	next[2];

	next[0] = MLX->MAP->player_position[0];
	next[1] = MLX->MAP->player_position[1] - 1;

	if (is_safetomove(MLX, next)){
		move(MLX, MLX->MAP->player_position, next);
		new_img(MLX, 0);
		draw_map(MLX);
		update_counter(MLX, BLUE);
	}
	else
		printf("Nah Bro!");
}

int	update_counter(t_mlx *MLX, int color){
	int	x;
	int	y;

	x = MLX->counter_location[0];
	y = MLX->counter_location[1];
	MLX->counter = MLX->counter + 1;
	char *string;

	string = ft_itoa(MLX->counter);
	mlx_string_put(MLX->mlx, MLX->win, x, y, color, string);
	printf("COUNTER UPDATE: %d\n", MLX->counter);
}