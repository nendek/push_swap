
#include "checker.h"

void	ft_sx(int *pile_x, int i_x)
{
	if (i_x > 0)
		ft_swap(&pile_x[i_x], &pile_x[i_x - 1]);
}

void	ft_ss(int *pile_a, int *pile_b, t_index i)
{
	ft_sx(pile_a, i.a);
	ft_sx(pile_b, i.b);
}

void	ft_rx(int *pile_x, int i_x)
{
	int cursor;

	cursor = i_x;
	if (cursor >= 1)
		while (cursor != 0)
		{
			ft_swap(&pile_x[cursor], &pile_x[cursor - 1]);
			cursor--;
		}
}

void	ft_rr(int *pile_a, int *pile_b, t_index i)
{
	ft_rx(pile_a, i.a);
	ft_rx(pile_b, i.b);
}
