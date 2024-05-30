/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:18:14 by leochen           #+#    #+#             */
/*   Updated: 2024/05/07 16:22:11 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_d(int nb)
{
	int		len;
	char	*str;

	ft_putnbr_fd(nb, 1);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	free(str);
	return (len);
}
