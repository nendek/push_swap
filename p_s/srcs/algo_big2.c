
#include "push_swap.h"

static int	ft_is_small(int *tab, int last)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (i != last)
	{
		if (tab[i] < tab[tmp])
			tmp = i;
		i++;
	}
	return (tmp);
}

int		ft_search_small_for_big(int *tab, int last)
{
	int i;
	int j;
	int ret;
	int limit = 0;

	limit = 12;
	if (limit > last)
		limit = last + 1;
	ret = ft_is_small(tab, limit);
	i = last;
	j = last;
	if (limit > last)
		limit = last + 1;
	while (i != last - limit && i != 0)
	{
		if (tab[i] < tab[j])
			j = i;
		i--;
	}
	if (tab[ret] > tab[j])
		ret = j;	
	return (ret);
}

static	void	ft_find_pile_b_pos2(t_pile tab, t_nbr nbr, int *i, int *j)
{
	if (*j > -1)
	{
		while (*i != nbr.last_b + 1)
		{
			if (tab.pile_b[*i] < tab.pile_a[nbr.pivot_a] && tab.pile_b[*j] < tab.pile_b[*i])
				*j = *i;
			*i += 1;
		}	
	}
	else
	{
		*i = 0;
		*j = 0;
		while (*i != nbr.last_b + 1)
		{
			if (tab.pile_b[*j] > tab.pile_b[*i])
				*j = *i;
			*i += 1;
		}
	}
}

int 	ft_find_pile_b_pos(t_pile tab, t_nbr nbr, int *meaning)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (i != nbr.last_b + 1)
	{
		if (tab.pile_b[i] < tab.pile_a[nbr.pivot_a])
		{
			j = i;
			break;
		}
		i++;
	}
	if (j > -1)
		*meaning = 0;
	else
		*meaning = 1;
	ft_find_pile_b_pos2(tab, nbr, &i, &j);
	return (j);
}
