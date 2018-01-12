
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
	limit = 20;
	if (limit > last)
		limit = last;
	while (i != limit)
	{
		if (tab[i] < tab[j])
			j = i;
		i++;
	}
	ret = j;
	/*//le plus petit des x dernier
	i = last;
	j = last;
	while (i != last - limit && i != 0)
	{
		if (tab[i] < tab[j])
			j = i;
		i--;
	}
	// on renvoie celui avec le moin de coup
	if (ret == last - j)
	{
		if ( tab[j] < tab[ret])
			ret = j;
	}
	else if (ret > last - j)
		ret = j;*/
	return (ret);
}

int 	ft_find_pile_b(t_pile tab, t_nbr nbr, int end_b)
{
	int i;
	int j;

	i = 0;
	j = -1;
	//trouver si il y a un plus petit
	while (i != end_b + 1)
	{
		if (tab.pile_b[i] < tab.pile_a[nbr.last])
		{
			j = i;
			break;
		}
		i++;
	}
	if (j > -1)
	{//touver le plus grand des plus petit que tab_a[nbr.last]
		while (i != end_b + 1)
		{
			if (tab.pile_b[i] < tab.pile_a[nbr.last] && tab.pile_b[j] < tab.pile_b[i])
				j = i;
			i++;
		}	
	}
	else//si il n y a pas de plus petit trouver le plus petit des plus grands
	{
		i = 0;
		j = 0;
		while (i != end_b + 1)
		{
			if (tab.pile_b[j] > tab.pile_b[i])
				j = i;
			i++;
		}
	}
	return (j);
}

void	ft_place(t_pile tab, t_nbr nbr, int end_b, t_cmd_list **cmd)
{

}

int	ft_sort_big(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p)
{
	t_index i;
	
	i.b = p;
	i.b = -1;
	while (nbr.last != -1)
	{
		nbr.pivot = ft_search_small_for_big(tab.pile_a, nbr.last);
		nbr.pivot_b = ft_find_pile_b(tab, nbr, i.b);
		ft_place(tab, nbr, i.b, cmd);
	}

	return (0);
}
