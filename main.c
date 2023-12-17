/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:27:20 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/17 16:17:08 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		protect();
	game->win = mlx_new_window(game->mlx, ft_strlen_x(game->arr[0]) * 65,
			game->k * 65, "so long");
	if (!game->win)
	{
		write(1, "Error\n", 6);
		mlx_destroy_window(game->mlx, game->win);
		exit(0);
	}
}

void	images(t_game *game)
{
	game->player_right = mlx_xpm_file_to_image(game->mlx, "./img/player_right.xpm",
			&game->img_width, &game->img_height);
	if (!game->player_right)
		protect();
	game->player_left = mlx_xpm_file_to_image(game->mlx, "./img/player_left.xpm",
			&game->img_width, &game->img_height);
	if (!game->player_right)
		protect();
	game->player_down = mlx_xpm_file_to_image(game->mlx, "./img/player_down.xpm",
			&game->img_width, &game->img_height);
	if (!game->player_down)
		protect();
	game->player_up = mlx_xpm_file_to_image(game->mlx, "./img/player_up.xpm",
			&game->img_width, &game->img_height);
	if (!game->player_up)
		protect();
	game->ground = mlx_xpm_file_to_image(game->mlx, "./img/ground1.xpm",
			&game->img_width, &game->img_height);
	if (!game->ground)
		protect();
}

int	main(int ac, char *av[])
{
	t_game	game;

	if (ac != 2)
		protect();
	valid_name(av[1]);
	get_line(&game, av[1]);
	if (map_check(&game) == 0)
		protect();
	init(&game);
	map(&game);
	if (game.k == 3)
	{
		if (flood_fill_3(&game) == 0)
			protect();
	}
	if (flood_fill(&game) == 0)
		protect();
	images(&game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_hook(game.win, 02, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}
