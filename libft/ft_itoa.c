/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:57:34 by leochen           #+#    #+#             */
/*   Updated: 2023/11/22 14:14:02 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<stdlib.h>
#include "libft.h"

static int	count_len(int long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	if (n >= 0 && n <= 9)
	{
		len++;
		return (len);
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len + 1);
}

static char	*write_str(char *s, int long n)
{
	int	len;
	int	l;

	len = count_len(n);
	l = len;
	if (n == 0)
	{
		*s = '0';
		*(s + 1) = '\0';
		return (s);
	}
	if (n < 0)
	{
		*s = '-';
		n = -n;
	}
	len --;
	while (len >= 0 && n > 0)
	{
		*(s + len) = n % 10 + '0';
		n = n / 10;
		len--;
	}
	*(s + l) = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char		*s;
	int long	nb;

	nb = n;
	s = (char *)malloc(count_len(nb) + 1);
	if (s == NULL)
		return (NULL);
	return (write_str(s, nb));
}

/*int	main()
{
	long int	n = -21212121;
	printf("%d\n", count_len(n));
	printf("%s\n", ft_itoa(n));
	return 0;
} */
