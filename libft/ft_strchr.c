/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:24:34 by leochen           #+#    #+#             */
/*   Updated: 2024/02/28 14:15:37 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while ((char)c != *s)
	{
		if (*s == '\0')
			return (NULL);
		s++;
	}
	return ((char *)s);
}

/*int	main(void)
{
	char	s[] = "abcdefggg";
	printf("%p\n", ft_strchr(s,'g'));
	printf("%p\n", ft_strchr(s,'w'));
	printf("%p\n", strchr(s,'g'));
	printf("%p\n", strchr(s,'w'));
	printf("%p\n", ft_strchr(s,'\0'));
	printf("%p\n", strchr(s,'\0'));
	
	return (0);
}*/
