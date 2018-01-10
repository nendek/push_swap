/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:42:56 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/10 15:39:30 by pnardozi         ###   ########.fr       */
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

int ft_sort_big(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p)
{
	t_index i;

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
		if (i.b < 1)
			ft_pb_list(tab, &i.b, &nbr.last, cmd);
		if (i.b == 1)
			if(tab.pile_b[0] < tab.pile_b[1])
				ft_sb_list(tab.pile_b, i.b);
		//trouver le plus grand des plus petit dans le pile b et le positionner au sommet de la pile b
		//ensuite placer b dans ll ordre avec des rb ou rrb
		//et ensuite pour finir pa
	}
}
