#include "../main.h"
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

int quit(t_game *game)
{
	(void)game;
	exit(0);
	return (0);
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