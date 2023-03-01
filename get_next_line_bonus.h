/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-he <jdiaz-he@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:03:33 by jdiaz-he          #+#    #+#             */
/*   Updated: 2023/03/01 13:51:47 by jdiaz-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_gnl_by_char(int fd);
char	*ft_gnl_by_buffer(int fd, char **buffer, char *line);
char	*ft_read_line_buffer(int fd);
char	*ft_next_line_buffer(char *buffer);
char	*ft_next_buffer(char *buffer);
char	*ft_strjoin(char *s1, char *s2, char *free_s1, char *free_s2);
void	ft_bzero(void *mem, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
ssize_t	ft_strchr_index(char *buffer, ssize_t buffer_size, char c);

#endif