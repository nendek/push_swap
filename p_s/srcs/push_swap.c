/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:50:11 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/11 14:28:14 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

void ft_cpy_tab_int(int *dest, int *srcs, int end)
{
	int i;
	
	i = 0;
	while (i <= end)
	{
		dest[i] = srcs[i];
		i++;
	}
}

void ft_put_small_result(t_solution *sol, int end)
{
	int tmp;
	int res;
	int i;

	i = 0;
	tmp = ft_lentgh_list(sol->tab[i]);
	res = i;
	i++;
	while (i < end)
	{
		if (ft_lentgh_list(sol->tab[i]) < tmp)
		{
			res = i;
			tmp = ft_lentgh_list(sol->tab[i]);
		}
		i++;
	}
	ft_put_list(sol->tab[res]);
}

int	main(int argc, char **argv)
{
	t_pile		tab;
	t_nbr		nbr;
	t_solution	sol;
	int			p;
	int			*tmp;

	p = 0;
	if (!(tmp = malloc(sizeof(int) * argc - 1)))
		return (0);
	if(!(tab.pile_a = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (!(tab.pile_b = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (ft_parsing_int(argc - 1, argv, tab.pile_a) == 0 || argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_cpy_tab_int(tmp, tab.pile_a, argc - 1);
	nbr.first = 0;
	nbr.last = argc - 2;
	/*while (p < NB_SOL)
	{
		ft_cpy_tab_int(tab.pile_a, tmp, argc - 1);
		sol.tab[p] = NULL;
		ft_sort_small(tab, nbr, &sol.tab[p], p);
		p++;
	}
	ft_put_small_result(&sol, NB_SOL);
	*/
	sol.tab[0] = NULL;
	ft_sort_big(tab, nbr, &sol.tab[0], p);
	int i = 0;
	//while (i < p)
	//{
		ft_put_list(sol.tab[i]);
	//	ft_printf("\n");
	//	i++;
//	}*/
	return (0);
}
