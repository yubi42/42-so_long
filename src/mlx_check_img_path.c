/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_check_img_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 13:08:48 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/16 12:04:03 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <mlx.h>

void	set_img_path(t_img *img)
{
	img->player_l1_path = "./sprites/player-l1.xpm";
	img->player_l2_path = "./sprites/player-l2.xpm";
	img->player_r1_path = "./sprites/player-r1.xpm";
	img->player_r2_path = "./sprites/player-r2.xpm";
	img->player_up1_path = "./sprites/player-up-1.xpm";
	img->player_up2_path = "./sprites/player-up-2.xpm";
	img->player_down1_path = "./sprites/player-down-1.xpm";
	img->player_down2_path = "./sprites/player-down-2.xpm";
	img->border_path = "./sprites/border.xpm";
	img->ground_path = "./sprites/ground.xpm";
	img->collect_path = "./sprites/fork.xpm";
	img->enemy_path = "./sprites/knife.xpm";
	img->exit_1_path = "./sprites/exit1.xpm";
	img->exit_2_path = "./sprites/exit2.xpm";
	img->exit_open_path = "./sprites/exit_open.xpm";
}

void	check_img_path(char *path, t_mlx *data)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		err_clear_game(data, "Error: invalid file path");
	close(fd);
}

void	img_path_validator(t_mlx *data, t_img *img)
{
	check_img_path(img->player_l1_path, data);
	check_img_path(img->player_l2_path, data);
	check_img_path(img->player_r1_path, data);
	check_img_path(img->player_r2_path, data);
	check_img_path(img->player_up1_path, data);
	check_img_path(img->player_up2_path, data);
	check_img_path(img->player_down1_path, data);
	check_img_path(img->player_down1_path, data);
	check_img_path(img->border_path, data);
	check_img_path(img->ground_path, data);
	check_img_path(img->collect_path, data);
	check_img_path(img->enemy_path, data);
	check_img_path(img->exit_1_path, data);
	check_img_path(img->exit_2_path, data);
	check_img_path(img->exit_open_path, data);
}
