/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:15:32 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/19 14:15:36 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sx(int *pile_x, int i_x)
{
	if (i_x > 0)
		ft_swap(&pile_x[i_x], &pile_x[i_x - 1]);
}

void	ft_rx(int *pile_x, int i_x)
{
	int cursor;

	cursor = i_x;
	if (cursor >= 1)
		while (cursor != 0)
		{
			ft_swap(&pile_x[cursor], &pile_x[cursor - 1]);
			cursor--;
		}
}

void	ft_rrx(int *pile_x, int i_x)
{
	int cursor;

	cursor = 0;
	if (i_x >= 1)
		while (cursor != i_x)
		{
			ft_swap(&pile_x[cursor], &pile_x[cursor + 1]);
			cursor++;
		}
}
