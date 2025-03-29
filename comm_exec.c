/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:24:35 by root              #+#    #+#             */
/*   Updated: 2025/03/27 21:11:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void exec(char *cmd, char **env)
{
	char **s_cmd;
}

int pipe(int fd[2])
{
	pid_t pid = fork();

	if (pid < 0)
	{
		ft_printf("fork failed");
		return 1;		
	}
	else if(pid == 0)
		ft_printf("hijo")
	
	read(fd[0])
	write(fd[1])
}