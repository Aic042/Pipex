/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 12:01:02 by root              #+#    #+#             */
/*   Updated: 2025/03/31 10:47:48 by aingunza         ###   ########.fr       */
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

void	ft_free_tab(char **tab);
void	exec(char *cmd, char **env);
char	*path_finder(char *cmd, char **env);
int		exit_handler(int n_exit);

void	ft_init_pipex(infile, outfile, p_fd, argv);
void	ft_check_args(argc, argv);
void	ft_parse_cmds(argv, env);
void	ft_cleanup(infile, outfile, p_fd);
#endif