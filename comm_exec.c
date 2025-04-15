/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aingunza <aingunza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:24:35 by root              #+#    #+#             */
/*   Updated: 2025/04/15 16:07:37 by aingunza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder_utils(char *cmd, char **allpath)
{
	int		i;
	char	*exec;
	char	*path_part;

	i = -1;
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	return (NULL);
}

char	*path_finder(char **s_cmd, char **env)
{
	char	**allpath;
	char	*result;

	if (ft_strchr(s_cmd[0], '/'))
	{
		if (access(s_cmd[0], F_OK | X_OK) == 0)
			return (ft_strdup(s_cmd[0]));
		return (NULL);
	}
	allpath = ft_split(get_env("PATH", env), ':');
	if (!allpath)
		return (NULL);
	result = path_finder_utils(s_cmd[0], allpath);
	ft_free_str(allpath);
	return (result);
}

void	exec(char *cmd, char **env)
{
	char	**s_cmd;
	char	*path;

	s_cmd = ft_split(cmd, ' ');
	path = path_finder(s_cmd, env);
	if (!path)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_str(s_cmd);
		exit(127);
	}
	if (execve(path, s_cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(s_cmd[0], 2);
		ft_free_str(s_cmd);
		free(path);
		exit(127);
	}
}

char	*get_env(char *name, char **env)
{
	int		i;
	size_t	len;

	if (!name || !env)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}
