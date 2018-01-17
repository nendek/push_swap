/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:50:11 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/17 16:37:14 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			ft_cpy_tab_int(int *dest, int *srcs, int end)
{
	int i;

	i = 0;
	while (i <= end)
	{
		dest[i] = srcs[i];
		i++;
	}
}

static void		ft_put_small_result(t_solution *sol, int end)
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

static char		**recovery(char **av, int ac, int *length, int *i)
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
		*i = 1;
		return (av);
	}
}

static void		ft_sort(t_pile tab, t_nbr nbr, int *tmp)
{
	t_solution	sol;
	int			p;

	p = 0;
	ft_init(&sol);
	ft_cpy_tab_int(tmp, tab.pile_a, nbr.last_a);
	if (nbr.last_a <= 15)
	{
		while (p < NB_SOL)
		{
			ft_cpy_tab_int(tab.pile_a, tmp, nbr.last_a);
			ft_sort_small(tab, nbr, &sol.tab[p], p);
			p++;
		}
		ft_put_small_result(&sol, NB_SOL);
		ft_list_clear_all(&sol);
	}
	else
	{
		ft_simulate(tab, &nbr);
		ft_cpy_tab_int(tab.pile_a, tmp, nbr.last_a);
		ft_sort_big(tab, nbr, &sol.tab[p]);
		ft_put_list(sol.tab[p]);
		ft_list_clear(&sol.tab[p]);
	}
}

int				main(int argc, char **argv)
{
	t_pile	tab;
	t_nbr	nbr;
	int		*tmp;
	char	**av;
	int		length;

	av = recovery(argv, argc, &length, &nbr.limit1);
	if (!(tmp = malloc(sizeof(int) * length)))
		return (0);
	if (!(tab.pile_a = malloc(sizeof(int) * length)))
		return (0);
	if (!(tab.pile_b = malloc(sizeof(int) * length)))
		return (0);
	if (ft_parsing_int(length, av, tab.pile_a, nbr.limit1) == 0 || length < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	nbr.last_a = length - 1;
	nbr.last_b = -1;
	ft_sort(tab, nbr, tmp);
	free(tmp);
	free(tab.pile_a);
	free(tab.pile_b);
	return (0);
}
