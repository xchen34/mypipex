/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:53:47 by leochen           #+#    #+#             */
/*   Updated: 2023/11/08 18:29:38 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}

/*int	main(void)
{
	printf("%c\n", ft_toupper('S'));
	printf("%c\n",ft_toupper('w'));
	printf("%c\n",ft_toupper('.'));
	printf("%c\n",toupper('S'));;
	printf("%c\n",toupper('w'));;
	printf("%c\n",toupper('.'));
	return (0);
}*/
