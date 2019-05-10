#include "push_swap.h"

void	sort_tree(t_env *e)
{
	unsigned int size;

	size = stack_size(e->s_a);
	while (!is_sorted(e->s_a, 0, size))
	{
		if (size <= 3)
			if (e->s_a->top->next->data < e->s_a->top->data)
				op_sa(e);
		if (size > 2)
		{
			if (e->s_a->top->data == find_max(e->s_a, 0, 0))
				ra(e);
			(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
			if (find_bottom(e->s_a) != find_max(e->s_a, 0, 0))
				rra(e);
			(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
		}
	}
}

void	sel_sort(t_env *e)
{
	int max;
	int min;

	while (!is_sorted(e->s_a, 0, stack_size(e->s_a)) \
		&& stack_size(e->s_a) >= 3)
	{
		min = find_min(e->s_a, 0, 0);
		goto_pos(e, get_index(e->s_a, min), "ra");
		pb(e);
	}
	(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
	if (!is_sorted(e->s_a, 0, stack_size(e->s_a)))
		sort_tree(e);
	(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
	while (!is_empty(e->s_b))
	{
		max = find_max(e->s_b, 0, 0);
		goto_pos(e, get_index(e->s_b, max), "b");
		pa(e);
	}
}