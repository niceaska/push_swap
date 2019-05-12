/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:47:10 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:47:14 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "libft.h"
# include <fcntl.h>

# define FL_V0 (1 << 0)
# define FL_V1 (1 << 1)
# define FL_C (1 << 2)
# define FL_F (1 << 3)

# define MAG "\033[0;35m"
# define YEL "\033[0;33m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define CYAN "\033[0;36m"
# define BLUE "\033[0;34m"
# define COL "\033[0m"

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stack
{
	struct s_lst	*top;
}					t_stack;

typedef struct		s_move
{
	unsigned int	index;
	int				val;
	unsigned int	path;
}					t_move;

typedef struct		s_env
{
	t_stack			*s_a;
	t_stack			*s_b;
	int				fd;
	short			flags;
	unsigned int	fl_c;
}					t_env;

void				push(t_stack **s, int data);
int					pop(t_stack **s);
t_stack				*init_stack(void);
int					is_empty(t_stack *s);
int					is_sorted(t_stack *s, unsigned int start, unsigned int end);
unsigned int		stack_size(t_stack *s);

void				free_stack(t_stack *s);
void				free_tab(char **tab);
void				print_stack(t_stack *sa, t_stack *sb, short flags);
void				print_error(t_stack *sa, t_stack *sb, t_env *e);

int					*check_args(char **ag, int ac,
								t_stack **sa, unsigned int i);
void				swap(t_stack **sa, t_stack **sb, char *ord);
void				push_ab(t_stack **sa, t_stack **sb, char *ord);
void				rotate_ab(t_stack **sa, t_stack **sb, char *ord);
void				rev_rotate(t_stack **sa, t_stack **sb, char *ord);

int					find_max(t_stack *s, int excl, int flag);
int					find_min(t_stack *s, int excl, int flag);
void				ft_quicksort(int *arr, unsigned int bot, unsigned int top);
unsigned int		get_index(t_stack *sa, int val);
void				goto_pos(t_env *e, unsigned int pos, char *o);
int					get_by_index(t_stack *sa, unsigned int index);
unsigned int		find_place(t_stack *s, int val, unsigned int i);
unsigned int		to_next(t_stack *s, int val);
int					is_more(t_stack *s, int val);
int					find_bottom(t_stack *s);

void				pa(t_env *e);
void				pb(t_env *e);
void				ra(t_env *e);
void				rb(t_env *e);
void				rra(t_env *e);
void				rrb(t_env *e);
void				rr(t_env *e);
void				rrr(t_env *e);
void				ss(t_env *e);
void				op_sa(t_env *e);
void				op_sb(t_env *e);

void				parse_flags(char **ag, int ac, t_env **e);
t_env				*init_env(int flag);
void				process_file(t_env **e, char *fname, int flag);

void				mainsort(t_env *e, int *arr, unsigned int size);
void				sel_sort(t_env *e);
void				sort_tree(t_env *e);

#endif
