#include "../main.h"
int strfind(char *arr)
{
	int i;
	
	i = 0;
	while (arr[i] && arr[i] != '\n')
	{
		if (arr[i] != '1')
		{
			return 0;
		}
		i++;
	}
	return 1;
}
int ft_strlen_x(char *s)
{
	int i;
	
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return i;
}
int ft_coins(t_game **game)
{
	int i = 0;
	int j = 0;
	int count = 0;
	while (i < (*game)->k - 1)
	{
		j = 0;
		while ((*game)->arr[i][j])
		{
			if ((*game)->arr[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return count;
}
void get_line(t_game *game, char *s)
{
	int fd = open(s, O_RDONLY);
	if (!fd)
	{
		perror("Error\n");
		exit(0);
	}
	game->k = 0;
	while (1)
	{
		game->arr[game->k] = get_next_line(fd);
		if (!game->arr[game->k])
			break;
		game->k++;
	}
	game->collect = ft_coins(&game);
	game->coins = 0;
	game->move_count = 1;
}