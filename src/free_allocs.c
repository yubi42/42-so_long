/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_allocs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:18:06 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/08 11:55:01 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	free_err_grid(t_map map, char ***grid)
{
	map.x--;
	while (map.x >= 0)
	{
		free((*grid)[map.x]);
		map.x--;
	}
	free(*grid);
	*grid = NULL;
}

void	ft_free_str(char **str)
{
	free(*str);
	*str = NULL;
}

void	ft_free_grid(t_map map, char ***grid)
{
	while (map.x < map.row)
	{
		free((*grid)[map.x]);
		map.x++;
	}
	free(*grid);
	*grid = NULL;
}
