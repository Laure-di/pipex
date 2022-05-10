/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:09:53 by lauremass         #+#    #+#             */
/*   Updated: 2021/10/29 11:38:58 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	total_len;
	size_t	i;
	size_t	n;
	char	*s_final;

	i = 0;
	n = 0;
	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	s_final = malloc(sizeof(char) * total_len);
	if (!s_final)
		return (NULL);
	while (s1[n])
		s_final[i++] = (char)s1[n++];
	n = 0;
	while (s2[n])
	{
		s_final[i++] = (char)s2[n];
		n++;
	}
	s_final[i] = '\0';
	return (s_final);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	size_t	i;
	char	*s1_copy;

	len = ft_strlen(s1) + 1;
	i = 0;
	s1_copy = malloc((sizeof(char) * len));
	if (!s1_copy)
		return (NULL);
	while (s1[i])
	{
		s1_copy[i] = s1[i];
		i++;
	}
	s1_copy[i] = '\0';
	return (s1_copy);
}
