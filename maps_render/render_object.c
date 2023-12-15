#include "../main.h"
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