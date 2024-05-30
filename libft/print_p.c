/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:48:23 by leochen           #+#    #+#             */
/*   Updated: 2024/05/07 16:22:18 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_hex_digit(unsigned long long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

static void	put_ptr(unsigned long long address)
{
	static char	base[] = "0123456789abcdef";

	if (address >= 16)
	{
		put_ptr(address / 16);
		ft_putchar_fd(base[address % 16], 1);
	}
	else
		ft_putchar_fd(base[address % 16], 1);
}

int	print_p(void *address)
{
	if (address == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	put_ptr((unsigned long long)address);
	return (count_hex_digit((unsigned long long)address) + 2);
}
