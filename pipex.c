/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:39:22 by aingunza          #+#    #+#             */
/*   Updated: 2025/04/02 00:00:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
    int infile;
    int outfile;
    int p_fd[2];

    ft_check_args(argc, argv); // Exits on invalid args
    infile = open(argv[1], O_RDONLY);
    if (infile == -1)
    {
        ft_printf("Error: %s: No such file or directory\n", argv[1]);
        exit(1);
    }
    outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile == -1)
    {
        ft_printf("Error: %s: Failed to create/open output file\n", argv[4]);
        close(infile);
        exit(1);
    }
    ft_parse_cmds(argv, env); // Update this to use infile/outfile if needed
    ft_cleanup(infile, outfile, p_fd);
    // wait(NULL);
    // wait(NULL);
    return (0);
}