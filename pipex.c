/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:39:22 by aingunza          #+#    #+#             */
/*   Updated: 2025/03/31 12:01:10 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	int		infile;
	int		outfile;

	ft_init_pipex(infile, outfile, p_fd, argv);
	ft_check_args(argc, argv);
	ft_parse_cmds(argv, env);
	ft_cleanup(infile, outfile, p_fd);
	return (0);
}

int     main(int ac, char **av, char **env)
{
		int		p_fd[2];
        pid_t   pid;

        if (ac != 5)
                exit_handler(1);
        if (pipe(p_fd) == -1)
                exit(-1);
        pid = fork();
        if (pid == -1)
                exit(-1);
        if (!pid)
                child(av, p_fd, env);
        parent(av, p_fd, env);
}