/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:21:00 by lauremass         #+#    #+#             */
/*   Updated: 2021/11/01 19:42:01 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	find_path(t_data *data, char *cmd)
{
	int		i;
	char	*temp;

	i = 0;
	if (cmd && access(cmd, X_OK) == 0)
	{
		data->path = ft_strdup(cmd);
		return (1);
	}
	while (data->env_path[i])
	{
		temp = ft_strjoin(data->env_path[i], "/");
		data->path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(data->path, X_OK) == 0)
			return (1);
		free(data->path);
		i++;
	}
	return (0);
}

void	execute_cmd2(t_data *data, char **env)
{
	dup2(data->fd[0], STDIN_FILENO);
	dup2(data->outfile, STDOUT_FILENO);
	close(data->outfile);
	close(data->fd[1]);
	if (find_path(data, data->child[0]) == 0)
		manage_error("Pipex: command not found", data);
	if (execve(data->path, data->child, env) == -1)
		manage_error("Pipex", data);
}

void	execute_cmd1(t_data *data, char **env)
{
	int		status;

	waitpid(-1, &status, 0);
	dup2(data->infile, STDIN_FILENO);
	dup2(data->fd[1], STDOUT_FILENO);
	close(data->infile);
	close(data->fd[0]);
	if (find_path(data, data->parent[0]) == 0)
		manage_error("Pipex: command not found", data);
	if (execve(data->path, data->parent, env) == -1)
		manage_error("Pipex", data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		status;

	if (argc != 5)
	{
		fd_putstr("Structure's error : ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	if (parse_data(&data, argv, env) == 0)
		manage_error("Pipex", &data);
	pipe(data.fd);
	data.pid[0] = fork();
	if (data.pid[0] < 0)
		manage_error("Fork ", &data);
	if (data.pid[0] == 0)
		execute_cmd1(&data, env);
	data.pid[1] = fork();
	if (data.pid[1] < 0)
		manage_error("Fork ", &data);
	if (data.pid[1] == 0)
		execute_cmd2(&data, env);
	close_fd(&data);
	clear_data(&data);
	waitpid(data.pid[0], &status, 0);
	waitpid(data.pid[1], &status, 0);
}
