/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:53:14 by leochen           #+#    #+#             */
/*   Updated: 2023/11/09 17:23:10 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char		*ps1;
	const unsigned char		*ps2;
	int						i;

	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	i = n;
	if (n == 0)
		return (0);
	while (i > 0)
	{
		if (*ps1 == *ps2)
		{
			ps1 ++;
			ps2 ++;
			i --;
		}
		else
			return ((int)(*ps1 - *ps2));
	}
	return (0);
}

/*int main()
{
char *s1 = "Hello,Programmer!";
char *s2 = "Hello,Promers";
int r;
r = memcmp(s1,s2,strlen(s1));
if(!r)
    printf("s1 and s2 are identical\n");//s1等于s2
else if(r<0)
    printf("s1 is less than s2,%d\n", r);//s1小于s2
else
    printf("s1 is greater than s2, %d\n", r);//s1大于s2

r = ft_memcmp(s1,s2,strlen(s1));
if(!r)
    printf("s1 and s2 are identical\n");//s1等于s2
  else if(r<0)
      printf("s1 is less than s2 ,%d\n", r);//s1小于s2
  else
      printf("s1 is greater than s2, %d\n", r);//s1大于s2
  return 0;


}*/
