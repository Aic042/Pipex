/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:45:53 by root              #+#    #+#             */
/*   Updated: 2025/03/26 16:23:30 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// void fork(int infile, int outfile, int pipefd[2], char **argv, char **envp)
// {
//     if (fork() == 0) {
//         dup2(infile, STDIN_FILENO);
//         close(infile);
//         dup2(pipefd[1], STDOUT_FILENO);
//         close(pipefd[0]);
//         close(pipefd[1]);
//         execute_command(argv[2], envp);
//     }
//     if (fork() == 0) {
//         dup2(pipefd[0], STDIN_FILENO);
//         close(pipefd[0]);
//         close(pipefd[1]);
//         dup2(outfile, STDOUT_FILENO);
//         close(outfile);
//         execute_command(argv[3], envp);
//     }
// }