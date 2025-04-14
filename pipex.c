/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:39:22 by aingunza          #+#    #+#             */
/*   Updated: 2025/04/08 11:35:56 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	int		status;
	pid_t	pid1;
	pid_t	pid2;

	ft_check_args(argc, argv);
	pipe_checker(p_fd);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
		children(argv, p_fd, env);
	pid2 = fork();
	if (pid2 == -1)
		exit(1);
	if (pid2 == 0)
		parent(argv, p_fd, env);
	ft_cleanup(-1, -1, p_fd);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (0);
}
