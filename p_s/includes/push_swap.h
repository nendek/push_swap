/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnardozi <pnardozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 13:01:39 by pnardozi          #+#    #+#             */
/*   Updated: 2018/01/11 14:13:42 by pnardozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "checker.h"

# define NB_SOL 4

typedef struct			s_pile
{
	int					*pile_a;
	int					*pile_b;
}						t_pile;

typedef struct			s_cmd_list
{
	char				cmd[2];
	struct s_cmd_list	*next;
}						t_cmd_list;

typedef struct			s_solution
{
	t_cmd_list			*tab[NB_SOL - 1];
}						t_solution;

typedef struct			s_nbr
{
	int					pivot;
	int					first;
	int					last;
}						t_nbr;

int						ft_sort_big(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p);
int						ft_search_small_for_small(int *tab, int last);
int						ft_sort_small(t_pile tab, t_nbr nbr, t_cmd_list **cmd, int p);
void					ft_pushback_cmd(t_cmd_list **beginlist, char *cmd);
int						ft_lentgh_list(t_cmd_list *list);
void					ft_put_list(t_cmd_list *list);
void					ft_sa_list(int *pile_a, int i_a, t_cmd_list **list);
void					ft_sb_list(int *pile_b, int i_b, t_cmd_list **list);
void					ft_ra_list(int *pile_a, int i_a, t_cmd_list **list);
void					ft_rb_list(int *pile_b, int i_b, t_cmd_list **list);
void					ft_rra_list(int *pile_a, int i_a, t_cmd_list **list);
void					ft_rrb_list(int *pile_b, int i_b, t_cmd_list **list);
void					ft_pa_list(t_pile pile, int *last_a, int *last_b, t_cmd_list **list);
void					ft_pb_list(t_pile pile, int *last_b, int *last_a, t_cmd_list **list);

#endif
