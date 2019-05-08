#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
 
# include "libft.h"

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
	unsigned int	s_sa;
	unsigned int	s_sb;
}					t_env;


void				push(t_stack **s, int data);
int					pop(t_stack **s);
t_stack				*init_stack(void);
int					is_empty(t_stack *s);
int					is_sorted(t_stack *s, unsigned int start, unsigned int end);
unsigned int		stack_size(t_stack *s);

void				free_stack(t_stack *s);
void				free_tab(char **tab);
void				print_stack(t_stack *sa, t_stack *sb); 
void				print_error(t_stack *sa, t_stack *sb, t_env *e);

int					*check_args(char **ag, int ac, t_stack **sa, unsigned int i);
void				swap(t_stack **sa, t_stack **sb, char *ord);
void				push_ab(t_stack **sa, t_stack **sb, char *ord);
void				rotate_ab(t_stack **sa, t_stack **sb, char *ord);
void				rev_rotate(t_stack **sa, t_stack **sb, char *ord);

int					find_max(t_stack *s, int excl, int flag);
int					find_min(t_stack *s, int excl, int flag);
void				ft_quicksort(int *arr, unsigned int bot, unsigned int top);
unsigned int 		get_index(t_stack *sa, int val);
void				goto_pos(t_stack *sa, t_stack *sb, unsigned int pos, char *o);
int 				get_by_index(t_stack *sa, unsigned int index);
unsigned int		find_place(t_stack *s, int val);
unsigned int		to_next(t_stack *s, int val);
int					is_more(t_stack *s, int val);
int					find_bottom(t_stack *s);

void				pa(t_stack *sa, t_stack *sb);
void				pb(t_stack *sa, t_stack *sb);
void				ra(t_stack *sa, t_stack *sb);
void				rb(t_stack *sa, t_stack *sb);
void				rra(t_stack *sa, t_stack *sb);
void				rrb(t_stack *sa, t_stack *sb);
void				rr(t_stack *sa, t_stack *sb);
void				rrr(t_stack *sa, t_stack *sb);
void				ss(t_stack *sa, t_stack *sb);
void				op_sa(t_stack *sa, t_stack *sb);
void				op_sb(t_stack *sa, t_stack *sb);

void				mainsort(t_stack *sa, t_stack *sb, int *arr, unsigned int size);
void				sel_sort(t_stack *sa, t_stack *sb);
void				sort_tree(t_stack *sa, t_stack *sb);

#endif