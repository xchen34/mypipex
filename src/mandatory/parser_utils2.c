/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 19:06:15 by leochen           #+#    #+#             */
/*   Updated: 2024/05/27 17:09:18 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	*handle_slash(char *cmd, char **cmd_ok)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			return (cmd);
		}
		else
		{
			perror(cmd);
			free_str_array(cmd_ok);
			exit(126);
		}
	}
	else
	{
		perror(cmd);
		free_str_array(cmd_ok);
		exit(127);
	}
}

static char	*handle_dot(char *cmd, char **cmd_ok)
{
	if (access(cmd, F_OK) == 0)
	{
		if (access(cmd, X_OK) == 0)
		{
			return (cmd);
		}
		else
		{
			perror(cmd);
			free_str_array(cmd_ok);
			exit(126);
		}
	}
	else
	{
		perror(cmd);
		free_str_array(cmd_ok);
		exit(127);
	}
}

char	*abs_path_cmd(char *cmd, char **cmd_ok, char **envp)
{
	(void)envp;
	if (!cmd_ok || !cmd_ok[0])
	{
		errno = ENOENT;
		print_error_message(cmd);
		free_str_array(cmd_ok);
		exit(127);
	}
	if (cmd_ok[0][0] == '.')
		return (handle_dot(cmd_ok[0], cmd_ok));
	if (ft_strchr(cmd_ok[0], '/') != NULL)
		return (handle_slash(cmd_ok[0], cmd_ok));
	else
	{
		return ("not_abs");
	}
}
