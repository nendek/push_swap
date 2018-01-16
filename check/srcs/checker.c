/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:09:46 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 14:31:02 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char		**recovery(char **av, int ac, int *length, int *i)
{
	if (ac == 2)
	{
		*length = ft_countword(av[1], ' ');
		*i = 0;
		return (ft_strsplit(av[1], ' '));
	}
	else
	{
		*length = ac - 1;
		*i = 1;
		return (av);
	}
}

int				main(int argc, char **argv)
{
	int		*tab_a;
	int		*tab_b;
	int		length;
	char	**av;
	int		i;

	av = recovery(argv, argc, &length, &i);
	if (!(tab_a = malloc(sizeof(int) * length)))
		return (0);
	if (!(tab_b = malloc(sizeof(int) * length)))
		return (0);
	if (ft_parsing_int(length, av, tab_a, i) == 0 || length < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (ft_cmd(tab_a, tab_b, (length - 1)) == 0)
		ft_printf("Error\n");
	free(tab_a);
	free(tab_b);
	return (1);
}
