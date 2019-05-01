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
int					is_sorted(t_stack *s);
int					is_rev_sorted(t_stack *s);

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

void				ft_quicksort(int *arr, int bot, int top); 
void				merge_sort(t_stack *sa, t_stack *sb, int *arr, unsigned int size);

#endif