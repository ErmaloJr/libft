/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 22:25:37 by eramusho          #+#    #+#             */
/*   Updated: 2023/03/03 22:37:22 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoinm(char *str_static, char *buffer)
{
	unsigned int	len;
	char			*str;

	if (!str_static)
	{
		str_static = (char *)malloc(1 * sizeof(char));
		str_static[0] = '\0';
	}
	if (!str_static || !buffer)
		return (0);
	len = ft_strlen(str_static) + ft_strlen(buffer);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	ft_strcpy(str, str_static);
	len = ft_strlen(str_static);
	ft_strcpy(&str[len], buffer);
	free(str_static);
	return (str);
}

char	*ft_print_line(char *str_static)
{
	int		index;
	char	*line;

	index = 0;
	if (!str_static[index])
		return (NULL);
	while (str_static[index] != '\0' && str_static[index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = 0;
	while (str_static[index] && str_static[index] != '\n')
	{
		line[index] = str_static[index];
		index++;
	}
	if (str_static[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_next_buffer(char *str_static)
{
	int		index;
	char	*line;

	index = 0;
	while (str_static[index] != '\0' && str_static[index] != '\n')
		index++;
	if (!str_static[index])
		return (free(str_static), NULL);
	line = (char *)malloc(sizeof(char) * (ft_strlen(str_static) - index + 1));
	if (!line)
		return (NULL);
	index++;
	ft_strcpy(line, &str_static[index]);
	free(str_static);
	return (line);
}

char	*ft_read_buffer(int fd, char *str_static)
{
	int		buflen;
	char	*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buflen = 1;
	while (!ft_strchr(str_static, '\n') && buflen != 0)
	{
		buflen = read(fd, buffer, BUFFER_SIZE);
		if (buflen == -1)
			return (free(buffer), free(str_static), NULL);
		buffer[buflen] = '\0';
		str_static = ft_strjoinm(str_static, buffer);
	}
	return (free(buffer), str_static);
}

char	*get_next_line(int fd)
{
	static char	*str_static;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_static = ft_read_buffer(fd, str_static);
	if (!str_static)
		return (NULL);
	s = ft_print_line(str_static);
	str_static = ft_next_buffer(str_static);
	return (s);
}
