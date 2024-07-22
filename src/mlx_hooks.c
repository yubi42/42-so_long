/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:57:02 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/23 13:27:50 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	check_input(t_mlx *data)
{
	if (data->keys[ESC])
	{
		ft_printf("\n");
		close_game(data);
	}
	if (data->keys[D] || data->keys[RIGHT])
		change_input(data, 'y', 1);
	if (data->keys[A] || data->keys[LEFT])
		change_input(data, 'y', -1);
	if (data->keys[W] || data->keys[UP])
		change_input(data, 'x', -1);
	if (data->keys[S] || data->keys[DOWN])
		change_input(data, 'x', 1);
}

int	key_press(int keycode, t_mlx *data)
{
	data->keys[keycode] = 1;
	return (1);
}

int	key_release(int keycode, t_mlx *data)
{
	data->keys[keycode] = 0;
	return (0);
}

int	destroy_window(t_mlx *data)
{
	ft_printf("\n");
	close_game(data);
	return (0);
}

int	ft_loop(t_mlx *data)
{
	data->player_anim_delay++;
	data->player_anim_delay %= DELAY;
	data->anim_delay++;
	data->anim_delay %= DELAY;
	if (data->player_mov_speed == 0 && (data->keys[D] || data->keys[RIGHT]
			|| data->keys[A] || data->keys[LEFT] || data->keys[W]
			|| data->keys[UP] || data->keys[S] || data->keys[DOWN]
			|| data->keys[ESC]))
	{
		visualise_grid_tile(data, data->img.border, 0, 40);
		visualise_grid_tile(data, data->img.ground, (data->map->px * IMG_SIZE)
			+ data->xi, (data->map->py * IMG_SIZE) + data->yi);
		check_input(data);
		do_counter(data);
		data->player_anim_delay += DELAY / 16;
	}
	data->player_mov_speed++;
	data->player_mov_speed %= SPEED;
	player_anim(data);
	if (data->anim_delay == 0 || data->anim_delay == DELAY / 2)
		visualise_map(*(data->map), *data);
	return (0);
}
