
#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

int	ft_sort(int *tab_a, int *tab_b, int ac)
{
	int current;
	int tmp;
	int pivot;
	int wall;

	pivot = tab_a[ac - 1];
	wall = 0;
	current = 0;
	if (ft_is_sort(tab_a, ac) != 1)
	{
		while (current < ac)
		{
			if (tab_a[current] <= pivot)
			{
				if (wall != current)
				{
					tmp = tab_a[current];
					tab_a[current] = tab_a[wall];
					tab_a[wall] = tmp;
				}
				wall++;
			}
			current++;
		}
		ft_sort(tab_a, tab_b, ac - wall + 1);
		ft_sort(tab_a + wall -1, tab_b, ac - wall + 1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;
	t_nbr	nbr;

	if(!(tab_a = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (!(tab_b = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (ft_parsing_int(argc - 1, argv, tab_a) == 0 || argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	nbr.first = tab_a[0];
	nbr.last = tab_a[argc - 1];
	nbr.pivot = nbr.last;
	ft_sort(tab_a, tab_b, argc);

	return (0);
}
