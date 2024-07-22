/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_check_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 13:24:26 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/12 10:06:37 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	check_exit_y(t_mlx *data, int sign, t_map *m, void *exit)
{
	if (m->grid[m->px][m->py] == 'E')
		visualise_grid_tile(data, exit, m->px * IMG_SIZE, ((m->py) * IMG_SIZE)
			- 28);
	if (m->grid[m->px][m->py - (1 * sign)] == 'E')
		visualise_grid_tile(data, exit, m->px * IMG_SIZE, ((m->py - (1 * sign))
				* IMG_SIZE) - 28);
	if (m->grid[m->px][m->py + (1 * sign)] == 'E')
		visualise_grid_tile(data, exit, m->px * IMG_SIZE, ((m->py + (1 * sign))
				* IMG_SIZE) - 28);
	if (data->xi > 0 && m->grid[m->px + 1][m->py - (1 * sign)] == 'E')
		visualise_grid_tile(data, exit, (m->px + 1) * IMG_SIZE, ((m->py - (1
						* sign)) * IMG_SIZE) - 28);
	if (data->xi > 0 && m->grid[m->px + 1][m->py + (1 * sign)] == 'E')
		visualise_grid_tile(data, exit, (m->px + 1) * IMG_SIZE, ((m->py + (1
						* sign)) * IMG_SIZE) - 28);
	if (data->xi < 0 && m->grid[m->px - 1][m->py - (1 * sign)] == 'E')
		visualise_grid_tile(data, exit, (m->px - 1) * IMG_SIZE, ((m->py - (1
						* sign)) * IMG_SIZE) - 28);
	if (data->xi < 0 && m->grid[m->px - 1][m->py + (1 * sign)] == 'E')
		visualise_grid_tile(data, exit, (m->px - 1) * IMG_SIZE, ((m->py + (1
						* sign)) * IMG_SIZE) - 28);
}

void	check_exit_x(t_mlx *data, int sign, t_map *m, void *exit)
{
	if (m->grid[m->px][m->py] == 'E')
		visualise_grid_tile(data, exit, m->px * IMG_SIZE, ((m->py) * IMG_SIZE
				- 28));
	if (m->grid[m->px - (1 * sign)][m->py] == 'E')
		visualise_grid_tile(data, exit, (m->px - (1 * sign)) * IMG_SIZE, (m->py
				* IMG_SIZE - 28));
	if (m->grid[m->px + (1 * sign)][m->py] == 'E')
		visualise_grid_tile(data, exit, (m->px + (1 * sign)) * IMG_SIZE, (m->py
				* IMG_SIZE - 28));
	if (data->yi > 0 && m->grid[m->px - (1 * sign)][m->py + 1] == 'E')
		visualise_grid_tile(data, exit, (m->px - (1 * sign)) * IMG_SIZE, ((m->py
					+ 1) * IMG_SIZE - 28));
	if (data->yi > 0 && m->grid[m->px + (1 * sign)][m->py + 1] == 'E')
		visualise_grid_tile(data, exit, (m->px + (1 * sign)) * IMG_SIZE, ((m->py
					+ 1) * IMG_SIZE - 28));
	if (data->yi < 0 && m->grid[m->px - (1 * sign)][m->py - 1] == 'E')
		visualise_grid_tile(data, exit, (m->px - (1 * sign)) * IMG_SIZE, ((m->py
					- 1) * IMG_SIZE - 28));
	if (data->yi < 0 && m->grid[m->px + (1 * sign)][m->py - 1] == 'E')
		visualise_grid_tile(data, exit, (m->px + (1 * sign)) * IMG_SIZE, ((m->py
					- 1) * IMG_SIZE - 28));
}

void	check_exit(t_mlx *data, int sign, t_map *m)
{
	void	*exit;

	win_condition(data, sign, m);
	if (data->anim_delay < DELAY / 2)
		exit = data->img.exit_1;
	else
		exit = data->img.exit_2;
	if (data->exit_bool == 0)
	{
		check_exit_x(data, sign, m, exit);
		check_exit_y(data, sign, m, exit);
	}
}
