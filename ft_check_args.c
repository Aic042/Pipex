/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:12 by root              #+#    #+#             */
/*   Updated: 2025/04/14 12:24:27 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_infiles(char *infile)
{
	if (access(infile, F_OK) == -1)
	{
		ft_printf("Error: %s: No such file or directory\n", infile);
		exit(EXIT_FAILURE);
	}
	return (0);
}

void	ft_check_outfile_permissions(const char *file)
{
	int	fd;

	if (access(file, F_OK) == 0)
	{
		if (access(file, W_OK) == -1)
		{
			ft_putstr_fd("pipex: ", 2);
			ft_putstr_fd(file, 2);
			ft_putendl_fd(": Permission denied", 2);
			exit(1);
		}
	}
	else
	{
		fd = open(file, O_CREAT | O_WRONLY, 0644);
		if (fd == -1)
		{
			perror("Error");
		}
		close(fd);
	}
}

void	ft_check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Argument error: Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(1);
	}
	// if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[2]) == 1)
	// {
	// 	ft_printf("Error: Command 1 is empty\n");
	// 	exit(127);
	// }
	// if (ft_strlen(argv[3]) == 0 || ft_strlen(argv[3]) == 1)
	// {
	// 	ft_printf("Error: Command 2 is empty\n");
	// 	exit(127);
	// }
	if (
		ft_isspace(argv[2][0]) == 1 || ft_isspace(argv[3][0]) == 1)
	{
		ft_printf("Error: Command 1/2 has space first\n");
		exit(127);
	}
}
