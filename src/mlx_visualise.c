/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_visualise.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:52:08 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/10 23:30:31 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	choose_img(t_mlx data, char c, int x, int y)
{
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.ground, y
		* IMG_SIZE, x * IMG_SIZE);
	if (c == '1')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.border, y
			* IMG_SIZE, x * IMG_SIZE);
	if (c == 'C')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.collect, y
			* IMG_SIZE, x * IMG_SIZE);
	if (c == 'E')
		exit_anim(data, x, y);
	if (c == 'N')
		mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.enemy, y
			* IMG_SIZE, x * IMG_SIZE);
}

void	visualise_grid_tile(t_mlx *data, void *updated_img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, updated_img, y, x);
}

void	visualise_map(t_map map, t_mlx data)
{
	map.x = 0;
	while (map.x < map.row)
	{
		map.y = 0;
		if (map.x == 0)
			map.y = 2;
		while (map.y < map.col)
		{
			choose_img(data, map.grid[map.x][map.y], map.x, map.y);
			map.y++;
		}
		map.x++;
	}
}
