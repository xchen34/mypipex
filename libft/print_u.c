/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:24:58 by leochen           #+#    #+#             */
/*   Updated: 2024/05/07 16:22:36 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_unsigned_int_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_put_unsigned_int_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

int	print_u(unsigned int nb)
{
	int	len;

	len = 1;
	ft_put_unsigned_int_fd(nb, 1);
	if (nb < 10)
		return (1);
	else
	{
		while (nb >= 10)
		{
			len++;
			nb = nb / 10;
		}
	}
	return (len);
}
