/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-he <jdiaz-he@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:01:18 by jdiaz-he          #+#    #+#             */
/*   Updated: 2023/03/01 14:14:36 by jdiaz-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next_line_buffer(char *buffer)
{
	ssize_t	len;
	char	*line;

	if (!buffer || !*buffer)
		return (NULL);
	len = ft_strchr_index(buffer, ft_strlen(buffer), '\n');
	if (len < 0)
		return (NULL);
	line = ft_calloc(len + 2, sizeof(char));
	if (!line)
		return (NULL);
	len++;
	while (len--)
		line[len] = buffer[len];
	return (line);
}

char	*ft_next_buffer(char *buffer)
{
	ssize_t	i;
	size_t	j;
	char	*next_buffer;

	if (!buffer)
		return (NULL);
	i = ft_strchr_index(buffer, ft_strlen(buffer), '\n');
	if (i < 0)
		return (buffer);
	next_buffer = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!next_buffer)
		return (NULL);
	j = 0;
	while (buffer[++i])
		next_buffer[j++] = buffer[i];
	free(buffer);
	return (next_buffer);
}

char	*ft_read_line_buffer(int fd)
{
	char	*line_buffer;
	ssize_t	r;

	line_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line_buffer)
		return (NULL);
	r = read(fd, line_buffer, BUFFER_SIZE);
	if (r <= 0)
	{
		free(line_buffer);
		return (NULL);
	}
	return (line_buffer);
}

char	*ft_gnl_by_buffer(int fd, char **buffer, char *line)
{
	char	*line_buffer;

	while (!line)
	{
		line = ft_next_line_buffer(*buffer);
		if (!line)
		{
			line_buffer = ft_read_line_buffer(fd);
			if (!line_buffer)
			{
				if (*buffer && **buffer)
					line = *buffer;
				else
					free(*buffer);
				*buffer = NULL;
				break ;
			}
			else
				*buffer = ft_strjoin(*buffer, line_buffer,
						*buffer, line_buffer);
		}
		else
			*buffer = ft_next_buffer(*buffer);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buff[FOPEN_MAX];
	char		*line;

	if (fd > FOPEN_MAX)
		return (NULL);
	if (read(fd, 0, 0) < 0)
	{
		free(buff[fd]);
		buff[fd] = NULL;
		return (NULL);
	}
	line = NULL;
	line = ft_gnl_by_buffer(fd, &buff[fd], line);
	return (line);
}

// int main(void)
// {
// 	int	fd1;
// 	char *l1;
// 	fd1 = open("f3", O_RDONLY);
// 	l1 = get_next_line(1000);
// 	printf("fd invalido y fuera de rango");
// 	printf("1- %s -$\n", l1);
// 	// printf("$-1 %i -$\n", l1[1]);
// 	//printf("$-1 %i -$", l1[2]);
// 	free(l1);
// 	l1 = get_next_line(fd1);
// 	printf("2- %s -$\n", l1);
// 	//printf("$-1 %i -$", l1[1]);
// 	//printf("$-1 %i -$", l1[2]);
// 	free(l1);
// 	l1 = get_next_line(fd1);
// 	printf("3- %s -$\n", l1);
// 	free(l1);
// 	l1 = get_next_line(fd1);
// 	printf("4- %s -$\n", l1);
// 	free(l1);
// 	l1 = get_next_line(fd1);
// 	printf("5- %s -$\n", l1);
// 	free(l1);
// 	l1 = get_next_line(fd1);
// 	printf("6- %s -$\n", l1);
// 	free(l1);
// 	l1 = get_next_line(fd1);
// 	printf("7- %s -$\n", l1);
// 	free(l1);
// 	return 0;
// }