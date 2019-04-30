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
	struct s_lst *top;
}					t_stack;

void				push(t_stack **s, int data);
int					pop(t_stack **s);
t_stack				*init_stack(void);
int					is_empty(t_stack *s);


#endif