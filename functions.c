# include "so_long.h"


void	open_map(char *path, char *buf){
	int	fd;
	int	rd;

	fd = open(path, O_RDONLY);
	if (!fd){
		printf("File not found !\n");
		exit(1);
	}
	rd = read(fd, buf, 100);
	if (!rd){		
		printf("Can't read file !\n");
		exit(1);
	}
	close(fd);
}


int	walls_check(t_map *MAP){
	int	y;
	int top;
	int	bot;

	y = 0;
	top = char_count(&MAP->map_str[0], '1', '\n');
	bot = char_count(&MAP->map_str[MAP->map_length - MAP->width], '1', '\0');
	if ((bot != top || top != MAP->width))
		return (0);
	while (y < MAP->map_length)
	{
		if (MAP->map_str[y] != '1' || MAP->map_str[y + MAP->width - 1] != '1')
			return (0);
		y = y + MAP->width + 1;
	}
	return (1);

}

void	map_copy(t_map *MAP){
	int x;
	int y;
	int i;

	y = 0;
	MAP->map = (char **)malloc(sizeof(char *) * MAP->height);
	while (y < MAP->height){
		MAP->map[y] = (char *)malloc(sizeof(char) * (MAP->width  + 1));
		MAP->map[y][MAP->width] = '\0';
		y++;
	}
	y = 0;
	i = 0;
	while (y < MAP->height)
	{
		x = 0;
		while (x < MAP->width)
		{
			MAP->map[y][x] =  MAP->map_str[i];
			x++;
			i++;
		}
		i++;
		y++;
	}
}

void	init_map(t_map *MAP){
	MAP->player = char_count(MAP->map_str, 'P', '\0');
	MAP->enemy = char_count(MAP->map_str, 'E', '\0');
	MAP->collectible = char_count(MAP->map_str, 'C', '\0');
	MAP->height = char_count(MAP->map_str, '\n', '\0') + 1;
	MAP->width = ft_strlen(MAP->map_str, '\n');
	MAP->map_length = ft_strlen(MAP->map_str, '\0');

	if (!map_check(MAP)){
		printf("MAP ERROR !\n");
		exit(1);
	}
	MAP->player_position[0] = 0;
	MAP->player_position[1] = 0;
	while (MAP->map_str[MAP->player_position[0]]){
		if (MAP->map_str[MAP->player_position[0]] == '\n')
			MAP->player_position[1] = MAP->player_position[1] + 1;
		if (MAP->map_str[MAP->player_position[0]] == 'P'){
			MAP->player_position[0] = MAP->player_position[0] % MAP->width - MAP->player_position[1];
			break;
		}
		MAP->player_position[0] = MAP->player_position[0] + 1;
	}
	map_copy(MAP);
}

void	get_map(char *path, t_map *MAP){
	MAP->map_str = (char *)malloc(sizeof(char)*1000);
	
	open_map(path, MAP->map_str);
	init_map(MAP);
}