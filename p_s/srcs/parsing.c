/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:53:22 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/23 10:36:08 by pnardozi         ###   ########.fr       */
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

static int		ft_check(char **av, int *i, int *j)
{
	*j = 0;
	(av[*i][*j] == '-') ? *j += 1 : 0;
	while (av[*i][*j] != '\0')
	{
		if (ft_isdigit(av[*i][*j]) == 0 || *j >= 18)
			return (0);
		*j += 1;
	}
	return (1);
}

static void		ft_error(long long *tmp)
{
	free(tmp);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

int				ft_parsing_int(int ac, char **av, int *tab, int i)
{
	long long		*tmp;
	int				j;
	int				tmp2;
	int				k;

	k = 0;
	tmp2 = i;
	if (!(tmp = malloc(sizeof(tmp) * ac)))
		exit(EXIT_FAILURE);
	while (av[i])
	{
		if (ft_check(av, &i, &j) == 0)
			ft_error(tmp);
		tmp[k] = ft_long_atoi(av[i]);
		if (tmp[k] > 2147483647 || tmp[k] < -2147483648)
			ft_error(tmp);
		tab[--ac] = (int)tmp[k++];
		if (ft_double(tab, i, ac) == 0)
			ft_error(tmp);
		i++;
	}
	(tmp2 == 0) ? ft_del_av(av) : 0;
	free(tmp);
	return (1);
}
