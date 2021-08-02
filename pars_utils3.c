/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:45:50 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/25 14:45:51 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	list(char *line, t_list **head, int f)
{
	if (f > 0 && line[0] != '\0')
		errmsg("line");
	ft_lstadd_back(head, ft_lstnew(line));
}

void	finalchek(char *line, t_list **head, int f, int c)
{
	list(line, head, f);
	if (c != 8)
		errmsg("uvalid conf");
}
