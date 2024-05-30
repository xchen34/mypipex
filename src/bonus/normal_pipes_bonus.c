/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_pipes_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:26:56 by leochen           #+#    #+#             */
/*   Updated: 2024/05/30 16:52:10 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

static void	child_process_normal(t_arg *arg)
{
	close(arg->pipe_fd[0]);
	if (arg->i == 2)
	{
		check_infile_open_bonus(arg->in_fd, arg->argv);
		dup2(arg->in_fd, STDIN_FILENO);
		close(arg->in_fd);
	}
	else
	{
		dup2(arg->prev_pipe_fd[0], STDIN_FILENO);
		close(arg->prev_pipe_fd[0]);
	}
	if (arg->i != arg->argc - 2)
	{
		dup2(arg->pipe_fd[1], STDOUT_FILENO);
	}
	else
	{
		check_outfile_writable_bonus(arg->argv[arg->argc - 1]);
		dup2(arg->out_fd_normal, STDOUT_FILENO);
		close(arg->out_fd_normal);
	}
	close_all_fds();
	execute_command(arg->argv[arg->i], arg->envp, arg->pipe_fd[1]);
	exit(EXIT_SUCCESS);
}

static void	parent_process_normal(t_arg *arg)
{
	close(arg->pipe_fd[1]);
	if (arg->i != 2)
	{
		close(arg->prev_pipe_fd[0]);
	}
	arg->prev_pipe_fd[0] = arg->pipe_fd[0];
	if (arg->i == arg->argc - 2)
	{
		arg->pid_last = arg->pid;
	}
}

int	handle_normal_pipes(int argc, char **argv, char **envp)
{
	t_arg	arg;

	init_arg_normal(&arg, argc, argv, envp);
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
			child_process_normal(&arg);
		else
		{
			parent_process_normal(&arg);
		}
		arg.i++;
	}
	close_all_fds();
	return (finalize_processes(&arg));
}

void	init_arg_normal(t_arg *arg, int argc, char **argv, char **envp)
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	arg->in_fd = open(argv[1], O_RDONLY);
	arg->out_fd_heredoc = -1;
	arg->out_fd_normal = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			0666);
	arg->cmd_index = 2;
	arg->i = 2;
	arg->exit_status = 0;
	arg->status = 0;
	arg->pid = -1;
	arg->pid_last = -1;
	arg->pipe_fd[0] = -1;
	arg->pipe_fd[1] = -1;
	arg->prev_pipe_fd[0] = -1;
	arg->prev_pipe_fd[1] = -1;
}
