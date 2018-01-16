/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:52:08 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/10 13:41:29 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_sim(int *pile_a, int i_a, int *nb_coup)
{
	ft_sx(pile_a, i_a);
	*nb_coup += 1;
}

void	ft_sb_sim(int *pile_b, int i_b, int *nb_coup)
{
	ft_sx(pile_b, i_b);
	*nb_coup += 1;
}

void	ft_ra_sim(int *pile_a, int i_a, int *nb_coup)
{
	ft_rx(pile_a, i_a);
	*nb_coup += 1;
}

void	ft_rb_sim(int *pile_b, int i_b, int *nb_coup)
{
	ft_rx(pile_b, i_b);
	*nb_coup += 1;
}

void	ft_rra_sim(int *pile_a, int i_a, int *nb_coup)
{
	ft_rrx(pile_a, i_a);
	*nb_coup += 1;
}
