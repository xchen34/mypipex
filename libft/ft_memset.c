/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:24:27 by leochen           #+#    #+#             */
/*   Updated: 2023/11/09 13:25:06 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dest;

	dest = s;
	while (n > 0)
	{
		*dest = (unsigned char)c;
		dest ++;
		n--;
	}
	return (s);
}
/*int	main(void)
{
	unsigned char	s[] = "hello";
	ft_memset(s, '.', 3);
	printf("%s\n", s);
	return (0);
}*/
