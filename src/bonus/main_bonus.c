/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:34:21 by leochen           #+#    #+#             */
/*   Updated: 2024/05/30 16:51:28 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int		exit_code;

	exit_code = 0;
	check_arg_bonus(argc);
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		if (argc < 6)
			return (1);
		exit_code = handle_here_doc(argc, argv, envp);
	}
	else
	{
		exit_code = handle_normal_pipes(argc, argv, envp);
	}
	close_all_fds();
	return (exit_code);
}
