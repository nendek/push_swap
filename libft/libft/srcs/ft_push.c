
#include "libft.h"

void	ft_push(int *pile_dst, int *pile_src, int *i_dst, int *i_src)
{
	if (*i_src >= 0)
	{
		*i_dst += 1;
		pile_dst[*i_dst] = pile_src[*i_src];
		*i_src -= 1;
	}
}
