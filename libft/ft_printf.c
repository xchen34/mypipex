/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:16:58 by leochen           #+#    #+#             */
/*   Updated: 2024/05/27 17:25:37 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	param_size(char conversion, va_list params)
{
	int	printed;

	printed = 0;
	if (conversion == 'c')
		printed = print_c(va_arg(params, int));
	else if (conversion == 's')
		printed = print_s(va_arg(params, char *));
	else if (conversion == 'p')
		printed = print_p(va_arg(params, void *));
	else if (conversion == 'i' || conversion == 'd')
		printed = print_d(va_arg(params, int));
	else if (conversion == 'u')
		printed = print_u(va_arg(params, unsigned int));
	else if (conversion == 'x')
		printed = print_x(va_arg(params, unsigned int), 0);
	else if (conversion == 'X')
		printed = print_x(va_arg(params, unsigned int), 1);
	else if (conversion == '%')
	{
		ft_putchar_fd('%', 1);
		printed = 1;
	}
	return (printed);
}

static int	checkerror(char c)
{
	if (c != 'c' && c != 's' && c != 'p' && c != 'i' && c != 'd' && c != 'u'
		&& c != 'x' && c != 'X' && c != 'c' && c != '%')
		return (-1);
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	int		printed;

	printed = 0;
	if (!format)
		return (-1);
	va_start(params, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd(*format, 1);
			format++;
			printed++;
		}
		else
		{
			if (checkerror(*(format + 1)) == -1)
				return (-1);
			printed = printed + param_size(*(format + 1), params);
			format = format + 2;
		}
	}
	va_end(params);
	return (printed);
}
