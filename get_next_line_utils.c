/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:30:19 by ael-khel          #+#    #+#             */
/*   Updated: 2022/11/12 02:32:35 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	if (size)
	{
		while (--size && *src)
			*dst++ = *src++;
		*dst = '\0';
	}
}

int	ft_strchr(char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
		if (*s++ == (char)c)
			return (1);
	return (0);
}

void	*ft_free(char **ptr1)
{
	if (ptr1)
	{
		if (*ptr1)
		{
			free(*ptr1);
			*ptr1 = NULL;
		}
	}
	return (NULL);
}
