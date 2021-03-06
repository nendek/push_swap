/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:23:44 by pnardozi          #+#    #+#             */
/*   Updated: 2017/12/19 14:25:30 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_sort(int *tab, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		if (tab[i] < tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
