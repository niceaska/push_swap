#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H
 
# include "libft/libft.h"

typedef struct		s_lst
{
	int				data;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_stack
{
	struct s_lst	*top;
}					t_stack;

void				push(t_stack **s, int data);
int					pop(t_stack **s);
t_stack				*init_stack(void);
int					is_empty(t_stack *s);
int					is_sorted(t_stack *s, unsigned int start, unsigned int end);
int					is_rev_sorted(t_stack *s);
int					quick_sort(int top, int bottom, t_stack *sa, t_stack *sb);

int		find_max(t_stack *s, int excl, int flag);
int					find_min(t_stack *s, int excl, int flag);

void				free_stack(t_stack *s);
void				free_tab(char **tab);

unsigned int		stack_size(t_stack *s);
void				print_stack(t_stack *sa, t_stack *sb); 
void				print_error(t_stack *sa, t_stack *sb);

int					*check_args(char **ag, int ac, t_stack **sa, unsigned int i);

void				swap(t_stack **sa, t_stack **sb, char *ord);
void				push_ab(t_stack **sa, t_stack **sb, char *ord);
void				rotate_ab(t_stack **sa, t_stack **sb, char *ord);
void				rev_rotate(t_stack **sa, t_stack **sb, char *ord);

char				*case_swap(t_stack *sa, t_stack *sb);
void				q_sort(int n, t_stack *sa, t_stack *sb);

void				ft_quicksort(int *arr, int bot, int top); 
void				merge_sort(t_stack *sa, t_stack *sb, int *arr, unsigned int size);
void				ins_sort(t_stack *sa, t_stack *sb);
//void				devide(t_stack *sa, t_stack *sb, int *arr, unsigned int size);
int 				get_index(t_stack *sa, unsigned int val);
void				goto_pos(t_stack *sa, t_stack *sb, unsigned int pos, char *o);
int					path_to_next(t_stack *s, int *arr, int size);
int					is_values(t_stack *s, int *arr, int size);
int 				get_by_index(t_stack *sa, unsigned int index);

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



void	minmax_sort(t_stack *sa, t_stack *sb, int *arr, unsigned int size);
#endif