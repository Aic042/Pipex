/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comm_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:24:35 by root              #+#    #+#             */
/*   Updated: 2025/04/14 22:55:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*path_finder(char **s_cmd, char **env)
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	*path_env;

	i = 0;
	path_env = get_env("PATH", env);
	if (!path_env || !*path_env)
	{
		ft_putstr_fd("pipex: Path not found", 2);
		return (NULL);
	}
	allpath = ft_split(path_env, ':');
	while (allpath[i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, s_cmd[0]);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
		{
			ft_free_str(allpath);
			return (exec);
		}
		free(exec);
		i++;
	}
	ft_free_str(allpath);
	return (NULL);
}

void	exec(char *cmd, char **env)
{
	char **s_cmd;
	char *path;

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
