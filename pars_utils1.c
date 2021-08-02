/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 15:09:27 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/22 15:09:29 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			freetwomas(char **m)
{
	int			i;

	i = 0;
	while (m[i])
		free(m[i++]);
	free(m);
}

void			freestrukt(t_settings *set)
{
	free(set->sprordr);
	free(set->sprdst);
	free(set->sp);
	free(set->pth_sp);
	free(set->path_ea);
	free(set->path_no);
	free(set->path_so);
	free(set->path_we);
	free(set->map);
	free(set);
}

void			freelist(t_list **head)
{
	t_list		*old;

	while ((*head)->next != NULL)
	{
		old = (*head);
		free((*head)->content);
		(*head) = (*head)->next;
		free(old);
	}
	free((*head)->content);
	free((*head));
}

int				thisisidentif(char *line)
{
	if (ft_strnstr(line, "R ", ft_strlen(line)) ||
		ft_strnstr(line, "NO ", ft_strlen(line)) ||
		ft_strnstr(line, "SO ", ft_strlen(line)) ||
		ft_strnstr(line, "WE ", ft_strlen(line)) ||
		ft_strnstr(line, "EA ", ft_strlen(line)) ||
		ft_strnstr(line, "S ", ft_strlen(line)) ||
		ft_strnstr(line, "F ", ft_strlen(line)) ||
		ft_strnstr(line, "C ", ft_strlen(line)))
		return (1);
	return (0);
}

int				checkline(char *line, int f)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			if (f == 0)
				free(line);
			return (1);
		}
		i++;
	}
	if (f == 0)
		free(line);
	return (0);
}
