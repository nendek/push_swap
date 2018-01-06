
#include "push_swap.h"
#include "../../libft/libft/includes/libft.h"

int ft_part(int *tab_a, int *tab_b, t_nbr nbr)
{
	t_index i;
	int	j;

	j = nbr.first;
	i.b = -1;
	ft_printf("LALLAALLALALLA j = %d, pivot = %d, last = %d, i.b = %d, first = %d\n", j, nbr.pivot, nbr.last, i.b, nbr.first);
	///
	int x = 0;
	while (x <= nbr.last)
	{
		ft_printf("A L ENTRE DE LA FOCNTIONtab_a[%x] = %d\n", x, tab_a[x]);
		x++;
	}
	/// placement du pivot a la fin de la liste
	while (nbr.pivot != nbr.last)
	{
		ft_printf("DANS LA BOUCLE POUR PLACER EN FIN DE LISTE LE PIVOT j = %d, pivot = %d, last = %d, i.b = %d, first = %d\n", j, nbr.pivot, nbr.last, i.b, nbr.first);
		if (tab_a[nbr.last] < tab_a[nbr.pivot])
		{
			ft_printf("ICIICICICICI\n");
			ft_push(tab_b, tab_a, &i.b, &nbr.last);
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
	ft_printf("APRES LA BOUCLE POUR PLACER EN FIN DE LISTE LE PIVOT j = %d, pivot = %d, last = %d, i.b = %d, first = %d\n", j, nbr.pivot, nbr.last, i.b, nbr.first);
	//partitionnement
	//les plus grands que pivot dans la pile b
	//
	x = 0;
	while (x <= nbr.last)
	{
		ft_printf("APRES LA BOUCLE POUR PLCER A LA FIN DE LA LISTE LE PIVOT tab_a[%x] = %d\n", x, tab_a[x]);
		x++;
	}
	//
	ft_printf("ICICICICICIC j = %d, pivot = %d, last = %d, i.b = %d, first = %d\n", j, nbr.pivot, nbr.last, i.b, nbr.first);

	while (j != nbr.pivot)
	{
		while (tab_a[nbr.first] < tab_a[nbr.pivot])
		{
			ft_printf("ici1\n");
			ft_rx(tab_a, nbr.last);
			ft_push(tab_b, tab_a, &i.b, &nbr.last);
			nbr.pivot = nbr.last;
		}
		while (tab_a[j] > tab_a[nbr.pivot])
		{
			ft_printf("ici2\n");
			j++;
		}
		if (j != nbr.last)
		{
			while (j != nbr.last)
			{
				ft_printf("ici3\n");
				ft_rx(tab_a, nbr.last);
				nbr.pivot++;
				if (nbr.pivot > nbr.last)
					nbr.pivot = 0;
				j++;
				if (j > nbr.last)
					j = 0;
			}
			ft_printf("ici4\n");
			ft_push(tab_b, tab_a, &i.b, &nbr.last);
			while (nbr.pivot != nbr.last)
			{
				ft_printf("ici5\n");
				ft_rx(tab_a, nbr.last);
				nbr.pivot++;
				if (nbr.pivot > nbr.last)
					nbr.pivot = 0;
				j++;
				if (j > nbr.last)
					j = 0;
			}
		}
	}
	while (i.b != -1)
		ft_push(tab_a, tab_b, &nbr.last, &i.b);
	//
	x = 0;
	while (x <= nbr.last)
	{
		ft_printf("FIN DU PARTION :tab_a[%x] = %d\n", x, tab_a[x]);
		x++;
	}
	//
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
		ft_printf("BONJOUR MAC LOL\n");
		ft_sort(tab_a, tab_b, nbr, ac);
		nbr.first = nbr.pivot + 1;
		nbr.last = ac;	
		nbr.pivot = nbr.last;
		ft_printf ("SALUT MEC \n\n");
		ft_sort(tab_a, tab_b, nbr, ac);
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
