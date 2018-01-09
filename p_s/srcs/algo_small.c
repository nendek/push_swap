/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:47:36 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/09 16:37:13 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

int ft_search_small_for_small(int *tab, int last)
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

int ft_sort_small(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p)
{
	t_index i;

	i.b = -1;
	while (!(ft_is_sort(tab.pile_a, nbr.last)))
	{
		dprintf(1, "icic p = %d\n", p);
		if (tab.pile_a[nbr.last] > tab.pile_a[nbr.last - 1] && (p == 1 || p == 2))
			ft_sa_list(tab.pile_a, nbr.last, cmd);
		nbr.pivot = ft_search_small_for_small(tab.pile_a, nbr.last);
		if (nbr.pivot >= nbr.last / 2)
			while (nbr.pivot != nbr.last)
			{
				dprintf(1, "ici2\n");
				if (tab.pile_a[nbr.last] > tab.pile_a[nbr.last - 1] && nbr.last != nbr.pivot && nbr.last - 1 != nbr.pivot && (p == 2 || p == 3))
					ft_sa_list(tab.pile_a, nbr.last, cmd);
				ft_ra_list(tab.pile_a, nbr.last, cmd);
				nbr.pivot++;
			}
		else
			while (nbr.pivot != nbr.last)
			{
				if (tab.pile_a[nbr.last] > tab.pile_a[nbr.last - 1] && nbr.last != nbr.pivot && nbr.last - 1 != nbr.pivot && (p == 2 || p == 3))
					ft_sa_list(tab.pile_a, nbr.last, cmd);
				ft_rra_list(tab.pile_a, nbr.last, cmd);
				nbr.pivot--;
				if (nbr.pivot < 0)
					nbr.pivot = nbr.last;
			}
		if (!(ft_is_sort(tab.pile_a, nbr.last)))
			ft_pb_list(tab, &i.b, &nbr.last, cmd);
	}
	while (i.b != -1)
		ft_pa_list(tab, &nbr.last, &i.b, cmd);
	return (0);
}
