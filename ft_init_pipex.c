/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:04 by root              #+#    #+#             */
/*   Updated: 2025/04/01 19:21:19 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_handler(int n_exit)
{
	if (n_exit == 1)
		printf("Error de salida: Salida inesperada");
	exit(0);
}

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

void ft_parse_cmds(char **argv, char **env)
{
    pid_t pid1;
    pid_t pid2;
    int p_fd[2];

    if (pipe(p_fd) == -1)
        exit_handler(1);
    pid1 = fork();
    if (pid1 == 0)
    {
        close(p_fd[0]);
        dup2(open(argv[1], O_RDONLY), STDIN_FILENO);
        dup2(p_fd[1], STDOUT_FILENO);
        close(p_fd[1]);
        exec(argv[2], env);
    }
    pid2 = fork();
    if (pid2 == 0)
    {
        close(p_fd[1]);
        dup2(p_fd[0], STDIN_FILENO);
        dup2(open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644), STDOUT_FILENO);
        close(p_fd[0]);
        exec(argv[3], env);
    }
}
