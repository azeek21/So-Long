#include "so_long.h"


int	ft_strchr(char *s, char c, char stop){
	int i;
	int found;

	i = 0;
	while (s[i] && s[i] != stop){
		if (s[i] == c){
			found = 1;
			break;
		}
		i++;
	}
	if (!found)
		return (-1);
	return (i);
}

int	char_count(char *str, char c, char stop){
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] && str[i] != stop)
	{
		if (str[i] == c)
			res++;
		i++;
	}
	
	return (res);
}


int	ft_strlen(char *s, char stop){
	int	i;

	i = 0;
	while (s[i] && s[i] != stop){
		i++;
	}
	return (i);
}

void	clean_console(){
  printf("\033[2J");
  printf("\033[%d;%dH", 0, 0);
	
}

int	map_check(t_map *MAP){
	int	i;
	int	j;
	char c;

	i = 0;
	j = 0;
	if ( (!walls_check(MAP)) || MAP->player < 1 || MAP->enemy < 1  || MAP->collectible < 1 || MAP->width < 3 || MAP-> height < 3)
		return (0);
	while (MAP->map_str[i] && i < MAP->map_length){
		if (ft_strlen(&MAP->map_str[i], '\n') != MAP->width || MAP->map_str[MAP->map_length - 1] == '\n')
			return (0);
		i = i + MAP->width + 1;
	}
	while (MAP->map_str[j])
	{
		c = MAP->map_str[j];
		if (!(c == '1' || c == '0' || c == 'C' || c == 'P' || c == 'E' || c == '\n'))
			return (0);
		j++;
	}

	return (1);
}
