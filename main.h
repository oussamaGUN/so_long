/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:29:56 by ousabbar          #+#    #+#             */
/*   Updated: 2023/12/17 14:28:43 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124
# define ESC 53

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <math.h>

typedef struct s_game {
	int		coin_x;
	int		coint_y;
	int		door_y;
	int		door_x;
	int		count_exit;
	int		garbage;
	int		count_worrior;
	void	*worrior;
	void	*ground;
	int		count_wall;
	int		count_char;
	int		coin_count;
	int		move_count;
	char	**arr;
	void	*img;
	void	*mlx;
	void	*win;
	int		k;
	int		x;
	int		y;
	int		img_width;
	int		img_height;
	int		pos_x;
	int		pos_y;
	int		collect;
	int		coins;
	char	g;
}				t_game;
typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

char	*get_next_line(int fd);
int		quit(t_game *game);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strdup(const char *s);
void	valid_name(char *s);
int		ft_strlen_x(char *s);
int		first_c(char **arr, int k);
int		second_c(char **arr, int k);
int		third_c(t_game **game);
void	positions_check(t_game ***game);
int		third_c_case(int a, int b, int c, int d);
int		map_check(t_game *game);
int		strfind(char *arr);
void	map(t_game *game);
void	render_wall(t_game ***game);
void	render_ground(t_game ***game);
void	render_monster(t_game ***game);
void	render_door(t_game ***game);
void	render_player(t_game ***game);
void	if_else(char c, t_game **game);
char	**ft_split(char **s, int k);
int		flood_fill(t_game *game);
int		animation(t_game *game);
void	render_animation(t_game **game, void *img);
int		key_hook(int keycode, t_game *game);
void	lost(void);
void	won(void);
void	to_down(t_game **game);
void	to_up(t_game **game);
void	to_right(t_game **game);
void	to_left(t_game **game);
int		player_check_row(t_game ****game);
void	render_text_on_the_window(t_game ****game);
int		player_check_col(t_game ****game);
int		check_right(t_game ***game);
int		check_left(t_game ***game);
int		check_down(t_game ***game);
int		check_up(t_game ***game);
int		ft_len(int n);
char	*ft_itoa(int n);
size_t	ft_strlen_for_printing_moves(const char *str);
int		ft_coins(t_game **game);
void	get_line(t_game *game, char *s);
void	protect(void);
void	collect(t_game ***game, int i, int j, void *img);
void	protect(void);
void	protect1(void *mlx, void *img);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
int		flood_fill_3(t_game *game);
#endif