/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:39:22 by aingunza          #+#    #+#             */
/*   Updated: 2025/04/03 12:19:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include "pipex.h"

int     main(int argc, char **argv, char **env)
{
    int     p_fd[2];
    int     status;
    pid_t   pid;

    ft_check_args(argc, argv);
    ft_parse_cmds(argv, env, p_fd);
    pid = waitpid(-1, &status, 0);
    while (pid > 0)
        pid = waitpid(-1, &status, 0);
    if (WIFEXITED(status))
        return (WEXITSTATUS(status));
    return (0);
}
