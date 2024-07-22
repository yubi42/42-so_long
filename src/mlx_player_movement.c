/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_player_movement.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:03:56 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/09 15:03:23 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	move_op(int *i, int *map_xy, int sign)
{
	*i += (8 * sign);
	if (*i == (64 * sign))
	{
		*i = 0;
		*map_xy = *map_xy + (1 * sign);
	}
}

int	border(t_mlx *data, char c, int sign, t_map *m)
{
	if (c == 'y')
		if ((m->grid[m->px][m->py + (1 * sign)] != '1' || (m->grid[m->px][m->py
				+ (1 * sign)] == '1' && (data->yi * sign) < 0))
			&& (data->xi == 0 || ((data->xi > 0 && m->grid[m->px + 1][m->py + (1
							* sign)] != '1') || (m->grid[m->px + 1][m->py + (1
							* sign)] == '1' && (data->yi * sign) < 0))
				|| ((data->xi < 0 && m->grid[m->px - 1][m->py + (1
							* sign)] != '1') || (m->grid[m->px - 1][m->py + (1
							* sign)] == '1' && (data->yi * sign) < 0))))
			return (0);
	if (c == 'x')
		if ((m->grid[m->px + (1 * sign)][m->py] != '1' || (m->grid[m->px + (1
						* sign)][m->py] == '1' && (data->xi * sign) < 0))
			&& (data->yi == 0 || ((data->yi > 0 && m->grid[m->px + (1
							* sign)][m->py + 1] != '1') || (m->grid[m->px + (1
							* sign)][m->py + 1] == '1' && (data->xi
							* sign) < 0)) || ((data->yi < 0 && m->grid[m->px
						+ (1 * sign)][m->py - 1] != '1') || (m->grid[m->px + (1
							* sign)][m->py - 1] == '1' && (data->xi
							* sign) < 0))))
			return (0);
	return (1);
}

void	player_movement(t_mlx *data, char c, int sign)
{
	if (!border(data, c, sign, data->map))
	{
		check_exit(data, sign, data->map);
		lose_condition(data, sign, data->map);
		if (c == 'y')
		{
			check_collect_y(data, sign, data->map);
			move_op(&(data->yi), &(data->map->py), sign);
		}
		if (c == 'x')
		{
			check_collect_x(data, sign, data->map);
			move_op(&(data->xi), &(data->map->px), sign);
		}
	}
}

void	change_input(t_mlx *data, char c, int sign)
{
	data->xy_bool = c;
	data->sign = sign;
	player_movement(data, data->xy_bool, data->sign);
}
