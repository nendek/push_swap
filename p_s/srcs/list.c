/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:09:42 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/10 14:31:36 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cmd_list *ft_create_elem(char *cmd)
{
	t_cmd_list *tmp;

	tmp = malloc(sizeof(t_cmd_list));

	if (tmp)
	{
		ft_strcpy(tmp->cmd, cmd);
		tmp->next = NULL;
	}
	return (tmp);
}

void		ft_pushback_cmd(t_cmd_list **beginlist, char *cmd)
{
	t_cmd_list *list;

	list = *beginlist;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(cmd);
	}
	else
		*beginlist = ft_create_elem(cmd);
}

int		ft_lentgh_list(t_cmd_list *list)
{
	int i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	ft_put_list(t_cmd_list *list)
{
	while (list)
	{
		ft_printf("%s\n", list->cmd);
		list = list->next;
	}
}
