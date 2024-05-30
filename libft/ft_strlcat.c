/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:18:25 by leochen           #+#    #+#             */
/*   Updated: 2023/11/20 18:46:43 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	save;

	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	save = i;
	j = 0;
	if (size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	while (src[j] && i < size - 1)
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (save + ft_strlen(src));
}

/*int main(void)
{
    char destination[20] = "Hello, ";
    const char source1[] = "world";
    const char source2[] = "1234567890";

    size_t copied1 = ft_strlcat(destination, source1, sizeof(destination));
    printf("Copied %zu characters:\n", copied1);
    printf("Destination: %s\n", destination);

    size_t copied2 = ft_strlcat(destination, source2, sizeof(destination));
    printf("Copied %zu characters:\n", copied2);
    printf("Destination: %s\n", destination);

    return 0;
}*/
