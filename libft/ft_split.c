/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:49:20 by leochen           #+#    #+#             */
/*   Updated: 2024/04/08 20:11:29 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include<stdio.h>
//#include<stdlib.h>
#include "libft.h"

static char	**malloc_fail(char **split, int words_written)
{
	int	i;

	i = 0;
	while (i < words_written)
		free(split[i++]);
	free(split);
	return (NULL);
}

static int	count_words(char *s, char c)
{
	int	count;
	int	flag;

	flag = 0;
	count = 0;
	while (*s)
	{
		if (flag == 0 && *s != c)
		{
			flag = 1;
			count++;
		}
		else if (flag == 1 && *s == c)
			flag = 0;
		s++;
	}
	return (count);
}

static char	*write_word(char *dest, char *src, int word_end, int word_len)
{
	int	i;

	i = 0;
	while (word_len > 0)
	{
		dest[i] = src[word_end - word_len];
		i++;
		word_len--;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**split_words(char *s, char c, char **s2, int count)
{
	int	i;
	int	j;
	int	word_len;

	i = 0;
	j = 0;
	word_len = 0;
	while (j < count)
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			word_len++;
			i++;
		}
		s2[j] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (s2[j] == NULL)
			return (malloc_fail(s2, j));
		write_word(s2[j], s, i, word_len);
		word_len = 0;
		j++;
	}
	s2[j] = 0;
	return (s2);
}

char	**ft_split(char *s, char c)
{
	unsigned int	count;
	char			**s2;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	s2 = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s2)
		return (NULL);
	s2 = split_words(s, c, s2, count);
	return (s2);
}
