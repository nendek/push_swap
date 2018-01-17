/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:53:22 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/17 15:05:47 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		ft_double(int *tab, int end, int ac)
{
	int	i;

	i = ac;
	i++;
	while (i < (end + ac))
	{
		if (tab[i] == tab[ac])
			return (0);
		i++;
	}
	return (1);
}

static void		ft_del_av(char **av)
{
	int i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
	free(av);
}

int				ft_parsing_int(int ac, char **av, int *tab, int i)
{
	long long	*tmp;
	int			j;
	int			tmp2;

	tmp2 = i;
	if (!(tmp = malloc(sizeof(tmp) * ac)))
		return (0);
	while (av[i])
	{
		j = 0;
		(av[i][j] == '-') ? j++ : 0;
		while (av[i][j] != '\0')
			if (ft_isdigit(av[i][j++]) == 0)
				return (0);
		tmp[i] = ft_long_atoi(av[i]);
		if (tmp[i] > 2147483647 || tmp[i] < -2147483648)
			return (0);
		tab[--ac] = (int)tmp[i];
		if (ft_double(tab, i, ac) == 0)
			return (0);
		i++;
	}
	(tmp2 == 0) ? ft_del_av(av) : 0;
	free(tmp);
	return (1);
}
