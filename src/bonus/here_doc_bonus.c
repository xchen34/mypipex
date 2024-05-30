/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:57:05 by leochen           #+#    #+#             */
/*   Updated: 2024/05/30 16:44:59 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

void	read_stdin(char *limiter)
{
	char	*line;
	int		pipe_fd[2];

	line = NULL;
	if (pipe(pipe_fd) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		line = get_next_line(STDIN_FILENO, 0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0
			&& line[ft_strlen(limiter)] == '\n')
		{
			free(line);
			break ;
		}
		write(pipe_fd[1], line, ft_strlen(line));
		free(line);
	}
	get_next_line(STDIN_FILENO, 1);
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[0]);
}

void	child_process(t_arg *arg)
{
	close(arg->pipe_fd[0]);
	if (arg->i != 3)
	{
		dup2(arg->in_fd, STDIN_FILENO);
		close(arg->in_fd);
	}
	if (arg->i != arg->argc - 2)
	{
		dup2(arg->pipe_fd[1], STDOUT_FILENO);
	}
	else
	{
		check_outfile_writable_bonus(arg->argv[arg->argc - 1]);
		dup2(arg->out_fd_heredoc, STDOUT_FILENO);
		close(arg->out_fd_heredoc);
	}
	close(arg->pipe_fd[1]);
	close_all_fds();
	execute_command(arg->argv[arg->i], arg->envp, arg->pipe_fd[1]);
	exit(EXIT_SUCCESS);
}

void	parent_process(t_arg *arg)
{
	close(arg->pipe_fd[1]);
	if (arg->i != 3)
	{
		close(arg->in_fd);
	}
	arg->in_fd = arg->pipe_fd[0];
	if (arg->i == arg->argc - 2)
	{
		arg->pid_last = arg->pid;
	}
}

int	finalize_processes(t_arg *arg)
{
	arg->pid = waitpid(-1, &arg->status, 0);
	while ((arg->pid) > 0)
	{
		if (arg->pid == arg->pid_last && WIFEXITED(arg->status))
		{
			arg->exit_status = WEXITSTATUS(arg->status);
		}
		arg->pid = waitpid(-1, &arg->status, 0);
	}
	close_all_fds();
	return (arg->exit_status);
}

int	handle_here_doc(int argc, char **argv, char **envp)
{
	t_arg	arg;

	init_arg_heredoc(&arg, argc, argv, envp);
	read_stdin(argv[2]);
	while (arg.i < argc - 1)
	{
		if (pipe(arg.pipe_fd) == -1)
		{
			perror("pipe error");
			exit(EXIT_FAILURE);
		}
		arg.pid = fork();
		check_fork(arg.pid);
		if (arg.pid == 0)
			child_process(&arg);
		else
			parent_process(&arg);
		arg.i++;
	}
	close_all_fds();
	return (finalize_processes(&arg));
}
