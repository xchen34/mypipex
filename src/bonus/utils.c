/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:27:16 by leochen           #+#    #+#             */
/*   Updated: 2024/05/30 13:30:46 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

char	*parse_cmd_path_utile(char *cmd, char **all_paths, char **cmd_ok)
{
	int		i;
	char	*tmp_path;
	char	*complete_path;

	i = 0;
	(void)cmd;
	while (all_paths[i] != NULL)
	{
		tmp_path = ft_strjoin(all_paths[i], "/");
		if (tmp_path == NULL)
			clean_all_paths(all_paths);
		complete_path = ft_strjoin(tmp_path, cmd_ok[0]);
		free_str(tmp_path);
		if (!complete_path)
			clean_all_paths(all_paths);
		if (access(complete_path, X_OK) == 0)
			return (complete_path);
		free_str(complete_path);
		i++;
	}
	return (NULL);
}

char	*extract_path_from_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (envp[i] + 5);
		}
		i++;
	}
	return (NULL);
}

char	*handle_extracted_path(char *env_path, char *cmd)
{
	char	*pure_path;

	if (!env_path)
	{
		return (NULL);
	}
	pure_path = strchr(env_path, '/');
	if (!pure_path)
	{
		if (access(cmd, X_OK) != 0)
			return (NULL);
		else
			return (cmd);
	}
	return (pure_path);
}

char	*prepare_pure_path(char **envp, char *cmd, char **cmd_ok)
{
	char	*env_path;
	char	*result;

	(void)cmd_ok;
	env_path = extract_path_from_env(envp);
	result = handle_extracted_path(env_path, cmd);
	return (result);
}

void	init_arg_heredoc(t_arg *arg, int argc, char **argv, char **envp)
{
	arg->argc = argc;
	arg->argv = argv;
	arg->envp = envp;
	arg->in_fd = STDIN_FILENO;
	arg->out_fd_heredoc = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND,
			0666);
	arg->out_fd_normal = -1;
	arg->cmd_index = 3;
	arg->i = 3;
	arg->exit_status = 0;
	arg->status = 0;
	arg->pid = -1;
	arg->pid_last = -1;
	arg->pipe_fd[0] = -1;
	arg->pipe_fd[1] = -1;
}
