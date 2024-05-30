/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:42:34 by leochen        #+#    #+#             */
/*   Updated: 2024/04/12 13:49:25 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	wait_for_children(pid_t last_pid)
{
	int		status;
	pid_t	pid;
	int		exit_status;

	exit_status = 0;
	pid = waitpid(-1, &status, 0);
	while (pid > 0)
	{
		if (pid == last_pid && WIFEXITED(status))
		{
			exit_status = WEXITSTATUS(status);
		}
		pid = waitpid(-1, &status, 0);
	}
	return (exit_status);
}

void	cmd_ok_error(char *cmd, char **cmd_ok)
{
	errno = ENOENT;
	print_error_message(cmd);
	free_str_array(cmd_ok);
	close_all_fds();
	exit(127);
}

int	child_process1(char **argv, char **envp, int *fd)
{
	int		infile;
	char	*complete_path;
	char	**cmd_ok;

	infile = open(argv[1], O_RDONLY);
	check_infile_open(infile, fd, argv[1]);
	if (dup2(infile, STDIN_FILENO) == -1)
		dup_fd_error(infile, fd);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		dup_fd_error(infile, fd);
	close_all_fds();
	cmd_ok = parse_command_line(argv[2]);
	if (!cmd_ok || !cmd_ok[0])
		cmd_ok_error(argv[2], cmd_ok);
	complete_path = parse_cmd_path(cmd_ok[0], envp, cmd_ok);
	check_complete_path(complete_path, infile, cmd_ok[0], cmd_ok);
	if (execve(complete_path, cmd_ok, envp) == -1)
	{
		if (errno == EACCES)
			perror(complete_path);
		split_cmd_or_execve_fail(complete_path, cmd_ok);
	}
	return (0);
}

int	child_process2(char **argv, char **envp, int *fd)
{
	int		outfile;
	char	*complete_path;
	char	**processed_args;

	close(fd[1]);
	check_outfile_writable(argv[4], fd);
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	check_file_open(outfile, fd, argv[3]);
	if (dup2(fd[0], STDIN_FILENO) == -1 || dup2(outfile, STDOUT_FILENO) == -1)
		dup_fd_error(outfile, fd);
	close_all_fds();
	processed_args = parse_command_line(argv[3]);
	if (!processed_args || !processed_args[0])
		cmd_ok_error(argv[3], processed_args);
	complete_path = parse_cmd_path(processed_args[0], envp, processed_args);
	check_complete_path(complete_path, outfile, processed_args[0],
		processed_args);
	if (execve(complete_path, processed_args, envp) == -1)
	{
		if (errno == EACCES)
			perror(complete_path);
		split_cmd_or_execve_fail(complete_path, processed_args);
	}
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];

	check_arg(argc, argv, envp);
	check_pipe(pipe(fd));
	pid1 = fork();
	check_fork(pid1);
	if (pid1 == 0)
		child_process1(argv, envp, fd);
	pid2 = fork();
	check_fork(pid2);
	if (pid2 == 0)
		child_process2(argv, envp, fd);
	close_fds(fd);
	close_all_fds();
	return (wait_for_children(pid2));
}
