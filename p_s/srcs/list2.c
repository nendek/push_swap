/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:25:59 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/17 14:31:06 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_list_clear(t_cmd_list **begin_list)
{
	t_cmd_list	*temp;

	while (*begin_list)
	{
		temp = (*begin_list)->next;
		free(*begin_list);
		*begin_list = temp;
	}
}

void	ft_list_clear_all(t_solution *sol)
{
	int i;

	i = 0;
	while (i < NB_SOL)
	{
		ft_list_clear(&sol->tab[i]);
		i++;
	}
}

void	ft_init(t_solution *sol)
{
	int i;

	i = 0;
	while (i < NB_SOL)
	{
		sol->tab[i] = NULL;
		i++;
	}
}
