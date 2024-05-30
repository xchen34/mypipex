/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:42:34 by leochen        #+#    #+#             */
/*   Updated: 2024/04/12 13:48:55 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_arg
{
	int		in_fd;
	int		out_fd_heredoc;
	int		out_fd_normal;
	int		cmd_index;
	int		argc;
	int		pid;
	int		pid_last;
	int		exit_status;
	int		status;
	int		i;
	int		pipe_fd[2];
	int		prev_pipe_fd[2];
	char	**argv;
	char	**envp;
}			t_arg;

int			child_process1(char **argv, char **envp, int *fd);
int			child_process2(char **argv, char **envp, int *fd);
char		*parse_cmd_path_utile(char *cmd, char **all_paths, char **cmd_ok);
char		*prepare_pure_path(char **envp, char *cmd, char **cmd_ok);
char		*parse_cmd_path(char *cmd, char **envp, char **cmd_ok);
char		**parse_command_line(char *cmd);
char		*abs_path_cmd(char *cmd, char **cmd_ok, char **envp);
void		split_cmd_or_execve_fail(char *complete_path, char **split_cmd);
void		dup_fd_error(int file, int *fd);
void		print_error_message(char *cmd);
void		split_cmd_error(char **all_paths, char *tmp_path, char **split_cmd);
void		close_all_fds(void);
void		close_fds(int *fd);
void		free_str(char *s);
char		*free_all_cmd_return(char **all_paths);
void		free_str_array(char **s);
void		check_file_open(int file, int *fd, char *cmd);
void		check_complete_path(char *complete_path, int file,
				char *processed_args_, char **processed_args);
void		check_fork(pid_t pid);
void		check_pipe(int p);
void		clean_all_paths(char **all_paths);
char		*check_abs_path(char *cmd, char **envp, char **cmd_ok);
void		close_extrafd(void);
void		free_two_str_array(char **s1, char **s2);
void		cmd_ok_error(char *cmd, char **cmd_ok);
//bonus
int			check_arg_bonus(int argc);
void		check_infile_open_bonus(int fd, char **argv);
void		init_arg_heredoc(t_arg *arg, int argc, char **argv, char **envp);
void		init_arg_normal(t_arg *arg, int argc, char **argv, char **envp);
void		read_stdin(char *limiter);
void		child_process(t_arg *arg);
void		parent_process(t_arg *arg);
int			finalize_processes(t_arg *arg);
int			handle_here_doc(int argc, char **argv, char **envp);
void		check_outfile_writable_bonus(char *file);
void		execute_command(char *cmd, char **envp, int file);
int			handle_normal_pipes(int argc, char **argv, char **envp);

#endif