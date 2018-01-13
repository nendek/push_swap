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
#include "../../libft/libft/includes/libft.h"

int ft_search_small_for_big(int *tab, int last)
{
	int i;
	int j;
	int ret;
	int limit = 0;
	
	if (last <= 500)
		limit = 20;
/*	if (last <= 450)
		limit = 22;
	if (last <= 400)
		limit = 22;
	if (last <= 350)
		limit = 23;
	if (last <= 300)
		limit = 21;
	if (last <= 250)
		limit = 28;
	if (last <= 200)
		limit = 14;
	if (last <= 150)
		limit = 26;
	if (last <= 100)
		limit = 12;
	if (last <= 50)
		limit = 11;
*/	//if (last <= 400)
	//	limit = 22;
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
	return (ret);
}

int 	ft_find_pile_b_pos(t_pile tab, t_nbr nbr, int end_b, int *meaning)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (i != end_b + 1)
	{
		if (tab.pile_b[i] < tab.pile_a[nbr.pivot])
		{
			j = i;
			break;
		}
		i++;
	}
	if (j > -1)
	{
		*meaning = 0;
		while (i != end_b + 1)
		{
			if (tab.pile_b[i] < tab.pile_a[nbr.pivot] && tab.pile_b[j] < tab.pile_b[i])
				j = i;
			i++;
		}	
	}
	else
	{
		i = 0;
		j = 0;
		*meaning = 1;
		while (i != end_b + 1)
		{
			if (tab.pile_b[j] > tab.pile_b[i])
				j = i;
			i++;
		}
	}
	return (j);
}

void	ft_place(t_pile tab, t_nbr nbr, int end_b, t_cmd_list **cmd, int meaning)
{
	if (nbr.pivot >= nbr.last / 2)
	{
		while(nbr.pivot != nbr.last)
		{
			if (nbr.pivot_b != end_b && nbr.pivot_b >= end_b / 2 && end_b >= 1 && meaning == 0)
			{
				ft_rr_list(tab, nbr.last, end_b, cmd);
				nbr.pivot++;
				nbr.pivot_b++;
			}
			else if (nbr.pivot_b != 0 && nbr.pivot_b >= end_b / 2 && end_b >= 1 && meaning == 1)
			{
				ft_rr_list(tab, nbr.last, end_b, cmd);
				nbr.pivot++;
				nbr.pivot_b++;
				if (nbr.pivot_b > end_b)
					nbr.pivot_b = 0;
			}
			else
			{
				ft_ra_list(tab.pile_a, nbr.last, cmd);
				nbr.pivot++;
			}
		}
	}
	else
		while (nbr.pivot != nbr.last)
		{
			if (nbr.pivot_b != end_b && nbr.pivot_b <= end_b / 2 && end_b >= 1 && meaning == 0)
			{
				ft_rrr_list(tab, nbr.last, end_b, cmd);
				nbr.pivot--;
				nbr.pivot_b--;
				if (nbr.pivot < 0)
					nbr.pivot = nbr.last;
				if (nbr.pivot_b < 0)
					nbr.pivot_b = end_b;
			}
			else if (nbr.pivot_b != 0 && nbr.pivot_b <= end_b / 2 && end_b >= 1 && meaning == 1)
			{
				ft_rrr_list(tab, nbr.last, end_b, cmd);
				nbr.pivot--;
				nbr.pivot_b--;
				if (nbr.pivot < 0)
					nbr.pivot = nbr.last;
			}
			else
			{
				ft_rra_list(tab.pile_a, nbr.last, cmd);
				nbr.pivot--;
				if (nbr.pivot < 0)
					nbr.pivot = nbr.last;
			}
		}	
	if (nbr.pivot_b >= end_b / 2 && end_b >= 1 && meaning == 0)
		while (nbr.pivot_b != end_b)
		{
			ft_rb_list(tab.pile_b, end_b, cmd);
			nbr.pivot_b++;
		}
	else if (end_b >= 1 && meaning == 0)
		while (nbr.pivot_b != end_b)
		{
			ft_rrb_list(tab.pile_b, end_b, cmd);
			nbr.pivot_b--;
			if (nbr.pivot_b < 0)
				nbr.pivot_b = end_b;
		}
	else if (nbr.pivot_b >= end_b / 2 && end_b >= 1 && meaning == 1)
		while (nbr.pivot_b != 0)
		{
			ft_rb_list(tab.pile_b, end_b, cmd);
			nbr.pivot_b++;
			if (nbr.pivot_b > end_b)
				nbr.pivot_b = 0;
		}
	else if (end_b >= 1 && meaning == 1)
		while (nbr.pivot_b != 0)
		{
			ft_rrb_list(tab.pile_b, end_b, cmd);
			nbr.pivot_b--;
		}
}

int	ft_sort_big(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p)
{
	t_index i;
	int meaning;
	meaning = 0;
	i.b = p;
	i.b = -1;
	if (ft_is_sort(tab.pile_a, nbr.last) == 0)
		while (nbr.last != -1)
		{
			nbr.pivot = ft_search_small_for_big(tab.pile_a, nbr.last);
			nbr.pivot_b = ft_find_pile_b_pos(tab, nbr, i.b, &meaning);
			ft_place(tab, nbr, i.b, cmd, meaning);
			ft_pb_list(tab, &i.b, &nbr.last, cmd);
			if (i.b == 1)
			{
				if(tab.pile_b[0] > tab.pile_b[1])
					ft_sb_list(tab.pile_b, i.b, cmd);
			}
		}
	while (i.b != -1)
		ft_pa_list(tab, &nbr.last, &i.b, cmd);
	return (0);
}
