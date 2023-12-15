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
void render_wall(t_game **game)
{
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/wall1.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
}
void render_ground(t_game **game)
{
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
}
void render_monster(t_game **game)
{
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/monster.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
}
void render_door(t_game **game)
{
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/closed_door.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
}
void render_player(t_game **game)
{
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
	(*game)->img = mlx_xpm_file_to_image((*game)->mlx, "./img/worrior.xpm", &(*game)->img_width, &(*game)->img_height);
    mlx_put_image_to_window((*game)->mlx, (*game)->win, (*game)->img,(*game)->x, (*game)->y);
	(*game)->pos_x = (*game)->x;
	(*game)->pos_y = (*game)->y;
	(*game)->g = 'P';
}

void map(t_game *game)
{
	int i = 0;
	int j = 0;

	while (j < game->k)
	{
		i = 0;
		while (game->arr[j][i])
		{
			if (game->arr[j][i] == '1')
				render_wall(&game);
			else if (game->arr[j][i] == '0')
				render_ground(&game);
			else if (game->arr[j][i] == 'M')
				render_monster(&game);
			else if (game->arr[j][i] == 'E')
				render_door(&game);
			else if (game->arr[j][i] == 'P')
				render_player(&game);
			game->x += 65;
			i++;
		}
		game->x = 0;
		game->y += 65;
		j++;
    }
}
int first_c(char **arr, int k)
{
    int len;
    int i;
	
	i = 1;
	len = ft_strlen_x(arr[0]);
	if (!len)
		return 0;
    while (i < k - 1)
    {
        if (ft_strlen_x(arr[i]) != len)
            return 0;
        i++;
    }
    return 1;
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
int second_c(char **arr,int k)
{
	if (strncmp(arr[0], arr[k - 1], ft_strlen_x(arr[0])) != 0)
		return 0;
	if (strfind(arr[0]) == 0 && strfind(arr[k - 1]) == 0)
		return 0;
	int i = 1;
	while (i < k - 1)
	{
		if (arr[i][0] != arr[i][ft_strlen_x(arr[i]) - 1] && arr[i][ft_strlen_x(arr[i]) - 1] != '1')
			return 0;
		i++;
	}
	return 1;
}

int third_c_case(int a, int b, int c,int d)
{
	if (a > 0)
		return 0;
	if (b != 1)
		return 0;
	if (d != 1)
		return 0;
	if (c < 1)
		return 0;
	return 1;
}
void positions_check(t_game ***game)
{
	int i;
	int j;
	
	j = 0;
	i = -1;
	while (++i < (**game)->k)
	{
		j = 0;
		while ((**game)->arr[i][j] && (**game)->arr[i][j] != '\n')
		{
			if ((**game)->arr[i][j] == '1' || (**game)->arr[i][j] == '0')
				(**game)->count_wall++;
			else if ((**game)->arr[i][j] == 'P')
				(**game)->count_char++;
			else if ((**game)->arr[i][j] == 'C')
				(**game)->coin_count++;
			else if ((**game)->arr[i][j] == 'E')
				(**game)->count_exit++;
			else if ((**game)->arr[i][j] == 'M')
				(**game)->count_worrior++;
			else
				(**game)->garbage++;
			j++;
		}
	}
}
int third_c(t_game **game)
{
	(*game)->count_exit = 0;
	(*game)->garbage = 0;
	positions_check(&game);
	if (!third_c_case((*game)->garbage, (*game)->count_char, (*game)->coin_count, (*game)->count_exit))
		return 0;
	return 1;
}

char	**ft_split(char  **s, int k)
{
	char **arr = malloc(sizeof(char *) * (k));
	if (!arr)
		return NULL;
	int i = 0;
	int j = 0;
	while (i < k)
	{
		j = 0;
		arr[i] = malloc(sizeof(char) * ft_strlen_x(s[i]));
		while (s[i][j])
		{
			arr[i][j] = s[i][j];
			j++;	
		}
		i++;
	}
	return (arr);
}
void fill(char **arr, int k, int i, int j)
{
	if ((i < 0 || i > k + 1|| j < 0 || j >  ft_strlen_x(arr[0]) - 1) 
			|| arr[i][j] == '1' || arr[i][j] == 'M')
		return;

	arr[i][j] = '1';
	fill(arr, k ,i + 1, j);
	fill(arr, k ,i - 1, j);
	fill(arr, k ,i, j + 1);
	fill(arr, k ,i, j - 1);
}
int flood_fill(t_game *game)
{
	char **new;
	new  = ft_split(game->arr, game->k);
	fill(new, game->k, game->pos_y / 65, game->pos_x / 65);
	int i = 0;
	int j = 0;
	while (i < game->k)
	{
		j = 0;
		while (new[i][j] && new[i][j] != '\n')
		{
			if (new[i][j] != '1' && new[i][j] != 'M')
				return 0;
			j++;
		}
		i++;
	}

	return 1;
}

int map_check(t_game *game)
{
	if (first_c(game->arr, game->k) == 0)
		return 0;
	if (second_c(game->arr, game->k) == 0)
		return 0;
	if (third_c(&game) == 0)
		return 0;
	return 1;
}
void render_animation(t_game **game, void *img)
{
	int j = 0;
	int i = 0;
	void *g;
	while (i < (*game)->k)
	{
		j = 0;
		while ((*game)->arr[i][j])
		{
			if ((*game)->arr[i][j] == 'C')
			{
				g = mlx_xpm_file_to_image((*game)->mlx, "./img/ground1.xpm", &(*game)->img_width, &(*game)->img_height);
				mlx_put_image_to_window((*game)->mlx, (*game)->win, g, j * 65,i * 65);
				mlx_put_image_to_window((*game)->mlx, (*game)->win, img, j * 65,i * 65);			
			}
			j++;
		}
		i++;
	}
}
int animation(t_game *game)
{
    static int frame = 0;
	void *imgf = NULL;

	
	if (frame < 20)
		imgf = mlx_xpm_file_to_image(game->mlx, "./img/coin1.xpm", &game->img_width, &game->img_height);
	else if (frame < 40)
	{
		imgf = mlx_xpm_file_to_image(game->mlx, "./img/png9.xpm", &game->img_width, &game->img_height);
		if (frame + 2 == 40)
			frame = 0;
	}
	render_animation(&game, imgf);
	frame += 1;
    return 0;
}
void valid_name(char *s)
{
	char ber[] = ".ber";
	int len = ft_strlen(ber) - 1;
	int i = ft_strlen(s) - 1;
	while (len >= 0)
	{
		if (s[i] != ber[len])
		{
			printf("Error");
			exit(0);
		}
		len--;
		i--;
	}
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
