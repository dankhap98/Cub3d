/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 19:03:31 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/21 19:03:36 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 100

int		ft_slash(char *str);
char	*gnl_substr(char const *s, unsigned int start, int len);
char	*gnl_strjoin(char const *s1, char const *s2);
int		get_next_line(int fd, char **line);
void	*gnl_memset(void *s, int q, size_t size);
size_t	gnl_strlen(const char *str);

#endif
