
#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

void ft_sort(int *tab_a, int *tab_b, int ac)
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
		ft_printf("tab_a + nbr.wall - 1 = %d, tab_a = %d, nbr.wall = %d\n", tab_a + nbr.wall - 1, tab_a, nbr.wall);
		ft_sort(tab_a, tab_b, nbr.wall - 1);
		ft_sort(tab_a + nbr.wall - 1, tab_b, ac - nbr.wall + 1);
	}
}

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;
	int i = 0;

	if(!(tab_a = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (!(tab_b = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (ft_parsing_int(argc - 1, argv, tab_a) == 0 || argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_sort(tab_a, tab_b, argc);
	while (i <= argc - 1)
	{
		ft_printf("tab_a[%i] = %d\n", i, tab_a[i]);
		i++;
	}

	return (0);
}
