/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 15:03:59 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 19:08:49 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		simu(t_nbr *nbr, t_pile tab, int *tmp_tab)
{
	t_nbr	sim;
	int		tmp;
	int		tmp2;

	sim = *nbr;
	sim.limit1 = 1;
	sim.limit2 = 1;
	tmp2 = ft_sort_big_sim(tab, sim);
	while (sim.limit1++ != 25)
	{
		sim.limit2 = 1;
		while (sim.limit2++ != 25)
		{
			ft_cpy_tab_int(tab.pile_a, tmp_tab, nbr->last_a);
			tmp = ft_sort_big_sim(tab, sim);
			if (tmp2 > tmp)
			{
				tmp2 = tmp;
				nbr->limit1 = sim.limit1;
				nbr->limit2 = sim.limit2;
			}
		}
	}
}

int				ft_simulate(t_pile tab, t_nbr *nbr)
{
	int *tmp_tab;

	if (!(tmp_tab = malloc(sizeof(int) * nbr->last_a + 1)))
		return (0);
	ft_cpy_tab_int(tmp_tab, tab.pile_a, nbr->last_a);
	simu(nbr, tab, tmp_tab);
	free (tmp_tab);
	return (1);
}
