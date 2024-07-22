/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:25:45 by jborner           #+#    #+#             */
/*   Updated: 2023/10/10 23:39:35 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	check_type(char c, va_list list, int *count);
void	ft_putchar(char c, int *count);
void	ft_puthex(unsigned long num, char c, int *count);
void	ft_putnbr(long num, int *count);
void	ft_putstr(char *s, int *count);
void	ft_putpoint(unsigned long num, int *count);

#endif