/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:09:46 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/18 15:49:03 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft/includes/libft.h"
#include "./libft/printf/includes/ft_printf.h"

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

static int		ft_parsing(int ac, char **av, int *tab)
{
	long long		*tmp;
	int			i;
	int			j;

	i = 1;
	if (!(tmp = malloc(sizeof(*tmp) * ac - 1)))
		return (0);
	ac--;
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

int		main(int argc, char **argv)
{
	int		*tab;

	//check doublon et digit remplie le tableau par le fin
	if (!(tab = malloc(sizeof(int) * argc - 1)))
		return (0);
	if (ft_parsing(argc, argv, tab) == 0 || argc < 2)
	{
		ft_printf("ERROR\n");
		return (0);
	}

	//test
	int i = 0;
	while (i < argc - 1)
	{
		ft_printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	return (0);
}
