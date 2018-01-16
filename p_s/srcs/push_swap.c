/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:50:11 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 13:44:49 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static		void ft_cpy_tab_int(int *dest, int *srcs, int end)
{
	int i;

	i = 0;
	while (i <= end + 1)
	{
		dest[i] = srcs[i];
		i++;
	}
}

static		void ft_put_small_result(t_solution *sol, int end)
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

static char	**recovery(char **av, int ac, int *length, int *i)
{
	if (ac == 2)
	{
		*length = ft_countword(av[1], ' ');
		*i = 0;
		return (ft_strsplit(av[1], ' '));
	}
	else
	{
		*length = ac - 1;
		*i  = 1;
		return (av);
	}
}

int		ft_simulate(t_pile tab, t_nbr *nbr)
{
	int *tmp_tab;
	int tmp;
	int sol;
	int sol2;
	t_nbr sim;
	int tmp2;

	if (!(tmp_tab = malloc(sizeof(int) * nbr->last_a + 1)))
		return (0);
	ft_cpy_tab_int(tmp_tab, tab.pile_a, nbr->last_a);
	sim = *nbr;
	sim.limit1 = 5;
	sim.limit2 = 5;
	tmp2 = ft_sort_big_sim(tab, sim);
	while (sim.limit1 != 25)
	{
		while (sim.limit2 != 25)
		{
			ft_cpy_tab_int(tab.pile_a, tmp_tab, nbr->last_a);
			tmp = ft_sort_big_sim(tab, sim);
			if (tmp2 > tmp)
			{
				tmp2 = tmp;
				sol = sim.limit1;
				sol2 = sim.limit2;
			}
			sim.limit2++;
		}
			sim.limit1++;
			sim.limit2 = 0;
	}
	nbr->limit1 = sol;
	nbr->limit2 = sol2;
	return (1);
}

static void	ft_sort(t_pile tab, t_nbr nbr, int *tmp)
{
	t_solution 	sol;
	int		p;

	p = 0;
	sol.tab[p] = NULL;
	ft_cpy_tab_int(tmp, tab.pile_a, nbr.last_a);
	if (nbr.last_a <= 15)
	{
		while (p < NB_SOL)
		{
			ft_cpy_tab_int(tab.pile_a, tmp, nbr.last_a);
			sol.tab[p] = NULL;
			ft_sort_small(tab, nbr, &sol.tab[p], p);
			p++;
		}
		ft_put_small_result(&sol, NB_SOL);
	}
	else
	{
		ft_simulate(tab, &nbr);
		ft_cpy_tab_int(tab.pile_a, tmp, nbr.last_a);
		ft_sort_big(tab, nbr, &sol.tab[p]);
		ft_put_list(sol.tab[p]);
	}
}

int	main(int argc, char **argv)
{
	t_pile		tab;
	t_nbr		nbr;
	int		*tmp;
	char		**av;
	int		length;
	int		i;

	av = recovery(argv, argc, &length, &i);
	if (!(tmp = malloc(sizeof(int) * length)))
		return (0);
	if(!(tab.pile_a = malloc(sizeof(int) * length)))
		return (0);
	if (!(tab.pile_b = malloc(sizeof(int) * length)))
		return (0);
	if (ft_parsing_int(length , av, tab.pile_a, i) == 0 || length < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	nbr.last_a = length - 1;
	nbr.last_b = -1;
	ft_sort(tab, nbr, tmp);
	return (0);
}
