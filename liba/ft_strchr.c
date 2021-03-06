/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 14:59:14 by sysilla           #+#    #+#             */
/*   Updated: 2020/11/18 16:14:33 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *r;

	r = (char *)s;
	while (*r != c)
	{
		if (*r == '\0')
			return (NULL);
		r++;
	}
	return (r);
}
