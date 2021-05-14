/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agermoge <agermoge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 17:36:00 by agermoge          #+#    #+#             */
/*   Updated: 2021/05/14 15:58:43 by agermoge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*free_and_return_null(char *str)
{
	free(str);
	return (NULL);
}

static char		*ft_strdup(char *str)
{
	int			i;
	char		*dup;
	size_t		len;

	i = 0;
	len = ft_strlen(str);
	dup = (char*)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char		*check_remainder(char **remainder, char **line)
{
	char		*ptr_n;

	ptr_n = NULL;
	if (*remainder)
	{
		if ((ptr_n = ft_strchr(*remainder, '\n')) != 0)
		{
			*ptr_n++ = '\0';
			*line = ft_strdup(*remainder);
			if (*ptr_n)
				ft_strcpy(*remainder, ptr_n);
			else
				*remainder = free_and_return_null(*remainder);
		}
		else
		{
			*line = ft_strdup(*remainder);
			*remainder = free_and_return_null(*remainder);
		}
	}
	else
		*line = ft_strdup("");
	return (ptr_n);
}

static int		find_n(char **ptr_n, char *buf, char **remainder, char **line)
{
	if ((*ptr_n = ft_strchr(buf, '\n')))
	{
		*(*ptr_n)++ = '\0';
		if (**ptr_n && !(*remainder = ft_strdup(*ptr_n)))
		{
			free(remainder);
			free(buf);
			return (-1);
		}
	}
	if (!(*line = ft_strjoin(*line, buf)))
	{
		free(remainder);
		free(buf);
		return (-1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	char		*ptr_n;
	int			bytes_read;

	buf = NULL;
	if (line == NULL || BUFFER_SIZE <= 0 || fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if ((!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
	{
		free(remainder);
		return (-1);
	}
	ptr_n = check_remainder(&remainder, line);
	while ((ptr_n == NULL) && ((bytes_read = read(fd, buf, BUFFER_SIZE)) > 0))
	{
		buf[bytes_read] = '\0';
		if (find_n(&ptr_n, buf, &remainder, line) == -1)
			return (-1);
	}
	free(buf);
	return (ptr_n ? 1 : 0);
}
