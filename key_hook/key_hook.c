/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:17:55 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/17 16:17:18 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	to_down(t_game **game)
{
	if (check_down(&game) == 1)
	{
		if (!mlx_put_image_to_window((*game)->mlx, (*game)->win,
				(*game)->ground, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->ground);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_y += 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		if (!mlx_put_image_to_window((*game)->mlx, (*game)->win,
				(*game)->player_down, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->player_right);
	}
}

void	to_up(t_game **game)
{
	if (check_up(&game) == 1)
	{
		if (!mlx_put_image_to_window((*game)->mlx, (*game)->win,
				(*game)->ground, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->ground);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_y -= 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		if (!mlx_put_image_to_window((*game)->mlx, (*game)->win,
				(*game)->player_up, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->player_right);
	}
}

void	to_right(t_game **game)
{
	if (check_right(&game) == 1)
	{
		if (!mlx_put_image_to_window((*game)->mlx, (*game)->win,
				(*game)->ground, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->ground);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_x += 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		if (!mlx_put_image_to_window((*game)->mlx, (*game)->win,
				(*game)->player_right, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->player_right);
	}
}

void	to_left(t_game **game)
{
	if (check_left(&game) == 1)
	{
		if (!mlx_put_image_to_window((*game)->mlx,
				(*game)->win, (*game)->ground, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->ground);
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = '0';
		(*game)->pos_x -= 65;
		(*game)->arr[(*game)->pos_y / 65][(*game)->pos_x / 65] = 'P';
		if (!mlx_put_image_to_window((*game)->mlx,
				(*game)->win, (*game)->player_left, (*game)->pos_x, (*game)->pos_y))
			protect1((*game)->mlx, (*game)->player_right);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
	else if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
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
