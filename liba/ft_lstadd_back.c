/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:55:26 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/11 19:55:30 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst)
		{
			if (lst->next == NULL)
				return (lst);
			lst = lst->next;
		}
	return (NULL);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*old;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	old = *lst;
	if (!(old = ft_lstlast(old)))
		return ;
	old->next = new;
}
