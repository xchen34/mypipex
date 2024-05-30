/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:05:04 by leochen           #+#    #+#             */
/*   Updated: 2023/11/08 18:30:10 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}

/*int	main(void)
{
	printf("%c\n", ft_tolower('S'));
	printf("%c\n",ft_tolower('w'));
	printf("%c\n",ft_tolower('.'));
	printf("%c\n",tolower('S'));;
	printf("%c\n",tolower('w'));;
	printf("%c\n",tolower('.'));
	return (0);
}*/
