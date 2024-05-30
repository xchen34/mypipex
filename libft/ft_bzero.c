/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:06:43 by leochen           #+#    #+#             */
/*   Updated: 2023/11/07 13:45:50 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;

	dest = s;
	while (n > 0)
	{
		*dest = '\0';
		dest ++;
		n --;
	}
}

/*int	main(void)
{
	char	s[] = "aaaa";
	char	b[] = "bbbb";
	
	ft_bzero(s, 4);
	bzero(b,4);
	printf("%s\n", s);
	printf("%s\n", b);
	return (0);
}*/
