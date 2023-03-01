/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdiaz-he <jdiaz-he@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:31:48 by jdiaz-he          #+#    #+#             */
/*   Updated: 2023/03/01 14:01:07 by jdiaz-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *mem, size_t size)
{
	if (!mem)
		return ;
	while (size)
		((char *) mem)[--size] = '\0';
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem;

	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

char	*ft_strjoin(char *s1, char *s2, char *free_s1, char *free_s2)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = ft_calloc(len, sizeof(char));
	if (!str)
		return (NULL);
	while (s1 && *s1)
		*str++ = *s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = '\0';
	if (free_s1)
		free(free_s1);
	if (free_s2)
		free(free_s2);
	return (str - (len - 1));
}

ssize_t	ft_strchr_index(char *buffer, ssize_t buffer_size, char c)
{
	ssize_t	i;

	i = 0;
	while (buffer && buffer[i] != c && i < buffer_size)
		i++;
	if (buffer && buffer[i] == 0)
		return (-1);
	return (i);
}
