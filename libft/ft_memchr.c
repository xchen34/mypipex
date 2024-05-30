/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:25:43 by leochen           #+#    #+#             */
/*   Updated: 2023/11/15 18:28:06 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n > 0)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		else
		{
			p++;
			n --;
		}
	}
	return (NULL);
}

/*int main() {
    char str[] = "Hello, World!";
    int search_char = 'W';
    size_t len = strlen(str);

    // 使用自己实现的 memchr 函数
    void *custom_result = memchr(str, search_char, len);
    
    if (custom_result != NULL) {
        printf("Custom memchr: Character '%c' found at position %ld\n",
 search_char, (char *)custom_result - str);
    } else {
        printf("Custom memchr: Character '%c' not found in the string\n",
 search_char);
    }

    // 使用标准库的 memchr 函数
    void *std_result = strchr(str, search_char);

    if (std_result != NULL) {
        printf("Standard memchr: Character '%c' found at position %ld\n",
 search_char, (char *)std_result - str);
    } else {
        printf("Standard memchr: Character '%c' not found in the string\n",
 search_char);
    }

    return 0;
}*/
