/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 21:31:16 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 20:00:08 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "libft.h"

typedef	struct			s_linklst
{
	int					data;
	struct s_linklst	*next;
	struct s_linklst	*prev;
}						t_linklst;

typedef struct			s_stack
{
	t_linklst	*a_head;
	t_linklst	*a_end;
	t_linklst	*b_head;
	t_linklst	*b_end;
	size_t		alen;
	size_t		blen;
	int			bmin;
	int			bmax;
	int			amax;
	int			amin;
	int			op_count;
}						t_stack;

typedef void			(*t_ops)(t_stack *stacks);
typedef enum
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
	invalid
}	t_operation;

int						ps_movesa(t_stack *stacks, int guess);
void					ps_dist_insert(t_stack *stacks, int guess,
							int *dist_rb, int *dist_rrb);
void					ps_dist_minmax(t_stack *stacks, int guess,
							int *dist_rb, int *dist_rrb);
int						ps_movesb(t_stack *stacks, int guess);
int						ps_diff(int a, int b);
int						ps_minint(int a, int b);
void					ps_prnt_stacks(t_stack *env);
void					ps_pop(t_stack *stacks, int to_pop);
void					ps_operate_sa(t_stack *stacks);
void					ps_operate_sb(t_stack *stacks);
void					ps_operate_ss(t_stack *stacks);
void					ps_operate_ra(t_stack *stacks);
void					ps_operate_rb(t_stack *stacks);
void					ps_fixlink_src(t_stack *stacks, t_linklst *node,
							t_operation op);
void					ps_operate_pa(t_stack *stacks);
void					ps_operate_pb(t_stack *stacks);
void					ps_operate_rr(t_stack *stacks);
void					ps_operate_rra(t_stack *stacks);
void					ps_operate_rrb(t_stack *stacks);
void					ps_operate_rrr(t_stack *stacks);
int						ps_rot_ra(int target, t_stack *stacks);
int						ps_rot_rb(int target, t_stack *stacks);
int						ps_min_moves(t_stack *stacks);
void					ps_setup_ops(t_ops *operation);
t_ops					ps_execute(t_operation str);
t_linklst				*ps_lstnew(int d);
void					ps_lstpush_end(t_stack *env, t_linklst *node);
int						ps_is_dup(t_linklst *a, int argv);
void					ps_setstack1(char **argv, t_stack *env);
void					ps_setstack2(int argc, char **argv, t_stack *env);
int						array_len(char **array);
void					ps_sort_mini_a(t_stack *ent);
void					push_swap(int argc, char **argv, int offset,
							t_stack *ent);
void					ps_final_pa(t_stack *ent, int offset);
void					ps_final_rot_ra(t_stack *ent);
int						final_rot_rb(t_stack *stacks);
void					free_ent(t_stack *ent);
void					free_both(t_stack *ent, char **line);
void					free_line(char **line);
void					err_setstack(t_stack *ent, char **line);
#endif
