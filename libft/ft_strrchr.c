/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 19:45:00 by leochen           #+#    #+#             */
/*   Updated: 2023/11/22 14:02:31 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] != (unsigned char)c)
			i --;
		else
		{
			return ((char *)s + i);
		}
	}
	return (NULL);
}

/*int	main(void)
{
	char	s[] = "abfcdefggg";
	printf("ft f:%p\n", ft_strrchr(s,'f'));
	printf("original f:%p\n", strrchr(s,'f'));
	printf("ft w:%p\n", ft_strrchr(s,'w'));
	//printf("%c\n", *(ft_strrchr(s,'w')));
	printf("original w:%p\n", strrchr(s,'w'));
	printf("ft null:%p\n", ft_strrchr(s,'\0'));
	printf("original null :%p\n", strrchr(s,'\0'));
	
	return (0);
} 根据你提供的测试代码和输出，问题是由于循环的条件 while (i >= 0) 导致的。
在C语言中，size_t 是无符号整数类型，它永远不会小于0。
因此，条件 while (i >= 0) 恒为真，循环不会在 i 变成负数时结束。*/
