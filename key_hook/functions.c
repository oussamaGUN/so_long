/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:20:15 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/16 16:50:10 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	player_check_col(t_game ****game)
{
	int	i;
	int j;

	i = 0;
	while (i < (***game)->k)
	{
		j = 0;
		while ((***game)->arr[i][j] != '\0')
		{
			if ((***game)->arr[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (j);
}

int	player_check_row(t_game ****game)
{
	int	i;
	int	j;

	i = 0;
	while (i < (***game)->k)
	{
		j = 0;
		while ((***game)->arr[i][j] != '\0')
		{
			if ((***game)->arr[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}

void	lost(void)
{
	write(1, "WA 3LA KA3KA3\n", 14);
	exit(0);
}

void	fun(void *a, void *b, char *s)
{
	mlx_string_put(a, b, 50, 0, 0x00FF0000, s);
}

void	render_text_on_the_window(t_game ****game)
{
	char	*s;

	s = ft_itoa((***game)->move_count++);
	(***game)->img = mlx_xpm_file_to_image((***game)->mlx,
			"./img/wall1.xpm", &(***game)->img_width,
			&(***game)->img_height);
	if (!(***game)->img)
		protect();
	if (!mlx_put_image_to_window((***game)->mlx, 
			(***game)->win, (***game)->img, 0, 0))
		protect1((***game)->img, (***game)->img);
	if (!mlx_put_image_to_window((***game)->mlx, 
			(***game)->win, (***game)->img, 65, 0))
		protect1((***game)->img, (***game)->img);
	if (!mlx_put_image_to_window((***game)->mlx, 
			(***game)->win, (***game)->img, 130, 0))
		protect1((***game)->img, (***game)->img);
	if (!mlx_put_image_to_window((***game)->mlx, 
			(***game)->win, (***game)->img, 194, 0))
		protect1((***game)->img, (***game)->img);
	if (mlx_string_put((***game)->mlx, 
			(***game)->win, 0, 0, 0x00FF0000, "move"))
		protect1((***game)->img, (***game)->img);
	fun((***game)->mlx, (***game)->win, s);
}
