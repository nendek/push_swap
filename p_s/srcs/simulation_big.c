/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:55:35 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 14:57:44 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		ft_last_sort_b(t_pile tab, t_nbr *nbr, int meaning)
{
	if (nbr->pivot_b >= nbr->last_b / 2 && nbr->last_b >= 1 && meaning == 0)
		while (nbr->pivot_b++ != nbr->last_b)
			ft_rb_sim(tab.pile_b, nbr->last_b, &nbr->coups);
	else if (nbr->last_b >= 1 && meaning == 0)
		while (nbr->pivot_b != nbr->last_b)
		{
			ft_rrb_sim(tab.pile_b, nbr->last_b, &nbr->coups);
			nbr->pivot_b--;
			if (nbr->pivot_b < 0)
				nbr->pivot_b = nbr->last_b;
		}
	else if (nbr->pivot_b >= nbr->last_b / 2 &&\
			nbr->last_b >= 1 && meaning == 1)
		while (nbr->pivot_b != 0)
		{
			ft_rb_sim(tab.pile_b, nbr->last_b, &nbr->coups);
			nbr->pivot_b++;
			if (nbr->pivot_b > nbr->last_b)
				nbr->pivot_b = 0;
		}
	else if (nbr->last_b >= 1 && meaning == 1)
		while (nbr->pivot_b-- != 0)
			ft_rrb_sim(tab.pile_b, nbr->last_b, &nbr->coups);
}

static void		ft_sort_rr(t_pile tab, t_nbr *nbr, int meaning)
{
	while (nbr->pivot_a++ != nbr->last_a)
		if (nbr->pivot_b != nbr->last_b && nbr->pivot_b >= nbr->last_b / 2\
				&& nbr->last_b >= 1 && meaning == 0)
		{
			ft_rr_sim(tab, nbr->last_a, nbr->last_b, &nbr->coups);
			nbr->pivot_b++;
		}
		else if (nbr->pivot_b != 0 && nbr->pivot_b >= nbr->last_b / 2\
				&& nbr->last_b >= 1 && meaning == 1)
		{
			ft_rr_sim(tab, nbr->last_a, nbr->last_b, &nbr->coups);
			nbr->pivot_b++;
			if (nbr->pivot_b > nbr->last_b)
				nbr->pivot_b = 0;
		}
		else
			ft_ra_sim(tab.pile_a, nbr->last_a, &nbr->coups);
}

static void		ft_sort_rrr(t_pile tab, t_nbr *nbr, int meaning)
{
	while (nbr->pivot_a-- != nbr->last_a)
		if (nbr->pivot_b != nbr->last_b && nbr->pivot_b <= nbr->last_b / 2\
				&& nbr->last_b >= 1 && meaning == 0)
		{
			ft_rrr_sim(tab, nbr->last_a, nbr->last_b, &nbr->coups);
			nbr->pivot_b--;
			if (nbr->pivot_a < 0)
				nbr->pivot_a = nbr->last_a;
			if (nbr->pivot_b < 0)
				nbr->pivot_b = nbr->last_b;
		}
		else if (nbr->pivot_b != 0 && nbr->pivot_b <= nbr->last_b / 2\
				&& nbr->last_b >= 1 && meaning == 1)
		{
			ft_rrr_sim(tab, nbr->last_a, nbr->last_b, &nbr->coups);
			nbr->pivot_b--;
			if (nbr->pivot_a < 0)
				nbr->pivot_a = nbr->last_a;
		}
		else
		{
			ft_rra_sim(tab.pile_a, nbr->last_a, &nbr->coups);
			if (nbr->pivot_a < 0)
				nbr->pivot_a = nbr->last_a;
		}
}

static void		ft_place(t_pile tab, t_nbr *nbr, int meaning)
{
	if (nbr->pivot_a >= nbr->last_a / 2)
		ft_sort_rr(tab, nbr, meaning);
	else
		ft_sort_rrr(tab, nbr, meaning);
	ft_last_sort_b(tab, nbr, meaning);
}

int				ft_sort_big_sim(t_pile tab, t_nbr nbr)
{
	int meaning;

	nbr.coups = 0;
	meaning = 0;
	if (ft_is_sort(tab.pile_a, nbr.last_a) == 0)
		while (nbr.last_a != -1)
		{
			nbr.pivot_a = ft_search_small_for_big_sim(tab.pile_a,\
					nbr.last_a, nbr.limit1, nbr.limit2);
			nbr.pivot_b = ft_find_pile_b_pos_sim(tab, nbr, &meaning);
			ft_place(tab, &nbr, meaning);
			ft_pb_sim(tab, &nbr.last_b, &nbr.last_a, &nbr.coups);
			if (nbr.last_b == 1)
				if (tab.pile_b[0] > tab.pile_b[1])
					ft_sb_sim(tab.pile_b, nbr.last_b, &nbr.coups);
		}
	while (nbr.last_b != -1)
		ft_pa_sim(tab, &nbr.last_a, &nbr.last_b, &nbr.coups);
	return (nbr.coups);
}
