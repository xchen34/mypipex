/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:23:43 by leochen           #+#    #+#             */
/*   Updated: 2023/11/21 14:52:58 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;

	b = (char *)big;
	i = 0;
	if (*little == '\0' || little == NULL)
		return (b);
	if (len == 0)
		return (NULL);
	while (b[i] && i < len)
	{
		j = 0;
		while (little[j] && i + j < len && b[i + j] == little[j]
			&& b[i + j] != '\0')
			j ++;
		if (little[j] == '\0')
			return (b + i);
		i ++;
	}
	return (NULL);
}

/*int	main()
{
	char big[] = "hello world";
	char lit[] = "wor";
	
	printf("%s\n", ft_strnstr(big, lit, 8));
	//printf("%p\n", strnstr(big, lit, 5));

	return 0;
}*/
