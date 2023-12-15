#include <mlx.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "main.h"





typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	
			t_data;
typedef struct s_collect {
	int collect;
} t_coll;
int player_check_col(t_game ****game)
{
	int i;

	i = 0;
	int j;
	while (i < (***game)->k)
	{
		j = 0;
		while ((***game)->arr[i][j] != '\0')
		{
			if ((***game)->arr[i][j] == 'P')
				return j;
			j++;
		}
		i++;
	}
	return j;
}
int player_check_row(t_game ****game)
{
	int i = 0;
	int j;
	while (i < (***game)->k)
	{
		j = 0;
		while ((***game)->arr[i][j] != '\0')
		{
			if ((***game)->arr[i][j] == 'P')
				return i;
			j++;
		}
		i++;
	}
	return i;
}
size_t	ft_strlen_for_printing_moves(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
char	*ft_strdup(const char *s)
{
	char		*dst;
	size_t		size;
	int			i;

	size = ft_strlen_for_printing_moves(s);
	dst = (char *)malloc(sizeof(char) * (size + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}
char *ft_itoa(int n)
{
	int		len;
	char	*s;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * (len + 5 + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	len--;
	while (len >= 0 && n > 0)
	{
		s[len] = (n % 10) + 48;
		n /= 10;
		len--;
	}

	return s;
}
void render_text_on_the_window(t_game ****game)
{
	char *s = ft_itoa((***game)->move_count++);
	(***game)->img = mlx_xpm_file_to_image((***game)->mlx, "./img/wall1.xpm", &(***game)->img_width, &(***game)->img_height);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 0, 0);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 65, 0);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 130, 0);
	mlx_put_image_to_window((***game)->mlx, (***game)->win, (***game)->img, 194, 0);
	mlx_string_put((***game)->mlx, (***game)->win, 0, 0, 0x00FF0000, "move");
	mlx_string_put((***game)->mlx, (***game)->win, 50, 0, 0x00FF0000, s);
}
void lost()
{
	write(1, "WA 3LA KA3KA3\n", 15);
	exit(0);
}
void won()
{
	write(1, "YOU WON\n", 9);
	exit(0);
}
int check_right(t_game ***game)
{
	int row; 
	int col;
	
	col = player_check_col(&game);
	row = player_check_row(&game);
	if ((**game)->arr[row][col + 1] == '1')
		return 0;
	else if ((**game)->arr[row][col + 1] == 'M')
		lost();
	else if ((**game)->arr[row][col + 1] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row][col + 1] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row][col + 1] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, (col + 1) * 65, row * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}
int check_left(t_game ***game)
{
	int row;
	int col;
	
	col = player_check_col(&game);
	row = player_check_row(&game);
	if ((**game)->arr[row][col - 1] == '1')
		return 0;
	else if ((**game)->arr[row][col - 1] == 'M')
		lost();
	else if ((**game)->arr[row][col - 1] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row][col - 1] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row][col - 1] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, (col - 1) * 65, row * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}
int check_down(t_game ***game)
{

	int row = player_check_row(&game);

	int col = player_check_col(&game);

	if ((**game)->arr[row + 1][col] == '1')
		return 0;
	else if ((**game)->arr[row + 1][col] == 'M')
		lost();
	else if ((**game)->arr[row + 1][col] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row + 1][col] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row + 1][col] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, col * 65, (row + 1) * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}
int check_up(t_game ***game)
{

	int row = player_check_row(&game);
	int col = player_check_col(&game);
	if ((**game)->arr[row - 1][col] == '1')
		return 0;
	else if ((**game)->arr[row - 1][col] == 'M')
		lost();
	else if ((**game)->arr[row - 1][col] == 'E' && (**game)->coins == (**game)->collect)
		won();
	else if (((**game)->arr[row - 1][col] == 'E' && (**game)->coins != (**game)->collect))
		return 0;
	else if ((**game)->arr[row - 1][col] == 'C')
	{
		(**game)->img = mlx_xpm_file_to_image((**game)->mlx, "./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
		mlx_put_image_to_window((**game)->mlx, (**game)->win, (**game)->img, col * 65, (row - 1) * 65);
		(**game)->coins++;
	}
	render_text_on_the_window(&game);
	return (1);
}

void to_right(t_game **game)
{
	if (check_right(&game) == 1)
	{
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_x += 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/worrior.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
	}

}
void to_left(t_game **game)
{
	if (check_left(&game) == 1)
	{
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_x -= 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/worrior.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
	}
}
void to_up(t_game **game)
{
	if (check_up(&game) == 1)
	{
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_y -= 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/worrior.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
	}
}
void to_down(t_game **game)
{
	if (check_down(&game) == 1)
	{
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_y += 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/worrior.xpm", &(*game)->img_width, &(*game)->img_height);
		mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->pos_x, (*game)->pos_y);
	}
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

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == UP || keycode == DOWN || keycode == LEFT || keycode == RIGHT)
	{
		if (keycode == RIGHT)
			to_right(&game);
		else if (keycode == LEFT)
			to_left(&game);
		else if (keycode == UP)
			to_up(&game);
		else if (keycode == DOWN)
			to_down(&game);
	}
	return (0);
}
int ft_strlen_x(char *s)
{
	int i;
	
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return i;
}


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
int	main(int ac, char *av[])
{
	t_game game;

	if (ac < 1)
	{
		printf("Erorr\n");
		exit(0);
	}
	valid_name(av[1]);
	get_line(&game, av[1]);
	if (map_check(&game) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, ft_strlen_x(game.arr[0]) * 65, game.k * 65, "so long");
	map(&game);
	if (flood_fill(&game) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_hook(game.win,02, 0, key_hook, &game);
	mlx_loop(game.mlx);
}
