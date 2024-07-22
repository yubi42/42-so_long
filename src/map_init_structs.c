/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_structs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:26:30 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/09 15:02:45 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	init_grid(t_map *map)
{
	map->grid = NULL;
	map->x = 0;
	map->y = 0;
	map->px = 0;
	map->py = 0;
	map->nx = 0;
	map->ny = 0;
	map->collect = 0;
	map->exit = 0;
	map->col = 0;
	map->row = 0;
}

void	init_map_check(t_map_checker *map_c)
{
	map_c->str = NULL;
	map_c->i = 0;
	map_c->col = 0;
	map_c->col_max = 0;
	map_c->row = 0;
	map_c->row_max = 0;
	map_c->player = 0;
	map_c->exit = 0;
	map_c->collect = 0;
	map_c->enemy = 0;
}
