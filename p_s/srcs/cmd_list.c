/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 12:52:08 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/10 13:41:29 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_list(int *pile_a, int i_a, t_cmd_list **list)
{
	ft_sx(pile_a, i_a);
	ft_pushback_cmd(list, "sa");
}

void	ft_sb_list(int *pile_b, int i_b, t_cmd_list **list)
{
	ft_sx(pile_b, i_b);
	ft_pushback_cmd(list, "sb");
}

void	ft_ra_list(int *pile_a, int i_a, t_cmd_list **list)
{
	ft_rx(pile_a, i_a);
	ft_pushback_cmd(list, "ra");
}

void	ft_rb_list(int *pile_b, int i_b, t_cmd_list **list)
{
	ft_rx(pile_b, i_b);
	ft_pushback_cmd(list, "rb");
}

void	ft_rra_list(int *pile_a, int i_a, t_cmd_list **list)
{
	ft_rrx(pile_a, i_a);
	ft_pushback_cmd(list, "rra");
}
