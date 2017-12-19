
#include "checker.h"

void	ft_rrx(int *pile_x, int i_x)
{
	int cursor;

	cursor = 0;
	if (i_x >= 1)
		while (cursor !=  i_x)
		{
			ft_swap(&pile_x[cursor], &pile_x[cursor + 1]);
			cursor++;
		}
}

void	ft_rrr(int *pile_a, int *pile_b, t_index i)
{
	ft_rrx(pile_a, i.a);
	ft_rrx(pile_b, i.b);
}
