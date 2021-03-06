/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 09:45:22 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/12 16:36:03 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	int m;

	m = 0;
	if (c >= 'a' && c <= 'z')
	{
		m = c - 32;
		return (m);
	}
	else
		return (c);
}
