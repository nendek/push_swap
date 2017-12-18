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

int		ft_double(int *tab, int end)
{
	int	i;
	int j;

	i = 0;
	while (i < end)
	{
		j = i + 1;
		while (j < end)
		{
			if (tab[i] == tab[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_parsing(int ac, char **av, int *tab)
{
	long long	*tmp;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!(tmp = malloc(sizeof(*tmp) * ac)))
		return (0);
	if (av[i][j] == '-')
	{
		if (ft_isdigit(av[i][j + 1]) == 1)
			j++;
		else
			return (0);
	}
	while (i < ac)
	{
		while (av[i][j] != '\0')
		{
			if (ft_isdigit(av[i][j] == 0))
				return (0);
			j++;
		}
		tmp[i] = ft_long_atoi(av[i]);
		if (tmp[i] > 2147483647 || tmp[i] < -2147483648)
			return (0);
		tab[i] = (int)tmp[i];
		if (ft_double(tab, i) == 0)
			return (0);
		i++;
		j = 0;
	}
	free(tmp);
	return (1);
}

int		main(int argc, char **argv)
{
	int		*tab;

	//check doublon et digit
	tab = malloc(sizeof(*tab) * argc);
	ft_printf("retour de parsing : %d", ft_parsing(argc, argv, tab));
	return (0);
}
