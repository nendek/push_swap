/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 14:18:10 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/16 14:18:23 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct	s_index
{
	int a;
	int b;
}				t_index;

int				ft_cmd(int *pile_a, int *pile_b, int end);
void			ft_sx(int *pile_x, int i_x);
void			ft_ss(int *pile_a, int *pile_b, t_index i);
void			ft_rx(int *pile_x, int i_x);
void			ft_rr(int *pile_a, int *pile_b, t_index i);
void			ft_rrx(int *pile_x, int i_x);
void			ft_rrr(int *pile_a, int *pile_b, t_index i);
int				ft_parsing_int(int ac, char **av, int *tab, int i);

#endif
