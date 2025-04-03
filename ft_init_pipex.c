/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:04 by root              #+#    #+#             */
/*   Updated: 2025/04/03 12:19:20 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_handler(int n_exit)
{
	if (n_exit == 1)
		printf("Error de salida: Salida inesperada");
	exit(127);
}

void    child(char **argv, int *p_fd, char **env)
{
    int     fd;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error: %s: No such file or directory\n", argv[1]);
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

void    parent(char **argv, int *p_fd, char **env)
{
    int     fd;

    fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        ft_printf("Error: %s: Failed to create/open output file\n", argv[4]);
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
}

void    ft_parse_cmds(char **argv, char **env, int *p_fd)
{
    pid_t   pid1;
    pid_t   pid2;

    if (pipe(p_fd) == -1)
    {
        ft_printf("Error: pipe creation failed\n");
        exit(1);
    }
    pid1 = fork();
    if (pid1 == -1)
        exit(1);
    if (pid1 == 0)
        child(argv, p_fd, env);
    pid2 = fork();
    if (pid2 == -1)
        exit(1);
    if (pid2 == 0)
        parent(argv, p_fd, env);
    ft_cleanup(-1, -1, p_fd);
}
