/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 18:27:20 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/16 18:10:21 by ousabbar         ###   ########.fr       */
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
		protect();
}

void	images(t_game *game)
{
	game->worrior = mlx_xpm_file_to_image(game->mlx, "./img/worrior.xpm",
			&game->img_width, &game->img_height);
	if (!game->worrior)
		protect();
	game->ground = mlx_xpm_file_to_image(game->mlx, "./img/ground.xpm",
			&game->img_width, &game->img_height);
	if (!game->worrior)
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
	if (flood_fill(&game) == 0)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
	images(&game);
	mlx_loop_hook(game.mlx, animation, &game);
	mlx_hook(game.win, 02, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, quit, &game);
	mlx_loop(game.mlx);
}
