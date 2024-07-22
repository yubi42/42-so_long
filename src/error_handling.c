/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:15:37 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/12 12:09:17 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	err_handle_grid(t_map_checker *map_c, t_map *map, t_map *map2)
{
	if (map)
		free_err_grid(*map, &(map->grid));
	if (map2)
		ft_free_grid(*map2, &(map2->grid));
	if (map_c->str)
		ft_free_str(&(map_c->str));
	ft_printf_err("Error\nnot enough mem to allocate.\n");
	exit(1);
}

void	err_handle_map_c(t_map_checker *map_c)
{
	if (map_c->str)
		ft_free_str(&(map_c->str));
	ft_printf_err("Error\nnot a valid map.\n");
	exit(1);
}

void	err_clear_game(t_mlx *data, char *str)
{
	clear_game(data);
	ft_printf_err(str);
	exit(1);
}
