/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:26:29 by leochen           #+#    #+#             */
/*   Updated: 2023/11/20 16:47:50 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	char	*res;

	if (s2 == NULL)
		return ((char *)s1);
	if (s1 == NULL)
		return (NULL);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s3 == NULL)
		return (NULL);
	res = s3;
	while (*s1)
	{
		*s3 = *s1;
		s3 ++;
		s1 ++;
	}
	while (*s2)
	{
		*s3 = *s2;
		s3 ++;
		s2 ++;
	}
	*s3 = '\0';
	return (res);
}

/*int main()
{
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    
    char *result = ft_strjoin(s1, s2);

    if (result != NULL)
    {
        printf("Concatenated string: %s\n", result);
        free(result); // 释放动态分配的内存
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}*/
