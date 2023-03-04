/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:30:22 by ael-khel          #+#    #+#             */
/*   Updated: 2022/11/12 03:13:43 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_check_nl(char **reserve)
{
	char	*line;
	char	*tmp;
	int		len;
	int		i;

	i = 0;
	while (*(*reserve + i) != '\n')
		++i;
	line = malloc(i + 2);
	if (!line)
		return (ft_free(reserve));
	ft_strlcpy(line, *reserve, (i + 2));
	len = ft_strlen(*reserve + i + 1);
	if (!len)
		ft_free(reserve);
	else
	{
		tmp = malloc(len + 1);
		ft_strlcpy(tmp, (*reserve + i + 1), (len + 1));
		ft_free(reserve);
		*reserve = malloc(len + 1);
		ft_strlcpy(*reserve, tmp, (len + 1));
		free (tmp);
	}
	return (line);
}

char	*ft_strjoin(char **reserve, char *buffer)
{
	char	*tmp;

	tmp = malloc(ft_strlen(*reserve) + ft_strlen(buffer) + 1);
	if (!tmp)
		return (ft_free(reserve));
	ft_strlcpy(tmp, *reserve, ft_strlen(*reserve) + 1);
	ft_strlcpy((tmp + ft_strlen(tmp)),
		buffer, ft_strlen(buffer) + 1);
	ft_free(reserve);
	return (tmp);
}

char	*ft_strdup(char **reserve)
{
	char	*dup;

	if (!**reserve)
		return (ft_free(reserve));
	dup = malloc(ft_strlen(*reserve) + 1);
	if (!dup)
		return (ft_free(reserve));
	ft_strlcpy(dup, *reserve, ft_strlen(*reserve) + 1);
	ft_free(reserve);
	return (dup);
}

char	*get_next_line(int fd)
{
	char		buffer[(-(BUFFER_SIZE < 0) * BUFFER_SIZE) + (
			(BUFFER_SIZE > 0) * BUFFER_SIZE) + 1];
	static char	*reserve;
	int			nbyte;

	if (fd < 0 || fd == 1 || fd == 2 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!reserve)
	{
		reserve = malloc(1);
		*reserve = '\0';
	}
	while (1)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
			return (ft_free(&reserve));
		if (!nbyte && !ft_strchr(reserve, '\n'))
			return (ft_strdup(&reserve));
		buffer[nbyte] = '\0';
		if (nbyte)
			reserve = ft_strjoin(&reserve, buffer);
		if (ft_strchr(reserve, '\n'))
			return (ft_check_nl(&reserve));
	}
}
