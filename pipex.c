/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:17 by root              #+#    #+#             */
/*   Updated: 2025/03/23 18:07:26 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
    if (argc != 5)
    {
        write(2, "Error: Uso: ./pipex archivo1 cmd1 cmd2 archivo2\n", 48);
        return (1);
    }
    int infile = open(argv[1], O_RDONLY);
    if (infile < 0) {
        perror("Error opening infile");
        return 1;
    }
	fork_checker(int infile, int outfile, int pipefd[2], char **argv, char **envp); 
    int outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (outfile < 0) {
        perror("Error opening outfile");
        close(infile);
        return 1;
    }

    int pipefd[2];
    if (pipe(pipefd) < 0) {
        perror("Pipe failed");
        close(infile);
        close(outfile);
        return 1;
    }
    close(infile);
    close(outfile);
    close(pipefd[0]);
    close(pipefd[1]);

    while (wait(NULL) > 0);

    return 0;
}
