/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:04 by root              #+#    #+#             */
/*   Updated: 2025/04/08 11:53:14 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_handler(int n_exit)
{
	if (n_exit == 1)
		printf("Error de salida: Salida inesperada");
	exit(127);
}

void	children(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putendl_fd(": No such file or directory", 2);
		exit(1);
	}
	if (dup2(fd, STDIN_FILENO) == -1)
		exit(1);
	if (dup2(p_fd[1], STDOUT_FILENO) == -1)
		exit(1);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(argv[2], env);
}

void	parent(char **argv, int *p_fd, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[4], 2);
		ft_putendl_fd(": Permission denied", 2);
		close(p_fd[0]);
		close(p_fd[1]);
		exit(1);
	}
	if (dup2(p_fd[0], STDIN_FILENO) == -1)
		exit(1);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit(1);
	close(fd);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(argv[3], env);
	exit(127);
}

void	pipe_checker(int *p_fd)
{
	if (pipe(p_fd) == -1)
	{
		ft_printf("Error: pipe creation failed\n");
		exit(1);
	}
}
