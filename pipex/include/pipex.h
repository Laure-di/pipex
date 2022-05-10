/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 19:33:07 by lauremass         #+#    #+#             */
/*   Updated: 2021/11/01 20:13:23 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_data
{
	char	**child;
	char	**parent;
	char	*cmd1;
	char	*cmd2;
	int		infile;
	int		outfile;
	char	**env_path;
	int		fd[2];
	char	*path;
	pid_t	pid[2];
}	t_data;

/* Fichier pipex.c */
int		main(int argc, char **argv, char **env);
void	execute_cmd1(t_data *data, char **env);
void	execute_cmd2(t_data *data, char **env);
int		find_path(t_data *data, char *cmd);
/* Fichier parsing.c */
char	**get_cmd(char *argv);
char	**path(char **env);
char	*get_path(char **env);
int		parse_data(t_data *data, char **argv, char **env);
/* Fichier libft.c */
char	*ft_substr(char *s, int start, size_t len);
char	*ft_strdup(char *s1);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
/* Fichier ft_splic.c */
char	**ft_split(char *s, char c);
void	*free_double_tab(char **tab);
void	*free_double_tab(char **tab);
size_t	count_word(char *s_bis, char c_sep);
size_t	is_sep(char schar, char sep);
/* Fichier fd_write.c */
void	fd_putstr(char *msg, int fd);
/* Fichier exit.c */
void	close_fd(t_data *data);
void	clear_data(t_data *data);
void	clear_close(t_data *data);
void	manage_error(char *str, t_data *data);

#endif
