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

int			ft_parsing_int(int ac, char **av, int *tab, int i)
{
	long long		*tmp;
	int				j;

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
