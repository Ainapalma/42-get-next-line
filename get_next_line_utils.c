/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agermoge <agermoge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:36:57 by agermoge          #+#    #+#             */
/*   Updated: 2021/05/13 12:27:06 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strchr(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (c == '\0')
		return ((char*)str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c)
			return ((char*)str + i);
		i++;
	}
	return (NULL);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
			+ 1))))
		return (NULL);
	while (s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	free(s1);
	return (s3);
}
