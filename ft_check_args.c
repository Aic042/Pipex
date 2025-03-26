/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:12 by root              #+#    #+#             */
/*   Updated: 2025/03/26 16:21:48 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_coms(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Argument error: Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(1);
	}
	if (strlen(argv[2]) == 0)
	{
		ft_printf("Error: Command 1 is empty\n");
		exit(1);
	}
	if (strlen(argv[3]) == 0)
	{
		ft_printf("Error: Command 2 is empty\n");
		exit(1);
	}
}

int	check_files(char *infile)
{
	if (access(infile, F_OK) == -1)
	{
		ft_printf("Error: %s: No such file or directory\n", infile);
		return (1);
	}
	return (0);
}

void	duplikate(int infile, int outfile)
{
	if (dup2(infile, STDIN_FILENO) == -1)
		exit(1);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		exit(1);
	close(infile);
	close(outfile);
}

int	main(int argc, char **argv)
{
	int	fd_in;
	int	fd_out;

	check_coms(argc, argv);
	check_files(argv[1]);
	fd_in = open(argv[1], O_RDONLY);
	fd_out = open(argv[4], O_WRONLY, O_TRUNC, O_CREAT);
	duplikate(fd_in, fd_out);
	return (0);
}
