/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_set_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:30:30 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/16 12:15:15 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	init_img_path(t_img *img)
{
	img->player_l1_path = NULL;
	img->player_l2_path = NULL;
	img->player_r1_path = NULL;
	img->player_r2_path = NULL;
	img->player_up1_path = NULL;
	img->player_up2_path = NULL;
	img->player_down1_path = NULL;
	img->player_down2_path = NULL;
	img->border_path = NULL;
	img->ground_path = NULL;
	img->collect_path = NULL;
	img->enemy_path = NULL;
	img->exit_1_path = NULL;
	img->exit_2_path = NULL;
	img->exit_open_path = NULL;
}

void	init_img(t_img *img)
{
	img->player_l1 = NULL;
	img->player_l2 = NULL;
	img->player_r1 = NULL;
	img->player_r2 = NULL;
	img->player_up1 = NULL;
	img->player_up2 = NULL;
	img->player_down1 = NULL;
	img->player_down2 = NULL;
	img->border = NULL;
	img->ground = NULL;
	img->collect = NULL;
	img->enemy = NULL;
	img->exit_1 = NULL;
	img->exit_2 = NULL;
	img->exit_open = NULL;
}

void	init_pointer(t_mlx *data)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	init_img(&(data->img));
	init_img_path(&(data->img));
	data->keys = NULL;
}

void	set_keys(t_mlx *data)
{
	int	i;

	i = 0;
	data->keys = (int *)malloc(NUM_KEYS * sizeof(int));
	if (!data->keys)
		err_clear_game(data, "Error\nproblem initialising keys.\n");
	while (i < NUM_KEYS)
		data->keys[i++] = 0;
}

void	set_data(t_mlx *data, t_map *map)
{
	set_keys(data);
	data->map = map;
	set_img(data, &(data->img));
	data->player_mov_speed = 0;
	data->counter = 0;
	data->yi = 0;
	data->xi = 0;
	data->player_anim_delay = 0;
	data->anim_delay = 0;
	data->xy_bool = 'y';
	data->exit_bool = 0;
	data->sign = 1;
}
