/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:44:13 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/12 16:53:16 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	start_game(t_map map)
{
	t_mlx	data;

	init_pointer(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		err_clear_game(&data, "Error\nproblems initialising the game.\n");
	data.mlx_win = mlx_new_window(data.mlx, map.col * IMG_SIZE, map.row
			* IMG_SIZE, "My first game");
	if (!data.mlx_win)
		err_clear_game(&data, "Error\nproblems initialising game window.\n");
	set_data(&data, &map);
	visualise_map(*(data.map), data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.border, 0, 0);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img.border, 64, 0);
	ft_printf("steps: 0");
	mlx_string_put(data.mlx, data.mlx_win, 20, 20, 0xFFFFFF, "steps: 0");
	mlx_loop_hook(data.mlx, ft_loop, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, key_release, &data);
	mlx_hook(data.mlx_win, 17, 0, destroy_window, &data);
	mlx_loop(data.mlx);
}

int	invalid_map(int argc, char **argv, t_map *map)
{
	t_map_checker	map_c;
	t_map			map_validator;

	if (argc != 2)
		return (1);
	file_validator(argv[1], &map_c);
	map->grid = NULL;
	map_validator.grid = NULL;
	init_grid(map);
	init_grid(&map_validator);
	set_grid(&map_c, map, &map_validator);
	set_grid(&map_c, &map_validator, map);
	ft_free_str(&(map_c.str));
	if (!map_valid(map_validator))
	{
		ft_printf_err("Error\nnot a valid map.\n");
		ft_free_grid(*map, &(map->grid));
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (invalid_map(argc, argv, &map))
		return (1);
	start_game(map);
	return (0);
}
