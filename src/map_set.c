/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 10:42:47 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/10 23:22:48 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	set_x_y(t_map *map)
{
	map->x = 0;
	while (map->x < map->row)
	{
		map->y = 0;
		while (map->y < map->col)
		{
			if (map->grid[map->x][map->y] == 'P')
			{
				map->px = map->x;
				map->py = map->y;
			}
			if (map->grid[map->x][map->y] == 'N')
			{
				map->nx = map->x;
				map->ny = map->y;
			}
			map->y++;
		}
		map->x++;
	}
	map->y = 0;
	map->x = 0;
}

void	set_grid(t_map_checker *map_c, t_map *map, t_map *map2)
{
	map->collect = map_c->collect;
	map->exit = map_c->exit;
	map->col = map_c->col_max;
	map->row = map_c->row_max;
	map->grid = (char **)malloc(map->row * sizeof(char *));
	if (!map->grid)
		err_handle_grid(map_c, map, map2);
	map->x = 0;
	map_c->i = 0;
	while (map->x < map->row)
	{
		map->grid[map->x] = (char *)malloc(map->col * sizeof(char));
		if (!(map->grid[map->x]))
			err_handle_grid(map_c, map, map2);
		map->y = 0;
		while (map->y < map->col)
		{
			map->grid[map->x][map->y++] = map_c->str[map_c->i++];
			if (map_c->str[map_c->i] == '\n')
				map_c->i++;
		}
		map->x++;
	}
	set_x_y(map);
}

/* void	ft_print_map(t_map map)
{
	while (map.x < map.row)
	{
		map.y = 0;
		while (map.y < map.col)
		{
			ft_printf("%c", map.grid[map.x][map.y]);
			map.y++;
		}
		ft_printf("\n");
		map.x++;
	}
	ft_printf("\n");
} */
