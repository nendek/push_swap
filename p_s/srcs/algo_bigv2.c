/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_bigv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 13:37:31 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/13 22:21:06 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int ft_search_small_for_big(int *tab, int last)
{
	int i;
	int j;
	int ret;
	int limit = 0;

	limit = 18;
	i = 0;	
	j = 0;
	if (limit > last)
		limit = last + 1;
	while (i != limit)
	{
		if (tab[i] < tab[j])
			j = i;
		i++;
	}
	ret = j;
	i = last;
	j = last;
	while (i != last - limit && i != 0)
	{
		if (tab[i] < tab[j])
			j = i;
		i--;
	}
	if (tab[ret] > tab[j])
		ret = j;	
	return (ret);
}

static int 	ft_find_pile_b_pos(t_pile tab, t_nbr nbr, int *meaning)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (i != nbr.last_b + 1)
	{
		if (tab.pile_b[i] < tab.pile_a[nbr.pivot_a])
		{
			j = i;
			break;
		}
		i++;
	}
	if (j > -1)
	{
		while (i != nbr.last_b + 1)
		{
			if (tab.pile_b[i] < tab.pile_a[nbr.pivot_a] && tab.pile_b[j] < tab.pile_b[i])
				j = i;
			i++;
		}	
	}
	else
	{
		i = 0;
		j = 0;
		*meaning = 1;
		while (i != nbr.last_b + 1)
		{
			if (tab.pile_b[j] > tab.pile_b[i])
				j = i;
			i++;
		}
	}
	return (j);
}

static void	ft_last_sort_b(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int meaning)
{
	if (nbr.pivot_b >= nbr.last_b / 2 && nbr.last_b >= 1 && meaning == 0)
		while (nbr.pivot_b++ != nbr.last_b)
			ft_rb_list(tab.pile_b, nbr.last_b, cmd);
	else if (nbr.last_b >= 1 && meaning == 0)
		while (nbr.pivot_b != nbr.last_b)
		{
			ft_rrb_list(tab.pile_b, nbr.last_b, cmd);
			nbr.pivot_b--;
			if (nbr.pivot_b < 0)
				nbr.pivot_b = nbr.last_b;
		}
	else if (nbr.pivot_b >= nbr.last_b / 2 && nbr.last_b >= 1 && meaning == 1)
		while (nbr.pivot_b != 0)
		{
			ft_rb_list(tab.pile_b, nbr.last_b, cmd);
			nbr.pivot_b++;
			if (nbr.pivot_b > nbr.last_b)
				nbr.pivot_b = 0;
		}
	else if (nbr.last_b >= 1 && meaning == 1)
		while (nbr.pivot_b-- != 0)
			ft_rrb_list(tab.pile_b, nbr.last_b, cmd);
}

static void	ft_sort_rr(t_pile tab, t_nbr *nbr, t_cmd_list **cmd, int meaning)
{
	while(nbr->pivot_a++ != nbr->last_a)
	{
		if (nbr->pivot_b != nbr->last_b && nbr->pivot_b >= nbr->last_b / 2 && nbr->last_b >= 1 && meaning == 0)
		{
			ft_rr_list(tab, nbr->last_a, nbr->last_b, cmd);
			nbr->pivot_b++;
		}
		else if (nbr->pivot_b != 0 && nbr->pivot_b >= nbr->last_b / 2 && nbr->last_b >= 1 && meaning == 1)
		{
			ft_rr_list(tab, nbr->last_a, nbr->last_b, cmd);
			nbr->pivot_b++;
			if (nbr->pivot_b > nbr->last_b)
				nbr->pivot_b = 0;
		}
		else
			ft_ra_list(tab.pile_a, nbr->last_a, cmd);
	}
}

static void	ft_sort_rrr(t_pile tab, t_nbr *nbr, t_cmd_list **cmd, int meaning)
{
	while (nbr->pivot_a-- != nbr->last_a)
	{
		if (nbr->pivot_b != nbr->last_b && nbr->pivot_b <= nbr->last_b / 2 && nbr->last_b >= 1 && meaning == 0)
		{
			ft_rrr_list(tab, nbr->last_a, nbr->last_b, cmd);
			nbr->pivot_b--;
			if (nbr->pivot_a < 0)
				nbr->pivot_a = nbr->last_a;
			if (nbr->pivot_b < 0)
				nbr->pivot_b = nbr->last_b;
		}
		else if (nbr->pivot_b != 0 && nbr->pivot_b <= nbr->last_b / 2 && nbr->last_b >= 1 && meaning == 1)
		{
			ft_rrr_list(tab, nbr->last_a, nbr->last_b, cmd);
			nbr->pivot_b--;
			if (nbr->pivot_a < 0)
				nbr->pivot_a = nbr->last_a;
		}
		else
		{
			ft_rra_list(tab.pile_a, nbr->last_a, cmd);
			if (nbr->pivot_a < 0)
				nbr->pivot_a = nbr->last_a;
		}
	}
}

static void	ft_place(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int meaning)
{
	if (nbr.pivot_a >= nbr.last_a / 2)
		ft_sort_rr(tab, &nbr, cmd, meaning);
	else
		ft_sort_rrr(tab, &nbr, cmd, meaning);
	ft_last_sort_b(tab, nbr, cmd, meaning);
}

int	ft_sort_big(t_pile tab, t_nbr nbr, t_cmd_list **cmd)
{
	int meaning;

	meaning = 0;
	if (ft_is_sort(tab.pile_a, nbr.last_a) == 0)
		while (nbr.last_a != -1)
		{
			nbr.pivot_a = ft_search_small_for_big(tab.pile_a, nbr.last_a);
			nbr.pivot_b = ft_find_pile_b_pos(tab, nbr, &meaning);
			ft_place(tab, nbr, cmd, meaning);
			ft_pb_list(tab, &nbr.last_b, &nbr.last_a, cmd);
			if (nbr.last_b == 1)
			{
				if(tab.pile_b[0] > tab.pile_b[1])
					ft_sb_list(tab.pile_b, nbr.last_b, cmd);
			}
		}
	while (nbr.last_b != -1)
		ft_pa_list(tab, &nbr.last_a, &nbr.last_b, cmd);
	return (0);
}
