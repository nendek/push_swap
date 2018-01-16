/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sim2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:50:11 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 14:50:13 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb_sim(int *pile_b, int i_b, int *nb_coup)
{
	ft_rrx(pile_b, i_b);
	*nb_coup += 1;
}

void	ft_pa_sim(t_pile pile, int *last_a, int *last_b, int *nb_coup)
{
	ft_push(pile.pile_a, pile.pile_b, last_a, last_b);
	*nb_coup += 1;
}

void	ft_pb_sim(t_pile pile, int *last_b, int *last_a, int *nb_coup)
{
	ft_push(pile.pile_b, pile.pile_a, last_b, last_a);
	*nb_coup += 1;
}

void	ft_rr_sim(t_pile pile, int last_a, int last_b, int *nb_coup)
{
	ft_rx(pile.pile_a, last_a);
	ft_rx(pile.pile_b, last_b);
	*nb_coup += 1;
}

void	ft_rrr_sim(t_pile pile, int last_a, int last_b, int *nb_coup)
{
	ft_rrx(pile.pile_a, last_a);
	ft_rrx(pile.pile_b, last_b);
	*nb_coup += 1;
}
