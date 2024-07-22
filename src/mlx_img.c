/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 23:31:04 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/16 12:12:03 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	destroy_player_img(t_mlx *data, t_img *img)
{
	if (img->player_l1)
		mlx_destroy_image(data->mlx, img->player_l1);
	if (img->player_l2)
		mlx_destroy_image(data->mlx, img->player_l2);
	if (img->player_r1)
		mlx_destroy_image(data->mlx, img->player_r1);
	if (img->player_r2)
		mlx_destroy_image(data->mlx, img->player_r2);
	if (img->player_up1)
		mlx_destroy_image(data->mlx, img->player_up1);
	if (img->player_up2)
		mlx_destroy_image(data->mlx, img->player_up2);
	if (img->player_down1)
		mlx_destroy_image(data->mlx, img->player_down1);
	if (img->player_down2)
		mlx_destroy_image(data->mlx, img->player_down2);
}

void	destroy_other_img(t_mlx *data, t_img *img)
{
	if (img->border)
		mlx_destroy_image(data->mlx, img->border);
	if (img->collect)
		mlx_destroy_image(data->mlx, img->collect);
	if (img->enemy)
		mlx_destroy_image(data->mlx, img->enemy);
	if (img->ground)
		mlx_destroy_image(data->mlx, img->ground);
	if (img->exit_1)
		mlx_destroy_image(data->mlx, img->exit_1);
	if (img->exit_2)
		mlx_destroy_image(data->mlx, img->exit_2);
	if (img->exit_open)
		mlx_destroy_image(data->mlx, img->exit_open);
}

void	check_img(t_mlx *data, void **image, char *path)
{
	int	img_width;
	int	img_height;

	*image = mlx_xpm_file_to_image(data->mlx, path, &img_width, &img_height);
	if (!(*image))
		err_clear_game(data, "Error\nproblem allocating image\n");
}

void	set_img(t_mlx *data, t_img *img)
{
	set_img_path(&(data->img));
	img_path_validator(data, &(data->img));
	check_img(data, &(img->player_l1), img->player_l1_path);
	check_img(data, &(img->player_l2), img->player_l2_path);
	check_img(data, &(img->player_r1), img->player_r1_path);
	check_img(data, &(img->player_r2), img->player_r2_path);
	check_img(data, &(img->player_up1), img->player_up1_path);
	check_img(data, &(img->player_up2), img->player_up2_path);
	check_img(data, &(img->player_down1), img->player_down1_path);
	check_img(data, &(img->player_down2), img->player_down2_path);
	check_img(data, &(img->border), img->border_path);
	check_img(data, &(img->ground), img->ground_path);
	check_img(data, &(img->collect), img->collect_path);
	check_img(data, &(img->enemy), img->enemy_path);
	check_img(data, &(img->exit_1), img->exit_1_path);
	check_img(data, &(img->exit_2), img->exit_2_path);
	check_img(data, &(img->exit_open), img->exit_open_path);
}
