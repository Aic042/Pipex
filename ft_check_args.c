/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 20:46:12 by root              #+#    #+#             */
/*   Updated: 2025/03/25 20:22:39 by root             ###   ########.fr       */
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

int check_files(char *infile, char *outfile)
{
	if (access(infile, F_OK) == -1)
	{
		ft_printf("Error: %s: No such file or directory\n", infile);
		return (1);
	}
	// if (access(outfile, F_OK) == -1)
	// {
	// 	ft_printf("Error: %s: No such file or directory\n", outfile);
	// 	return (1);
	// }
	// Debo crear el archivo de regreso "outfile", no verificar si existe. Si existe utiliza el O_TRUNC.
	return (0);
}

int	main(int argc, char **argv)
{
	check_coms(argc, argv);
	check_files(argv[1], argv[4]);
	execute_command(argv[2]);
	execute_command(argv[3]);
	return 0;
}
