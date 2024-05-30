/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:54:30 by leochen           #+#    #+#             */
/*   Updated: 2024/05/30 16:40:54 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	check_infile_open_bonus(int fd, char **argv)
{
	if (fd < 0)
	{
		if (errno == EACCES)
		{
			perror(argv[1]);
			close_all_fds();
			close_extrafd();
			exit(1);
		}
		else if (errno == ENOENT)
		{
			perror(argv[1]);
		}
		else if (errno == EISDIR)
			perror("");
		close_all_fds();
		close_extrafd();
		exit(127);
	}
}

void	check_file_open(int file, int *fd, char *cmd)
{
	if (file < 0)
	{
		errno = ENOENT;
		perror(cmd);
		close_fds(fd);
		exit(127);
	}
}

void	check_complete_path(char *complete_path, int file,
		char *processed_args_, char **processed_args)
{
	if (!complete_path)
	{
		close(file);
		if (processed_args_[0] != '/' || processed_args_[0] != '.')
		{
			free_str(complete_path);
			free_str_array(processed_args);
		}
		exit(127);
	}
}

void	check_outfile_writable_bonus(char *file)
{
	if (access(file, F_OK) != 0)
		return ;
	if (access(file, W_OK) != 0)
	{
		if (errno == EACCES)
			perror(file);
		else
			perror("Error checking file permission");
		close_all_fds();
		close(103);
		close(37);
		close(38);
		close(39);
		exit(1);
	}
}

int	check_arg_bonus(int argc)
{
	if (argc < 5)
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
		exit(EXIT_FAILURE);
	}
	return (0);
}
