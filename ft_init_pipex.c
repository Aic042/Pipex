/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:04 by root              #+#    #+#             */
/*   Updated: 2025/03/31 12:01:34 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	exit_handler(int n_exit)
// {
// 	if (n_exit == 1)
// 		printf("Error de salida: Salida inesperada");
// 	exit(0);
// }

void	child(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(1);
	close(p_fd[0]);
	exec(argv[2], env);
}

void	parent(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open(argv[4], 1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(1);
	close(p_fd[1]);
	exec(argv[3], env);
}

void	ft_init_pipex(char **argv, int *p_fd, char **env)
{
	child(argv, p_fd, env);
	parent(argv, p_fd, env);
}

