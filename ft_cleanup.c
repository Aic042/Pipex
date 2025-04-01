/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 18:15:16 by root              #+#    #+#             */
/*   Updated: 2025/04/01 19:20:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void ft_cleanup(int infile, int outfile, int *p_fd)
{
    if (infile != -1)
        close(infile);
    if (outfile != -1)
        close(outfile);
    if (p_fd)
    {
        close(p_fd[0]);
        close(p_fd[1]);
    }
}