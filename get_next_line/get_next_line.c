/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdelbecq <hdelbecq@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:32:32 by hdelbecq          #+#    #+#             */
/*   Updated: 2024/09/19 15:25:44 by hdelbecq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_next_line(char **old_line, int fd)
{
	int		bytes_read;
	char	*next_line;

	free(*old_line);
	*old_line = NULL;
	next_line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!next_line)
		return (NULL);
	bytes_read = read(fd, next_line, BUFFER_SIZE);
	if (bytes_read == 0)
	{
		free(next_line);
		next_line = NULL;
		return (NULL);
	}
	if (bytes_read < 0)
		bytes_read = 0;
	next_line[bytes_read] = '\0';
	return (next_line);
}

char	*create_line(char **next_line, char **line, char **t_line, int fd)
{
	while (*next_line && **next_line)
	{
		*t_line = ft_sub_before_chr(*next_line, '\n');
		if (!*t_line)
			*line = ft_strjoin(line, next_line);
		else
		{
			*line = ft_strjoin(line, t_line);
			*t_line = ft_sub_after_chr(*next_line, '\n');
			if (*t_line)
			{
				free(*next_line);
				*next_line = ft_strjoin(t_line, NULL);
				return (*line);
			}
			return (free(*next_line), *next_line = NULL, *line);
		}
		if (!*line)
			return (NULL);
		*next_line = read_next_line(next_line, fd);
		if (*next_line && !**next_line)
			return (free(*next_line), free(*line), *next_line = NULL,
				*line = NULL, NULL);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*line;
	char		*t_line;

	line = NULL;
	t_line = NULL;
	if (fd < 0 || !BUFFER_SIZE || BUFFER_SIZE <= 0 || BUFFER_SIZE >= 2147483647)
		return (NULL);
	if (!next_line)
		next_line = read_next_line(&next_line, fd);
	if (next_line && *next_line)
		line = create_line(&next_line, &line, &t_line, fd);
	if (line == NULL)
	{
		free(t_line);
		t_line = NULL;
		free(next_line);
		next_line = NULL;
	}
	return (line);
}
