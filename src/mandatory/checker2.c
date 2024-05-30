/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:58:55 by leochen           #+#    #+#             */
/*   Updated: 2024/05/23 12:15:55 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	check_fork(pid_t pid)
{
	if (pid < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
}

void	check_pipe(int p)
{
	if (p < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
}

void	clean_all_paths(char **all_paths)
{
	free_str_array(all_paths);
	exit(errno);
}

void	close_extrafd(void)
{
	close(103);
	close(37);
	close(38);
	close(39);
}
