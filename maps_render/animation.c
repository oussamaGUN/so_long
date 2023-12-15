#include "../main.h"
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