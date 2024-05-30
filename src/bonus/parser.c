/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 14:38:57 by leochen           #+#    #+#             */
/*   Updated: 2024/05/30 16:51:07 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

char	*check_abs_path(char *cmd, char **envp, char **cmd_ok)
{
	char	*abs;

	abs = abs_path_cmd(cmd, cmd_ok, envp);
	if (abs && ft_strncmp(abs, "not_abs", 7) != 0)
		return (abs);
	else if (!abs)
	{
		errno = ENOENT;
		perror(cmd);
		free_str_array(cmd_ok);
		exit(127);
	}
	return (NULL);
}

static char	*parse_relative_path(char *cmd, char **envp, char **cmd_ok)
{
	char	*pure_path;
	char	*complete_path;
	char	**all_paths;

	pure_path = prepare_pure_path(envp, cmd, cmd_ok);
	if (!pure_path)
	{
		errno = ENOENT;
		perror(cmd);
		free_str_array(cmd_ok);
		exit(127);
	}
	all_paths = ft_split(pure_path, ':');
	if (!all_paths)
		return (free_all_cmd_return(all_paths));
	complete_path = parse_cmd_path_utile(cmd, all_paths, cmd_ok);
	if (!complete_path && ft_strchr(cmd, '/') == NULL && cmd[0] != '.')
		print_error_message(cmd);
	free_str_array(all_paths);
	return (complete_path);
}

char	*parse_cmd_path(char *cmd, char **envp, char **cmd_ok)
{
	char	*abs_valid;

	abs_valid = check_abs_path(cmd, envp, cmd_ok);
	if (abs_valid)
		return (abs_valid);
	return (parse_relative_path(cmd, envp, cmd_ok));
}

void	execute_command(char *cmd, char **envp, int file)
{
	char	*complete_path;
	char	**cmd_ok;

	cmd_ok = parse_command_line(cmd);
	if (!cmd_ok || !cmd_ok[0])
		cmd_ok_error(cmd, cmd_ok);
	complete_path = parse_cmd_path(cmd_ok[0], envp, cmd_ok);
	check_complete_path(complete_path, file, cmd_ok[0], cmd_ok);
	close_all_fds();
	if (execve(complete_path, cmd_ok, envp) == -1)
	{
		if (errno == EACCES)
			perror(complete_path);
		split_cmd_or_execve_fail(complete_path, cmd_ok);
	}
}
