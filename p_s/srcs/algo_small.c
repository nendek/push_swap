/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:47:36 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/12 11:30:52 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_search_small_for_small(int *tab, int last)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i != last + 1)
	{
		if (tab[i] < tab[j])
			j = i;
		i++;
	}
	return (j);
}

static void	ft_place_ra(int *tab, t_nbr *nbr, t_cmd_list **cmd, int p)
{
	if (tab[nbr->last_a] > tab[nbr->last_a - 1] && nbr->last_a != nbr->pivot_a && nbr->last_a - 1 != nbr->pivot_a && (p == 2 || p == 3))
		ft_sa_list(tab, nbr->last_a, cmd);
	ft_ra_list(tab, nbr->last_a, cmd);
	nbr->pivot_a++;
}

static void	ft_place_rra(int *tab, t_nbr *nbr, t_cmd_list **cmd, int p)
{
	if (tab[nbr->last_a] > tab[nbr->last_a - 1] && nbr->last_a != nbr->pivot_a && nbr->last_a - 1 != nbr->pivot_a && (p == 2 || p == 3))
		ft_sa_list(tab, nbr->last_a, cmd);
	ft_rra_list(tab, nbr->last_a, cmd);
	nbr->pivot_a--;
	if (nbr->pivot_a < 0)
		nbr->pivot_a = nbr->last_a;
}

int		ft_sort_small(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p)
{
	while (!(ft_is_sort(tab.pile_a, nbr.last_a)))
	{
		if (tab.pile_a[nbr.last_a] > tab.pile_a[nbr.last_a - 1] && (p == 1 || p == 2))
			ft_sa_list(tab.pile_a, nbr.last_a, cmd);
		nbr.pivot_a = ft_search_small_for_small(tab.pile_a, nbr.last_a);
		if (nbr.pivot_a >= nbr.last_a / 2)
			while (nbr.pivot_a != nbr.last_a)
				ft_place_ra(tab.pile_a, &nbr, cmd, p);
		else
			while (nbr.pivot_a != nbr.last_a)
				ft_place_rra(tab.pile_a, &nbr, cmd, p);
		if (!(ft_is_sort(tab.pile_a, nbr.last_a)))
			ft_pb_list(tab, &nbr.last_b, &nbr.last_a, cmd);
	}
	while (nbr.last_b != -1)
		ft_pa_list(tab, &nbr.last_a, &nbr.last_b, cmd);
	return (0);
}
