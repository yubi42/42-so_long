/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jborner <jborner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 23:18:16 by yubi42            #+#    #+#             */
/*   Updated: 2023/10/23 13:12:37 by jborner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*pdest;
	const unsigned char	*psrc;

	pdest = dest;
	psrc = src;
	if (dest == src)
		return (dest);
	if (dest < src)
		while (n-- > 0)
			*pdest++ = *psrc++;
	else
	{
		pdest += n - 1;
		psrc += n - 1;
		while (n--)
			*pdest-- = *psrc--;
	}
	return (dest);
}

void	*ft_my_realloc(void *str, size_t size)
{
	void	*new_str;

	new_str = malloc(size);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
	if (str != NULL)
	{
		ft_memmove(new_str, str, size - 2);
		free(str);
	}
	return (new_str);
}

void	read_data(int fd, t_map_checker *map_c)
{
	char	buffer;
	ssize_t	bytes_read;

	bytes_read = read(fd, &buffer, 1);
	while (bytes_read > 0)
	{
		map_c->str = (char *)ft_my_realloc(map_c->str, (map_c->i + 2)
				* sizeof(char));
		if (!map_c->str)
		{
			close(fd);
			err_handle_map_c(map_c);
		}
		map_c->str[map_c->i] = buffer;
		map_c->i++;
		bytes_read = read(fd, &buffer, 1);
	}
	if (bytes_read < 0)
	{
		close(fd);
		err_handle_map_c(map_c);
	}
}

void	file_to_str(char *file, t_map_checker *map_c)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		err_handle_map_c(map_c);
	read_data(fd, map_c);
	close(fd);
	if (map_c->str)
		map_c->str[map_c->i] = '\0';
	map_c->i = 0;
}
