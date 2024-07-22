/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:24:33 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/23 13:09:10 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

int	valid_same_len(t_map_checker *map_c)
{
	while (map_c->str[map_c->i])
	{
		map_c->col++;
		if (map_c->str[map_c->i] == '\n')
		{
			if (map_c->row > 0 && map_c->col != map_c->col_max)
				return (0);
			map_c->col_max = map_c->col;
			map_c->col = 0;
			map_c->row++;
		}
		map_c->i++;
	}
	if (map_c->col != map_c->col_max - 1)
		return (0);
	map_c->col_max = map_c->col;
	map_c->row_max = map_c->row + 1;
	map_c->col = 0;
	map_c->row = 0;
	map_c->i = 0;
	return (1);
}

int	valid_count_p_e_c(t_map_checker *map_c)
{
	while (map_c->str[map_c->i])
	{
		if (map_c->str[map_c->i] == 'P')
			map_c->player++;
		if (map_c->str[map_c->i] == 'C')
			map_c->collect++;
		if (map_c->str[map_c->i] == 'E')
			map_c->exit++;
		if (map_c->str[map_c->i] == 'N')
			map_c->enemy++;
		if (map_c->str[map_c->i] != 'P' && map_c->str[map_c->i] != 'C'
			&& map_c->str[map_c->i] != 'E' && map_c->str[map_c->i] != 'N'
			&& map_c->str[map_c->i] != '1' && map_c->str[map_c->i] != '0'
			&& map_c->str[map_c->i] != '\n')
			return (0);
		map_c->col++;
		map_c->i++;
	}
	map_c->i = 0;
	if (map_c->player == 1 && map_c->collect > 0 && map_c->exit == 1
		&& map_c->enemy <= 1)
		return (1);
	return (0);
}

void	check_file_type(char *argv)
{
	int	i;
	int	valid;

	i = 0;
	valid = 1;
	while (argv[i])
		i++;
	if (i-- > 0 && argv[i] != 'r')
		valid = 0;
	if (i-- > 0 && argv[i] != 'e')
		valid = 0;
	if (i-- > 0 && argv[i] != 'b')
		valid = 0;
	if (i-- > 0 && argv[i] != '.')
		valid = 0;
	if (valid == 0)
	{
		ft_printf_err("Error\nnot a valid data type\n");
		exit(1);
	}
}

void	file_validator(char *argv, t_map_checker *map_c)
{
	check_file_type(argv);
	init_map_check(map_c);
	file_to_str(argv, map_c);
	if (!valid_same_len(map_c) || !valid_count_p_e_c(map_c))
		err_handle_map_c(map_c);
	if (map_c->col_max > 30 || map_c->row_max > 16)
	{
		ft_printf_err("Error\nthe map is too big for the school computers.\n");
		free(map_c->str);
		exit(1);
	}
}
