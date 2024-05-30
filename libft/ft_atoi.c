/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 13:11:18 by leochen           #+#    #+#             */
/*   Updated: 2023/11/16 12:20:22 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	char	*p;
	int		sign;
	int		c;

	sign = 1;
	c = 0;
	p = (char *)nptr;
	while (*p == '\t' || *p == '\n' || *p == '\v'
		|| *p == '\f' || *p == '\r' || *p == ' ')
		p++;
	if (*p == '-')
	{
		sign = -1;
		p ++;
	}
	else if (*p == '+')
		p++;
	while (*p >= '0' && *p <= '9')
	{
		c = c * 10 + (*p - '0');
		p ++;
	}
	return (c * sign);
}

/*int	main(void)
{
	char	p[] = "   2147483648f83648gsd";
	printf("atoi returns %d\n", atoi(p));
	printf("ft_atoi returns%d\n", ft_atoi(p));
	return 0;
}*/
