/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_count_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 10:38:04 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/16 11:45:43 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	convert_str(char *steps, char **str, int counter, int *len)
{
	int	j;

	j = 0;
	*str = malloc(sizeof(char) * (*len));
	if (!(*str))
		return ;
	while (*steps)
		(*str)[j++] = *steps++;
	(*len)--;
	(*str)[(*len)--] = '\0';
	while (counter)
	{
		(*str)[(*len)--] = counter % 10 + '0';
		counter /= 10;
	}
}

void	do_counter(t_mlx *data)
{
	char	*str;
	int		len;

	str = NULL;
	if (data->counter == INT_MAX)
	{
		ft_printf(RED "\nError\nyou have no steps left. You died\n" COLOR_END);
		close_game(data);
	}
	data->counter++;
	len = ft_printf("\rsteps: %i", data->counter);
	convert_str("steps: ", &str, data->counter, &len);
	if (!str)
	{
		ft_printf_err("\nError\nno memory to allocate counter.\n");
		close_game(data);
	}
	mlx_string_put(data->mlx, data->mlx_win, 20, 20, 0xFFFFFF, str);
	free(str);
}
