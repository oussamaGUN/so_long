/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:31:07 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/17 18:14:09 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	render_wall(t_game ***game)
{
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/wall1.xpm", &(**game)->img_width, &(**game)->img_height);
	if (!(**game)->img)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
}

void	render_ground(t_game ***game)
{
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
	if (!(**game)->img)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
}

void	render_monster(t_game ***game)
{
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
	if (!(**game)->img)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/monster.xpm", &(**game)->img_width, &(**game)->img_height);
	if (!(**game)->img)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
}

void	render_door(t_game ***game)
{
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
	if (!(**game)->img)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/closed_door.xpm", &(**game)->img_width,
			&(**game)->img_height);
	if (!(**game)->img)
		protect1((**game)->img, (**game)->img);
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
}

void	render_player(t_game ***game)
{
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/ground1.xpm", &(**game)->img_width, &(**game)->img_height);
	if (!(**game)->img)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
	(**game)->img = mlx_xpm_file_to_image((**game)->mlx,
			"./img/player_right.xpm", &(**game)->img_width,
			&(**game)->img_height);
	if (!(**game)->img)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx, (**game)->win,
			(**game)->img, (**game)->x, (**game)->y))
		protect1((**game)->img, (**game)->img);
	(**game)->pos_x = (**game)->x;
	(**game)->pos_y = (**game)->y;
	(**game)->g = 'P';
}
