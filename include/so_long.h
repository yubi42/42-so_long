/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:36:22 by jborner           #+#    #+#             */
/*   Updated: 2024/02/08 17:30:08 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// libaries

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

// macros

# define COLOR_END "\033[0m"
# define RED "\033[91m"
# define GREEN "\033[92m"
# define SPEED 3000
# define DELAY 80000
# define NUM_KEYS 65536
# define IMG_SIZE 64
# define TRUE 1
# define FALSE 0
# define OPEN 0
# define CLOSED 1
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363
# define ESC 65307
# define Q 113
# define E 101

// structs

typedef struct s_map
{
	char	**grid;
	int		x;
	int		y;
	int		px;
	int		py;
	int		nx;
	int		ny;
	int		collect;
	int		exit;
	int		col;
	int		row;
}			t_map;

typedef struct s_map_checker
{
	char	*str;
	int		i;
	int		col;
	int		col_max;
	int		row;
	int		row_max;
	int		player;
	int		exit;
	int		collect;
	int		enemy;
}			t_map_checker;

typedef struct s_img
{
	void	*player_l1;
	void	*player_l2;
	void	*player_r1;
	void	*player_r2;
	void	*player_up1;
	void	*player_up2;
	void	*player_down1;
	void	*player_down2;
	void	*border;
	void	*ground;
	void	*collect;
	void	*enemy;
	void	*exit_1;
	void	*exit_2;
	void	*exit_open;
	char	*player_l1_path;
	char	*player_l2_path;
	char	*player_r1_path;
	char	*player_r2_path;
	char	*player_up1_path;
	char	*player_up2_path;
	char	*player_down1_path;
	char	*player_down2_path;
	char	*border_path;
	char	*ground_path;
	char	*collect_path;
	char	*enemy_path;
	char	*exit_1_path;
	char	*exit_2_path;
	char	*exit_open_path;
}			t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	int		*keys;
	t_map	*map;
	t_img	img;
	int		player_mov_speed;
	int		counter;
	int		xi;
	int		yi;
	int		player_anim_delay;
	int		anim_delay;
	char	xy_bool;
	int		exit_bool;
	int		sign;
}			t_mlx;

// error_handling.c

void		err_handle_grid(t_map_checker *map_c, t_map *map, t_map *map2);
void		err_handle_map_c(t_map_checker *map_c);
void		err_clear_game(t_mlx *data, char *str);

// file_valid.c

int			valid_same_len(t_map_checker *map_c);
int			valid_count_p_e_c(t_map_checker *map_c);
void		file_validator(char *argv, t_map_checker *map_c);

// free_allocs.c

void		free_err_grid(t_map map, char ***grid);
void		ft_free_str(char **str);
void		ft_free_grid(t_map map, char ***grid);

// map_init_structs.c

void		init_map_check(t_map_checker *map_c);
void		init_grid(t_map *map);

// map_set.c

void		set_x_y(t_map *map);
void		set_grid(t_map_checker *map_c, t_map *map, t_map *map2);
void		ft_print_map(t_map map);

// map_read.c

void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_my_realloc(void *str, size_t size);
void		file_to_str(char *file, t_map_checker *map_c);

// map_valid.c

int			valid_border(t_map map);
void		check_path(t_map *map, int x, int y);
int			map_valid(t_map map);

// mlx_animation.c

void		player_anim_x(t_mlx *data);
void		player_anim_y(t_mlx *data);
void		exit_anim(t_mlx data, int x, int y);
void		player_anim(t_mlx *data);

// mlx_check_collect.c

void		edit_collect(t_mlx *data, t_map *m, int x, int y);
void		check_collect_y(t_mlx *data, int sign, t_map *m);
void		check_collect_x(t_mlx *data, int sign, t_map *m);

// mlx_check_exit.c

void		check_exit_y(t_mlx *data, int sign, t_map *m, void *exit);
void		check_exit_x(t_mlx *data, int sign, t_map *m, void *exit);
void		check_exit(t_mlx *data, int sign, t_map *m);

// mlx_check_img_path.c

void		set_img_path(t_img *img);
void		check_img_path(char *path, t_mlx *data);
void		img_path_validator(t_mlx *data, t_img *img);

// mlx_close.c

void		win_condition(t_mlx *data, int sign, t_map *m);
void		lose_condition(t_mlx *data, int sign, t_map *m);
void		clear_game(t_mlx *data);
void		close_game(t_mlx *data);

// mlx_count_steps.c

void		convert_str(char *steps, char **str, int counter, int *len);
void		do_counter(t_mlx *data);

// mlx_hooks.c

void		check_input(t_mlx *data);
void		player_anim(t_mlx *data);
int			key_press(int keycode, t_mlx *data);
int			key_release(int keycode, t_mlx *data);
int			destroy_window(t_mlx *data);
int			ft_loop(t_mlx *data);

// mlx_img.c

void		destroy_player_img(t_mlx *data, t_img *img);
void		destroy_other_img(t_mlx *data, t_img *img);
void		check_img(t_mlx *data, void **image, char *path);
void		set_img(t_mlx *data, t_img *img);

// mlx_player_movement.c

void		move_op(int *i, int *map_xy, int sign);
int			border(t_mlx *data, char c, int sign, t_map *m);
void		player_movement(t_mlx *data, char c, int sign);
void		change_input(t_mlx *data, char c, int sign);

// mlx_set_data.c

void		init_img(t_img *img);
void		init_pointer(t_mlx *data);
void		set_key(t_mlx *data);
void		set_data(t_mlx *data, t_map *map);

// mlx_visualise.c

void		choose_img(t_mlx data, char c, int x, int y);
void		visualise_grid_tile(t_mlx *data, void *updated_img, int x, int y);
void		visualise_map(t_map map, t_mlx data);

// main.c

void		start_game(t_map map);
int			invalid_map(int argc, char **argv, t_map *map);

// printf.c

int			ft_printf(const char *str, ...);
int			ft_printf_err(const char *str, ...);

#endif