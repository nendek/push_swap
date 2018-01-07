/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 12:58:12 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/07 15:51:50 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		ft_parsing_cmd(char *s)
{
	if (ft_strcmp("sa", s) != 0 &&\
		ft_strcmp("sb", s) != 0 &&\
		ft_strcmp("ss", s) != 0 &&\
		ft_strcmp("ra", s) != 0 &&\
		ft_strcmp("rb", s) != 0 &&\
		ft_strcmp("rr", s) != 0 &&\
		ft_strcmp("rrr", s) != 0 &&\
		ft_strcmp("rra", s) != 0 &&\
		ft_strcmp("rrb", s) != 0 &&\
		ft_strcmp("pb", s) != 0 &&\
		ft_strcmp("pa", s) != 0)
		return (0);
	return (1);
}

static void		ft_select_cmd(int *pile_a, int *pile_b, char *cmd, t_index *i)
{
	if (ft_strcmp("sa", cmd) == 0)
		ft_sx(pile_a, i->a);
	if (ft_strcmp("sb", cmd) == 0)
		ft_sx(pile_b, i->b);
	if (ft_strcmp("ss", cmd) == 0)
		ft_ss(pile_a, pile_b, *i);
	if (ft_strcmp("ra", cmd) == 0)
		ft_rx(pile_a, i->a);
	if (ft_strcmp("rb", cmd) == 0)
		ft_rx(pile_b, i->b);
	if (ft_strcmp("rr", cmd) == 0)
		ft_rr(pile_a, pile_b, *i);
	if (ft_strcmp("rrr", cmd) == 0)
		ft_rrr(pile_a, pile_b, *i);
	if (ft_strcmp("rra", cmd) == 0)
		ft_rrx(pile_a, i->a);
	if (ft_strcmp("rrb", cmd) == 0)
		ft_rrx(pile_b, i->b);
	if (ft_strcmp("pb", cmd) == 0)
		ft_push(pile_b, pile_a, &i->b, &i->a);
	if (ft_strcmp("pa", cmd) == 0)
		ft_push(pile_a, pile_b, &i->a, &i->b);
}

int				ft_cmd(int *pile_a, int *pile_b, int end)
{
	char	*cmd;
	t_index	i;

	i.a = end;
	i.b = -1;
	while (get_next_line_multi(0, &cmd))
	{
		if (ft_parsing_cmd(cmd) == 0)
			return (0);
		ft_select_cmd(pile_a, pile_b, cmd, &i);
		ft_strdel(&cmd);
	}
	if (i.b == -1 && i.a > 0 && ft_is_sort(pile_a, i.a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (1);
}
