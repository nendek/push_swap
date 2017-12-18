/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 14:02:31 by pnardozi          #+#    #+#             */
/*   Updated: 2017/11/14 15:19:36 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_duplicate(char const *str, char **tab, int c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			tab[j][k] = str[i];
			k++;
		}
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
		{
			tab[j][k] = str[i];
			tab[j][k++] = '\0';
			j++;
			k = 0;
		}
		i++;
	}
	tab[j] = NULL;
}

char		**ft_strsplit(char const *s, char c)
{
	int		nb_word;
	int		*size_word;
	char	**tab;
	int		i;

	i = 0;
	nb_word = ft_countword(s, c);
	if (!(size_word = malloc(sizeof(int) * (nb_word + 1))))
		return (NULL);
	ft_countsizeword(s, c, size_word);
	if (!(tab = malloc(sizeof(char *) * (nb_word + 1))))
		return (NULL);
	while (i < nb_word)
	{
		if (!(tab[i] = malloc(sizeof(char) * (size_word[i] + 1))))
			return (NULL);
		i++;
	}
	free(size_word);
	if (s)
		ft_duplicate(s, tab, c);
	return (tab);
}
