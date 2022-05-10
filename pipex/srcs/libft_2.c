/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauremasson <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:59:04 by lauremass         #+#    #+#             */
/*   Updated: 2021/10/21 12:03:20 by lauremass        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_substr(char *s, int start, size_t len)
{
	char			*s_bis;
	size_t			i;
	size_t			len_to_copy;

	i = 0;
	if (!s)
		return (NULL);
	len_to_copy = ft_strlen(&s[start]);
	if (len_to_copy < len)
		len = len_to_copy;
	if (ft_strlen(s) <= start || len <= 0)
		return (ft_strdup(""));
	s_bis = malloc(sizeof(char) * (len + 1));
	if (!s_bis)
		return (NULL);
	while (i < len && s[start + i])
	{
		s_bis[i] = s[start + i];
		i++;
	}
	s_bis[i] = '\0';
	return (s_bis);
}
