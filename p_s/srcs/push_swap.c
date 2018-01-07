
#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

int ft_part(int *tab_a, int *tab_b, t_nbr nbr)
{
	t_index i;
	int	j;

	j = nbr.first;
	i.b = -1;
	while (nbr.pivot != nbr.last)
	{
		if (tab_a[nbr.last] < tab_a[nbr.pivot])
		{
			ft_push(tab_b, tab_a, &i.b, &nbr.last);
			ft_printf("pb\n");
		}
		else if (nbr.last - nbr.pivot == 1)
		{
			ft_sx(tab_a, nbr.last);
			ft_printf("sa\n");
			nbr.pivot++;
		}
		else
		{
			ft_rx(tab_a, nbr.last);
			ft_printf("ra\n");
			nbr.pivot++;
		}
	}
	while (j != nbr.pivot)
	{
		while (tab_a[nbr.first] < tab_a[nbr.pivot])
		{
			ft_rx(tab_a, nbr.last);
			ft_printf("ra\n");
			ft_push(tab_b, tab_a, &i.b, &nbr.last);
			ft_printf("pb\n");
			nbr.pivot = nbr.last;
		}
		while (tab_a[j] > tab_a[nbr.pivot])
			j++;
		if (j != nbr.last)
		{
			if (j > nbr.last / 2)
			{
				while (j != nbr.last)
				{
					ft_rx(tab_a, nbr.last);
					ft_printf("ra\n");
					nbr.pivot++;
					if (nbr.pivot > nbr.last)
						nbr.pivot = 0;
					j++;
					if (j > nbr.last)
						j = 0;
				}
			}
			else
				while (j != nbr.last)
				{
					ft_rrx(tab_a, nbr.last);
					ft_printf("rra\n");
					nbr.pivot--;
					if (nbr.pivot < nbr.first)
						nbr.pivot = nbr.last;
					j--;
					if (j < nbr.first)
						j = nbr.last;
				}
			ft_push(tab_b, tab_a, &i.b, &nbr.last);
			ft_printf("pb\n");
			if (nbr.pivot > nbr.last / 2)
			{
				while (nbr.pivot != nbr.last)
				{
					ft_rx(tab_a, nbr.last);
					ft_printf("ra\n");
					nbr.pivot++;
					if (nbr.pivot > nbr.last)
						nbr.pivot = 0;
					j++;
					if (j > nbr.last)
						j = 0;
				}
			}
			else
				while (nbr.pivot != nbr.last)
				{
					ft_rrx(tab_a, nbr.last);
					ft_printf("rra\n");
					nbr.pivot--;
					if (nbr.pivot < nbr.first)
						nbr.pivot = nbr.last;
					j--;
					if (j < nbr.first)
						j = nbr.last;
				}
			int k = 1;
			while (i.b > 0 && k == 1)
			{
				k = 0;
				if (tab_b[i.b] < tab_b[i.b - 1] && tab_b[i.b] > tab_b[0])
				{
					k = 1;
					ft_sx(tab_b, i.b);
					ft_printf("sb ici1\n");
				}
				if (tab_b[i.b] < tab_b[0])
				{
					k = 1;
					ft_rx(tab_b, i.b);
					ft_printf("rb ici2\n");
				}
				if (tab_b[0] > tab_b[1])
				{
					k = 1;
					ft_rrx(tab_b, i.b);
					ft_printf ("rbb ici3\n");
				}	
			}
		}
	}
	while (i.b != -1)
	{
		ft_push(tab_a, tab_b, &nbr.last, &i.b);
		ft_printf("pa\n");
	}
	return (0);
}

int ft_sort(int *tab_a, int *tab_b, t_nbr nbr, int ac)
{
	if (nbr.first < nbr.last && !(ft_is_sort(tab_a, ac)))
	{
		ft_part(tab_a, tab_b, nbr);
		nbr.first = 0;
		nbr.last = nbr.pivot - 1;
		nbr.pivot = nbr.last;
		if (!(ft_is_sort(tab_a, ac)))
			ft_sort(tab_a, tab_b, nbr, ac);
		nbr.first = nbr.pivot + 1;
		nbr.last = ac;	
		nbr.pivot = nbr.last;
		if (!(ft_is_sort(tab_a, ac)))
			ft_sort(tab_a, tab_b, nbr, ac);
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
	nbr.first = 0;
	nbr.last = argc - 2;
	nbr.pivot = nbr.last;
	ft_sort(tab_a, tab_b, nbr, argc - 2);
	while (i <= argc - 2)
	{
		ft_printf("fini : tab_a[%i] = %d\n", i, tab_a[i]);
		i++;
	}

	return (0);
}
