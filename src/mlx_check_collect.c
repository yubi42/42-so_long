/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_check_collect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:40:07 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/10 23:27:53 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	edit_collect(t_mlx *data, t_map *m, int x, int y)
{
	m->grid[x][y] = '0';
	m->collect--;
	visualise_grid_tile(data, data->img.ground, x * IMG_SIZE, y * IMG_SIZE);
	if (m->collect == 0)
		data->exit_bool = 1;
}

void	check_collect_y(t_mlx *data, int sign, t_map *m)
{
	if (m->grid[m->px][m->py + (1 * sign)] == 'C' && data->yi == 0)
		edit_collect(data, m, m->px, m->py + (1 * sign));
	if (data->xi > 0 && m->grid[m->px + 1][m->py + (1 * sign)] == 'C'
		&& data->yi == 0)
		edit_collect(data, m, m->px + 1, m->py + (1 * sign));
	if (data->xi < 0 && m->grid[m->px - 1][m->py + (1 * sign)] == 'C'
		&& data->yi == 0)
		edit_collect(data, m, m->px - 1, m->py + (1 * sign));
}

void	check_collect_x(t_mlx *data, int sign, t_map *m)
{
	if (m->grid[m->px + (1 * sign)][m->py] == 'C' && data->xi == 0)
		edit_collect(data, m, m->px + (1 * sign), m->py);
	if (data->yi > 0 && m->grid[m->px + (1 * sign)][m->py + 1] == 'C'
		&& data->xi == 0)
		edit_collect(data, m, m->px + (1 * sign), m->py + 1);
	if (data->yi < 0 && m->grid[m->px + (1 * sign)][m->py - 1] == 'C'
		&& data->xi == 0)
		edit_collect(data, m, m->px + (1 * sign), m->py - 1);
}
