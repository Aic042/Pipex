/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:15:16 by root              #+#    #+#             */
/*   Updated: 2025/01/26 11:59:29 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_closer_postsuccess(int infile, int outfile, int pipefd[2])
{
	close(infile);
	close(outfile);
	close(pipefd[0]);
	close(pipefd[1]);
}
