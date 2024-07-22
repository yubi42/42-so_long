/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:43:36 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/10 11:21:02 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	valid_border(t_map map)
{
	while (map.x < map.row)
	{
		map.y = 0;
		while (map.y < map.col)
		{
			if ((map.y == 0 || map.x == 0 || map.y == map.col - 1
					|| map.x == map.row - 1) && map.grid[map.x][map.y] != '1')
				return (0);
			map.y++;
		}
		map.x++;
	}
	return (1);
}

void	check_path(t_map *map, int x, int y)
{
	if (map->grid[x][y] == 'C')
		map->collect--;
	if (map->grid[x][y] == 'E')
		map->exit--;
	map->grid[x][y] = '1';
	if (map->grid[x + 1][y] != '1')
		check_path(map, x + 1, y);
	if (map->grid[x - 1][y] != '1')
		check_path(map, x - 1, y);
	if (map->grid[x][y + 1] != '1')
		check_path(map, x, y + 1);
	if (map->grid[x][y - 1] != '1')
		check_path(map, x, y - 1);
}

int	map_valid(t_map map)
{
	if (!valid_border(map))
	{
		ft_free_grid(map, &(map.grid));
		return (0);
	}
	check_path(&map, map.px, map.py);
	if (map.collect != 0 || map.exit != 0)
	{
		ft_free_grid(map, &(map.grid));
		return (0);
	}
	ft_free_grid(map, &(map.grid));
	return (1);
}
