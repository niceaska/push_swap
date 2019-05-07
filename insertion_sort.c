#include "push-swap.h"

static void		best_path(t_stack *sa, t_stack *sb)
{
	t_lst			*list;
	char			*str;
	int				min;
	unsigned int	i;

	list = sa->top;
	min = find_min(sa);
	i = 0;
	while (list->data != min)
	{
		i++;
		list = list->next;
	}
	if (i <= stack_size(sa) / 2)
	{
		while (sa->top->data != min)
		{
		
			rotate_ab(&sa, &sb, "ra");
			ft_putendl("ra");
		}
	}
	else
	{
		while (sa->top->data != min)
		{
			rev_rotate(&sa, &sb, "rra");
			ft_putendl("rra");
		}
	}
}

void	ins_sort(t_stack *sa, t_stack *sb)
{
	char *str;

	int s = stack_size(sa);
	str = NULL;
	int min;
	//	print_stack(sa, sb);

	while (!is_empty(sa) && stack_size(sa) >= 2)
	{
		min = find_min(sa);
		best_path(sa, sb);
		push_ab(&sa, &sb, "pb");
		ft_putendl("pb");
	}

			ft_memdel((void *)str);
}