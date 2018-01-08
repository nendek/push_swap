
#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

int ft_search_small_for_small(int *tab, int last)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i != last + 1)
	{
		if (tab[i] < tab[j])
			j = i;
		i++;
	}
	return (j);
}

int ft_sort_small(int *tab_a, int *tab_b, t_nbr nbr)
{
	t_index i;

	i.b = -1;
	while (!(ft_is_sort(tab_a, nbr.last)))
	{
		if (tab_a[nbr.last] > tab_a[nbr.last - 1])
		{
			ft_sx(tab_a, nbr.last);
			ft_printf("sa\n");
		}
		nbr.pivot = ft_search_small_for_small(tab_a, nbr.last);
		if (nbr.pivot >= nbr.last / 2)
			while (nbr.pivot != nbr.last)
			{
				if (tab_a[nbr.last] > tab_a[nbr.last - 1] && nbr.last != nbr.pivot && nbr.last - 1 != nbr.pivot)
				{
					ft_sx(tab_a, nbr.last);
					ft_printf("sa\n");
				}
				ft_rx(tab_a, nbr.last);
				ft_printf("ra\n");
				nbr.pivot++;
				
			}
		else
			while (nbr.pivot != nbr.last)
			{
				if (tab_a[nbr.last] > tab_a[nbr.last - 1] && nbr.last != nbr.pivot && nbr.last - 1 != nbr.pivot)
				{
					ft_sx(tab_a, nbr.last);
					ft_printf("sa\n");
				}
				ft_rrx(tab_a, nbr.last);
				ft_printf("rra\n");
				nbr.pivot--;
				if (nbr.pivot < 0)
					nbr.pivot = nbr.last;
			}
		if (!(ft_is_sort(tab_a, nbr.last)))
		{
			ft_push(tab_b, tab_a, &i.b, &nbr.last);
			ft_printf("pb\n");
		}
	}
	while (i.b != -1)
	{
		ft_push(tab_a, tab_b, &nbr.last, &i.b);
		ft_printf("pa\n");
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;
	t_nbr	nbr;
	int 	i = 0;

	if(!(tab_a = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (!(tab_b = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (ft_parsing_int(argc - 1, argv, tab_a) == 0 || argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
/*		while (i <= argc - 2)
		{
		ft_printf("debut : tab_a[%i] = %d\n", i, tab_a[i]);
		i++;
		}
*/	nbr.first = 0;
	nbr.last = argc - 2;
	nbr.pivot = nbr.last;
	ft_sort_small(tab_a, tab_b, nbr);
	i = 0;
/*	while (i <= argc - 2)
	{
		ft_printf("fini : tab_a[%i] = %d\n", i, tab_a[i]);
		i++;
	}
	if (ft_is_sort(tab_a, argc - 2) == 1)
		ft_printf("OK\n");
*/
	return (0);
}
