
#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

int ft_part(int *tab_a, int *tab_b, t_nbr nbr)
{
	t_index i;
	int	j;

	j = nbr.first;
	i.b = -1;
	// placement du pivot a la fin de la liste
	while (nbr.pivot != nbr.last)
	{
		if (tab_a[nbr.last] > tab_a[nbr.pivot])
		{
			ft_push(tab_b, tab_a, &nbr.last, &i.b);
			nbr.last = i.a;
		}
		else if (nbr.last - nbr.pivot == 1)
		{
			ft_sx(tab_a, nbr.last);
			nbr.pivot++;
		}
		else
		{
			ft_rx(tab_a, nbr.last);
			nbr.pivot++;
		}
	}
	//partitionnement
	//les plus grands que pivot dans la pile b
	while (j != nbr.pivot - 1)
	{
		while (tab_a[nbr.first] > tab_a[nbr.pivot])
		{
			ft_rrx(tab_a, nbr.last);
			ft_push(tab_b, tab_a, &nbr.last, &i.b);
			nbr.pivot = nbr.last;
		}
		while (tab_a[j] < tab_a[nbr.pivot])
			j++;
		if (j != nbr.last)
		{
			while (j != nbr.last)
			{
				ft_rx(tab_a, nbr.last);
				nbr.pivot++;
				if (nbr.pivot > nbr.last)
					nbr.pivot = 0;
				j++;
				if (j > nbr.last)
					j = 0;
			}
			ft_push(tab_b, tab_a, &nbr.last, &i.b);
			while (nbr.pivot != nbr.last)
			{
				ft_rx(tab_a, nbr.last);
				nbr.pivot++;
				if (nbr.pivot > nbr.last)
					nbr.pivot = 0;
				j++;
				if (j > nbr.last)
					j = 0;
			}
		}
		ft_printf("ici\n");
	}
	return (0);
}

int ft_sort(int *tab_a, int *tab_b, t_nbr nbr)
{
	if (nbr.first < nbr.last)
	{
		ft_part(tab_a, tab_b, nbr);

	}
	return (0);
}

/*void ft_sort(int *tab_a, int *tab_b, int ac)
  {
  t_nbr nbr;

  nbr.pivot = tab_a[ac - 1];
  nbr.wall = 0;
  nbr.current = 0;
  if (ft_is_sort(tab_a, ac - 1) != 1)
  {
  while (nbr.current < ac)
  {
  if (tab_a[nbr.current] <= nbr.pivot)
  {
  if (nbr.wall != nbr.current)
  {
  nbr.tmp = tab_a[nbr.current];
  tab_a[nbr.current] = tab_a[nbr.wall];
  tab_a[nbr.wall] = nbr.tmp;
  }
  nbr.wall++;
  }
  nbr.current++;
  }
  ft_sort(tab_a, tab_b, nbr.wall - 1);
  ft_sort(tab_a + nbr.wall - 1, tab_b, ac - nbr.wall + 1);
  }
  }*/

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
	//ft_sort(tab_a, tab_b, argc);
	nbr.first = 0;
	nbr.last = argc - 1;
	nbr.pivot = nbr.last;
	ft_sort(tab_a, tab_b, nbr);
	while (i <= argc - 1)
	{
		ft_printf("tab_a[%i] = %d\n", i, tab_a[i]);
		i++;
	}

	return (0);
}
