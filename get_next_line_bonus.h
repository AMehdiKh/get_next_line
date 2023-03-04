/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-khel <ael-khel@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:33:49 by ael-khel          #+#    #+#             */
/*   Updated: 2022/11/12 02:28:00 by ael-khel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*ft_strjoin(char **reserve, char *buffer);
char	*ft_check_nl(char **reserve);
char	*ft_strdup(char **reserve);
char	*get_next_line(int fd);

void	ft_strlcpy(char *dst, const char *src, size_t size);

void	*ft_free(char **ptr1);

size_t	ft_strlen(const char *s);

int		ft_strchr(char *s, int c);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337

# endif
#endif
