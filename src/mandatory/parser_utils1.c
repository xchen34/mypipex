/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 18:50:44 by leochen           #+#    #+#             */
/*   Updated: 2024/05/27 17:30:58 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static char	*ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*extract_quoted(char **cmd)
{
	char	quote;
	int		len;
	char	*arg;
	char	*start;

	quote = **cmd;
	(*cmd)++;
	start = *cmd;
	while (**cmd && **cmd != quote)
		(*cmd)++;
	len = *cmd - start;
	arg = malloc(len + 1);
	if (arg)
	{
		ft_strncpy(arg, start, len);
		arg[len] = '\0';
	}
	if (**cmd == quote)
		(*cmd)++;
	return (arg);
}

static char	*extract_non_quoted(char **cmd)
{
	char	*start;
	int		len;
	char	*arg;

	start = *cmd;
	while (**cmd && !ft_isspace(**cmd) && **cmd != '\'' && **cmd != '\"')
	{
		(*cmd)++;
	}
	len = *cmd - start;
	arg = malloc(len + 1);
	if (arg)
	{
		ft_strncpy(arg, start, len);
		arg[len] = '\0';
	}
	return (arg);
}

char	**parse_command_line(char *cmd)
{
	char	**args;
	int		i;

	args = calloc(20, sizeof(char *));
	if (!args)
		return (NULL);
	i = 0;
	while (*cmd && i < 20 - 1)
	{
		while (ft_isspace(*cmd))
			cmd++;
		if (*cmd == '\'' || *cmd == '\"')
			args[i] = extract_quoted(&cmd);
		else if (*cmd)
			args[i] = extract_non_quoted(&cmd);
		if (!args[i])
		{
			free_str_array(args);
			return (NULL);
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}
