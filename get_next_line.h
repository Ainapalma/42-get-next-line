/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agermoge <agermoge@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:30:38 by agermoge          #+#    #+#             */
/*   Updated: 2021/05/13 11:46:02 by jtrauque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

int				get_next_line(int fd, char **line);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *str, char c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strjoin(char *s1, char *s2);

#endif
