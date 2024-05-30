/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:48:41 by leochen           #+#    #+#             */
/*   Updated: 2023/11/22 14:11:24 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p_dest;
	unsigned char	*p_src;

	if (dest == NULL && src == NULL)
		return (NULL);
	p_dest = (unsigned char *)dest;
	p_src = (unsigned char *) src;
	if (n == 0)
		return (dest);
	while (n > 0)
	{
		*p_dest = *p_src;
		p_dest ++;
		p_src ++;
		n --;
	}
	return (dest);
}

/*void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}*/

/*int main() {
    char source[] = "Hello, World!";
    char destination1[20];
    char destination2[20];

    // 使用你编写的 ft_memcpy 复制数据
    ft_memcpy(destination1, source, strlen(source) + 1);

    // 使用标准库的 memcpy 复制数据
    memcpy(destination2, source, strlen(source) + 1);

    // 打印目标字符串
    printf("Copied string using ft_memcpy: %s\n", destination1);
    printf("Copied string using memcpy: %s\n", destination2);

    // 检查结果是否一致
    if (strcmp(destination1, destination2) == 0) {
        printf("Results match.\n");
    } else {
        printf("Results do not match.\n");
    }

    return 0;
}*/
