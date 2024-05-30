/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:55:52 by leochen           #+#    #+#             */
/*   Updated: 2024/05/23 12:43:14 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	close_all_fds(void)
{
	int	fd;

	fd = 3;
	while (fd < 1024)
	{
		close(fd);
		fd++;
	}
}

void	close_fds(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	free_str(char *s)
{
	if (s)
		free(s);
}

char	*free_all_cmd_return(char **all_paths)
{
	free_str_array(all_paths);
	return (NULL);
}

void	free_str_array(char **s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != NULL)
		{
			free(s[i]);
			s[i] = NULL;
			i++;
		}
		free(s);
	}
}
