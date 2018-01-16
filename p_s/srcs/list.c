/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:09:42 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 18:32:11 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_clear(t_cmd_list **begin_list)
{
	t_cmd_list	*del;
	t_cmd_list	*temp;

	del = *begin_list;
	if (del)
		while (del->next)
		{
			temp = del->next;
			free(del);
			del = temp;
		}
	*begin_list = NULL;
}

t_cmd_list		*ft_create_elem(char *cmd)
{
	t_cmd_list *tmp;

	if (!(tmp = malloc(sizeof(t_cmd_list))))
		exit (EXIT_FAILURE);
	if (tmp)
	{
		ft_strcpy(tmp->cmd, cmd);
		tmp->next = NULL;
	}
	return (tmp);
}

void			ft_pushback_cmd(t_cmd_list **beginlist, char *cmd)
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

int				ft_lentgh_list(t_cmd_list *list)
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

void			ft_put_list(t_cmd_list *list)
{
	while (list)
	{
		ft_printf("%s\n", list->cmd);
		list = list->next;
	}
}
