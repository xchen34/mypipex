/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:09:29 by leochen           #+#    #+#             */
/*   Updated: 2024/05/30 16:32:49 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	split_cmd_or_execve_fail(char *complete_path, char **split_cmd)
{
	free_str(complete_path);
	free_str_array(split_cmd);
	exit(127);
}

void	dup_fd_error(int file, int *fd)
{
	ft_putstr_fd("Failed to duplicate infile to stdin", 2);
	close(file);
	close_fds(fd);
	exit(1);
}

void	print_error_message(char *cmd)
{
	char	*error_message;

	error_message = ft_strjoin(cmd, ": command not found\n");
	ft_putstr_fd(error_message, 2);
	free(error_message);
}

void	split_cmd_error(char **all_paths, char *tmp_path, char **split_cmd)
{
	free_str_array(all_paths);
	free_str(tmp_path);
	free_str_array(split_cmd);
	perror("exeve fail");
	exit(errno);
}

void	free_two_str_array(char **s1, char **s2)
{
	free_str_array(s1);
	free_str_array(s2);
}
