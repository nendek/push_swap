/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:49:33 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 18:22:45 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb_list(int *pile_b, int i_b, t_cmd_list **list)
{
	ft_rrx(pile_b, i_b);
	ft_pushback_cmd(list, "rrb");
}

void	ft_pa_list(t_pile pile, int *last_a, int *last_b, t_cmd_list **list)
{
	ft_push(pile.pile_a, pile.pile_b, last_a, last_b);
	ft_pushback_cmd(list, "pa");
}

void	ft_pb_list(t_pile pile, int *last_b, int *last_a, t_cmd_list **list)
{
	ft_push(pile.pile_b, pile.pile_a, last_b, last_a);
	ft_pushback_cmd(list, "pb");
}

void	ft_rr_list(t_pile pile, int last_a, int last_b, t_cmd_list **list)
{
	ft_rx(pile.pile_a, last_a);
	ft_rx(pile.pile_b, last_b);
	ft_pushback_cmd(list, "rr");
}

void	ft_rrr_list(t_pile pile, int last_a, int last_b, t_cmd_list **list)
{
	ft_rrx(pile.pile_a, last_a);
	ft_rrx(pile.pile_b, last_b);
	ft_pushback_cmd(list, "rrr");
}
