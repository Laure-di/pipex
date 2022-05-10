/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:43:03 by lauremass         #+#    #+#             */
/*   Updated: 2021/11/01 20:08:41 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	manage_error(char *str, t_data *data)
{
	clear_close(data);
	if (errno)
		perror(str);
	else
		fd_putstr(str, 2);
	exit(1);
}

void	clear_close(t_data *data)
{
	clear_data(data);
	close_fd(data);
}

void	clear_data(t_data *data)
{
	if (data->env_path)
		free_double_tab(data->env_path);
	if (data->child)
		free_double_tab(data->child);
	if (data->parent)
		free_double_tab(data->parent);
	if (data->cmd1)
		free(data->cmd1);
	if (data->cmd2)
		free(data->cmd2);
}

void	close_fd(t_data *data)
{
	close(data->infile);
	close(data->outfile);
	close(data->fd[0]);
	close(data->fd[1]);
}
