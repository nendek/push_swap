/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:09:46 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/19 14:22:41 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

static int		ft_parsing_int(int ac, char **av, int *tab)
{
	long long		*tmp;
	int				i;
	int				j;

	i = 1;
	if (!(tmp = malloc(sizeof(*tmp) * ac)))
		return (0);
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-')
			j++;
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
	free(tmp);
	return (1);
}

int				main(int argc, char **argv)
{
	int	*tab_a;
	int	*tab_b;

	if (!(tab_a = malloc(sizeof(int) * (argc - 1) * 2)))
		return (0);
	if (!(tab_b = malloc(sizeof(int) * (argc - 1) * 2)))
		return (0);
	if (ft_parsing_int(argc - 1, argv, tab_a) == 0 || argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_cmd(tab_a, tab_b, (argc - 2)) == 0)
		ft_printf("Error\n");
	return (1);
}
