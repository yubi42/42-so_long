/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_animation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:41:59 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/12 10:08:21 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	exit_anim(t_mlx data, int x, int y)
{
	if (data.exit_bool == 0 && data.anim_delay == 0)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.exit_1, (y
				* IMG_SIZE) - 28, x * IMG_SIZE);
	else if (data.exit_bool == 0)
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.exit_2, (y
				* IMG_SIZE) - 28, x * IMG_SIZE);
	else
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.exit_open, (y
				* IMG_SIZE) - 28, x * IMG_SIZE);
}

void	player_anim_x(t_mlx *data)
{
	if (data->sign > 0 && data->player_anim_delay < (DELAY / 2))
		visualise_grid_tile(data, data->img.player_up1, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
	else if (data->sign > 0)
		visualise_grid_tile(data, data->img.player_up2, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
	else if (data->sign < 0 && data->player_anim_delay < (DELAY / 2))
		visualise_grid_tile(data, data->img.player_down1, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
	else if (data->sign < 0)
		visualise_grid_tile(data, data->img.player_down2, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
}

void	player_anim_y(t_mlx *data)
{
	if (data->sign > 0 && data->player_anim_delay < (DELAY / 2))
		visualise_grid_tile(data, data->img.player_r1, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
	else if (data->sign > 0)
		visualise_grid_tile(data, data->img.player_r2, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
	else if (data->sign < 0 && data->player_anim_delay < (DELAY / 2))
		visualise_grid_tile(data, data->img.player_l1, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
	else if (data->sign < 0)
		visualise_grid_tile(data, data->img.player_l2, (data->map->px
				* IMG_SIZE) + data->xi, (data->map->py * IMG_SIZE) + data->yi);
}

void	player_anim(t_mlx *data)
{
	if (data->xy_bool == 'y')
		player_anim_y(data);
	else if (data->xy_bool == 'x')
		player_anim_x(data);
}
