/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_err.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yubi42 <yubi42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 14:25:45 by jborner           #+#    #+#             */
/*   Updated: 2023/10/11 00:12:49 by yubi42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_ERR_H
# define FT_PRINTF_ERR_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf_err(const char *str, ...);
void	check_type_err(char c, va_list list, int *count);
void	ft_putchar_err(char c, int *count);
void	ft_puthex_err(unsigned long num, char c, int *count);
void	ft_putnbr_err(long num, int *count);
void	ft_putstr_err(char *s, int *count);
void	ft_putpoint_err(unsigned long num, int *count);

#endif