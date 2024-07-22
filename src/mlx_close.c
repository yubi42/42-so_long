/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_close.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:58:15 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/12 16:57:35 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	win_condition(t_mlx *data, int sign, t_map *m)
{
	if (data->map->collect == 0 && (m->grid[m->px + (1 * sign)][m->py] == 'E'
		|| (data->yi > 0 && m->grid[m->px + (1 * sign)][m->py + 1] == 'E')
			|| (data->yi < 0 && m->grid[m->px + (1 * sign)][m->py - 1] == 'E'))
		&& (data->xi * sign) > 0)
	{
		ft_printf(GREEN "\nDead by snu snu - you win :)\n" COLOR_END);
		close_game(data);
	}
	if (data->map->collect == 0 && (m->grid[m->px][m->py + (1 * sign)] == 'E'
		|| (data->xi > 0 && m->grid[m->px + 1][m->py + (1 * sign)] == 'E')
			|| (data->xi < 0 && m->grid[m->px - 1][m->py + (1 * sign)] == 'E'))
		&& (data->yi * sign) > 0)
	{
		ft_printf(GREEN "\nDead by snu snu - you win :)\n" COLOR_END);
		close_game(data);
	}
}

void	lose_condition(t_mlx *data, int sign, t_map *m)
{
	if (((m->grid[m->px + (1 * sign)][m->py] == 'N') || (data->yi > 0
			&& m->grid[m->px + (1 * sign)][m->py + 1] == 'N')
			|| (data->yi < 0 && m->grid[m->px + (1 * sign)][m->py - 1] == 'N'))
		&& (data->xi * sign) > 0)
	{
		ft_printf(RED "\nYou dead.\n" COLOR_END);
		close_game(data);
	}
	if ((m->grid[m->px][m->py + (1 * sign)] == 'N' || (data->xi > 0
			&& m->grid[m->px + 1][m->py + (1 * sign)] == 'N')
			|| (data->xi < 0 && m->grid[m->px - 1][m->py + (1 * sign)] == 'N'))
		&& (data->yi * sign) > 0)
	{
		ft_printf(RED "\nYou dead.\n" COLOR_END);
		close_game(data);
	}
}

void	clear_game(t_mlx *data)
{
	destroy_player_img(data, &(data->img));
	destroy_other_img(data, &(data->img));
	if (data->mlx_win)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		mlx_destroy_display(data->mlx);
	}
	if (data->mlx)
		free(data->mlx);
	ft_free_grid(*(data->map), &(data->map->grid));
	if (data->keys)
		free(data->keys);
}

void	close_game(t_mlx *data)
{
	mlx_loop_end(data->mlx);
	clear_game(data);
	exit(0);
}
