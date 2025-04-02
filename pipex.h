/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:01:02 by root              #+#    #+#             */
/*   Updated: 2025/04/02 08:53:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"

void	ft_init_pipex(int *p_fd, char **argv);
void	ft_check_args(int argc, char **argv);
void	ft_parse_cmds(char **argv, char **env, int *p_fd);
void	ft_cleanup(int infile, int outfile, int *p_fd);
void	exec(char *cmd, char **env);
char	*path_finder(char *cmd, char **env);
char	*get_env(char *name, char **env);
void	ft_free_str(char **tab);

#endif