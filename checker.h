
#ifndef CHECKER_H
# define CHECKER_H

# include "./libft/libft/includes/libft.h"
# include "./libft/libft/includes/get_next_line.h"
# include "./libft/printf/includes/ft_printf.h"

typedef struct		s_index
{
	int a;
	int b;
}			t_index;

int	ft_cmd(int *pile_a, int *pile_b, int end);
void	ft_sx(int *pile_x, int i_x);
void	ft_ss(int *pile_a, int *pile_b, t_index i);
void	ft_rx(int *pile_x, int i_x);
void	ft_rr(int *pile_a, int *pile_b, t_index i);
void	ft_rrx(int *pile_x, int i_x);
void	ft_rrr(int *pile_a, int *pile_b, t_index i);

#endif
