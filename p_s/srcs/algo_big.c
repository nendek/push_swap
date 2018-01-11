/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:42:56 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/11 14:31:30 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

int ft_search_small_for_big(int *tab, int last)
{
	int i;
	int j;
	int ret;
	int limit;

	//le plus petit des x premier
	i = 0;
	j = 0;
	limit = 10;
	if (limit > last)
		limit = last;
	while (i != limit + 1)
	{
		if (tab[i] < tab[j])
			j = i;
		i++;
	}
	ret = j;
	//le plus petit des x dernier
	i = last;
	j = last;
	while (i != last - limit && i != 0)
	{
		if (tab[i] < tab[j])
			j = i;
		i--;
	}
	// on renvoie celui avec le moin de coup
	if (ret > j - last)
		ret = j;
	return (ret);
}

void ft_find_pile_b(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int end_b)
{
	int i;
	int ret;
	int j;

	i = 0;
	j = 0;
	//touver le plus grand des plus petit que tab_a[nbr.last]
	ret = tab.pile_a[0];
	while (i != end_b + 1)
	{
		if (tab.pile_b[i] < tab.pile_a[nbr.last] && tab.pile_b[i] > ret)
			j = i;
		i++;
	}
	if (j >= end_b / 2)
		while (j != end_b)
		{
			ft_rb_list(tab.pile_b, end_b, cmd);
			j++;
		}
	else
		while (j != end_b)
		{
			ft_rrb_list(tab.pile_b, end_b, cmd);
			j++;
			if (j < 0)
				j = end_b;
		}
}

void	ft_place_b(t_pile tab, t_cmd_list **cmd, int end_b, int small)
{
	if (small > end_b / 2)
		while (small != 0)
		{
			ft_rb_list(tab.pile_b, end_b, cmd);
			small++;
			if (small > end_b)
				small = 0;
		}
	else
		while (small != 0)
		{
			ft_rrb_list(tab.pile_b, end_b, cmd);
			small--;
		}
}


int ft_sort_big(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p)
{
	t_index i;
	int		small_b;

	i.b = p;
	i.b = -1;
	while (!ft_is_sort(tab.pile_a, nbr.last))
	{
		nbr.pivot = ft_search_small_for_big(tab.pile_a, nbr.last);
		if (nbr.pivot >= nbr.last / 2)
			while (nbr.pivot != nbr.last)
			{
				ft_ra_list(tab.pile_a, nbr.last, cmd);
				nbr.pivot++;
			}
		else
			while (nbr.pivot != nbr.last)
			{
				ft_rra_list(tab.pile_a, nbr.last, cmd);
				nbr.pivot--;
				if (nbr.pivot < 0)
					nbr.pivot = nbr.last;
			}
		if (i.b == 1)
			if(tab.pile_b[0] < tab.pile_b[1])
				ft_sb_list(tab.pile_b, i.b, cmd);
		//trouver le plus grand des plus petit dans le pile b et le positionner au sommet de la pile b
		if (i.b > 1)
			ft_find_pile_b(tab, nbr, cmd, i.b);
		ft_pb_list(tab, &i.b, &nbr.last, cmd);

	}
	//ensuite placer b dans ll ordre avec des rb ou rrb
	small_b = ft_search_small_for_big(tab.pile_b, i.b);
	ft_place_b(tab, cmd, i.b, small_b);
	//et ensuite pour finir pa
	while (i.b != -1)
		ft_pa_list(tab, &nbr.last, &i.b, cmd);

	int x = 0;
	while (x != nbr.last + 1)
	{
		ft_printf("tab_a[%d] = %d\n", x, tab.pile_a[x]);
		x++;
	}
	return (0);
}
