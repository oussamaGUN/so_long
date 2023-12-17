/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:12:06 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/17 14:58:47 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	collect(t_game ***game, int i, int j, void *img)
{
	void	*g;

	g = mlx_xpm_file_to_image((**game)->mlx,
			"./img/ground1.xpm", &(**game)->img_width,
			&(**game)->img_height);
	if (!g)
		protect();
	if (!mlx_put_image_to_window((**game)->mlx,
			(**game)->win, g, j * 65, i * 65))
		protect();
	if (!mlx_put_image_to_window((**game)->mlx,
			(**game)->win, img, j * 65, i * 65))
		protect();
}

void	render_animation(t_game **game, void *img)
{
	int		i;
	int		j;

	j = 0;
	i = -1;
	while (++i < (*game)->k)
	{
		j = 0;
		while ((*game)->arr[i][j])
		{
			if ((*game)->arr[i][j] == 'C')
			{
				collect(&game, i, j, img);
			}
			j++;
		}
	}
}

int	animation(t_game *game)
{
	void		*imgf;
	static int	frame = 0;

	imgf = NULL;
	if (frame < 20)
	{
		imgf = mlx_xpm_file_to_image(game->mlx,
				"./img/coin1.xpm", &game->img_width, &game->img_height);
		if (!imgf)
			protect();
	}
	else if (frame < 40)
	{
		imgf = mlx_xpm_file_to_image(game->mlx,
				"./img/png9.xpm", &game->img_width, &game->img_height);
		if (!imgf)
			protect();
		if (frame + 1 == 40)
			frame = 0;
	}
	render_animation(&game, imgf);
	frame += 1;
	return (0);
}
