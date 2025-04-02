/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:12 by root              #+#    #+#             */
/*   Updated: 2025/04/02 15:29:24 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_files(char *infile)
{
	if (access(infile, F_OK) == -1)
	{
		ft_printf("Error: %s: No such file or directory\n", infile);
		return (1);
	}
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Argument error: Usage: ./pipex infile cmd1 cmd2 outfile\n");
		exit(1);
	}
	if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[2]) == 1)
	{
		ft_printf("Error: Command 1 is empty\n");
		exit(127);
	}
	if (ft_strlen(argv[3]) == 0 || ft_strlen(argv[2]) == 1)
	{
		ft_printf("Error: Command 2 is empty\n");
		exit(127);
	}
	if (access(argv[1], F_OK) == -1)
	{
		ft_printf("Error: %s: No such file or directory\n", argv[1]);
		exit(1);
	}
}
