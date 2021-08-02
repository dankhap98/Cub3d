/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_v2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sysilla <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:46:19 by sysilla           #+#    #+#             */
/*   Updated: 2021/03/06 11:46:26 by sysilla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			pars_params(char *line, t_settings *set)
{
	char		*tmp;
	char		*val;

	tmp = ft_substr(line, 2, ft_strlen(line) - 2);
	val = ft_strtrim(tmp, " ");
	if (line[0] == 'R' && line[1] == ' ')
		set_window(set, val);
	else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		set_texture(set, val, 1);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		set_texture(set, val, 2);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		set_texture(set, val, 3);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		set_texture(set, val, 4);
	else if (line[0] == 'S' && line[1] == ' ')
		set_texture(set, val, 5);
	else if (line[0] == 'F' && line[1] == ' ')
		set_color(set, val, 1);
	else if (line[0] == 'C' && line[1] == ' ')
		set_color(set, val, 2);
	free(val);
	free(tmp);
}

int				pars_line(char *conf, t_settings *set)
{
	char		*tmp;

	chkspace(conf);
	tmp = NULL;
	tmp = ft_strtrim(conf, " ");
	if (ft_strchr("RNSWEFC", *tmp))
		pars_params(tmp, set);
	free(tmp);
	free(conf);
	return (1);
}

void			make_map(t_list *head, t_settings *typs)
{
	int			i;
	t_list		*tmp;

	typs->map = ft_calloc(ft_lstsize(head) + 1, sizeof(char *));
	i = -1;
	tmp = head;
	while (tmp)
	{
		typs->map[++i] = tmp->content;
		tmp = tmp->next;
	}
}

void			gnl_loop(t_settings *set, t_list **head, int *f)
{
	char		*line;

	while (get_next_line(set->fd, &line))
	{
		if (thisisidentif(line) && f[1] == 0)
		{
			pars_line(line, set);
			f[2]++;
		}
		else if ((ft_strchr(line, '1') || ft_strchr(line, ' ')) && f[0] == 0)
		{
			f[1] = 1;
			list(line, head, f[0]);
			set->amnt++;
		}
		else if (f[1] == 1 && line[0] == '\0')
			f[0]++;
		else if (line[0] != '\0')
			set->er++;
		else
			set->er += checkline(line, f[0]);
	}
	finalchek(line, head, f[0], f[2]);
}

int				main(int argc, char **argv)
{
	t_list		*head;
	t_settings	*set;
	int			f[4];
	int			i;

	i = -1;
	while (f[++i])
		f[i] = 0;
	head = NULL;
	if (!(set = (t_settings*)malloc(sizeof(t_settings))))
		errmsg("Malloc return NULL");
	struckzr(set);
	set->save = ckeckargs(argc, argv, set);
	gnl_loop(set, &head, f);
	close(set->fd);
	make_map(head, set);
	chkerr(set);
	pos_person(set);
	find_sp(set);
	main_mlx(*set);
	freelist(&head);
	freestrukt(set);
	return (0);
}
