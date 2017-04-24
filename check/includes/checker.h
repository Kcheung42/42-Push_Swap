/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcheung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 13:28:50 by kcheung           #+#    #+#             */
/*   Updated: 2017/04/21 20:44:57 by kcheung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"

typedef	struct			s_linklst
{
	int					data;
	struct s_linklst	*next;
}						t_linklst;

typedef struct			s_stack
{
	t_linklst	*a_head;
	t_linklst	*b_head;
	size_t		alen;
	size_t		blen;
	int			debug;
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

void					ch_setup_ops(t_ops *operation);
t_operation				ch_convert(char *str);
t_ops					ch_execute(t_operation str);
int						ch_check_input(t_operation *list, int n);
int						ch_is_solution(t_stack *result);
t_linklst				*ch_lstnew(int d);
void					ch_lstpush_end(t_linklst **begin, t_linklst *node);
void					ch_makestack1(int argc, char **argv, t_stack *env);
void					ch_makestack2(int argc, char **argv, t_stack *env);
void					ch_printlst(t_stack *env);
void					ch_operate_sa(t_stack *stacks);
void					ch_operate_sb(t_stack *stacks);
void					ch_operate_ss(t_stack *stacks);
void					ch_operate_pa(t_stack *stacks);
void					ch_operate_pb(t_stack *stacks);
void					ch_operate_ra(t_stack *stacks);
void					ch_operate_rb(t_stack *stacks);
void					ch_operate_rr(t_stack *stacks);
void					ch_operate_rra(t_stack *stacks);
void					ch_operate_rrb(t_stack *stacks);
void					ch_operate_rrr(t_stack *stacks);
int						ch_is_dup(t_linklst *a, int argv);
void					ch_prnt_error(t_linklst *new, t_stack *ent,
							char **array, char *str);
void					free_ent(t_stack *ent);
void					free_line(char **line);
void					free_both(t_stack *ent, char **line);
void					main_error(t_stack *ent, char **line);
int						checker(int argc, char *argv[], t_stack *env);
#endif
