#include "push-swap.h"

void	sort_tree(t_stack *sa, t_stack *sb)
{
	unsigned int size;

	size = stack_size(sa);
	if (size <= 3)
		if (sa->top->next->data < sa->top->data)
			op_sa(sa, sb);
	if (size > 2)
	{
		if (sa->top->data == find_max(sa, 0, 0))
			ra(sa, sb);
		if (find_bottom(sa) == find_min(sa, 0, 0))
			rra(sa, sb);
	}
}

void	sel_sort(t_stack *sa, t_stack *sb)
{
	int max;
	int min;

	while (!is_sorted(sa, 0, stack_size(sa)) && stack_size(sa) >= 3)
	{
		min = find_min(sa, 0, 0);
		goto_pos(sa, sb, get_index(sa, min), "ra");
		pb(sa, sb);
	}
	if (!is_sorted(sa, 0, stack_size(sa)))
		sort_tree(sa, sb);
	while (!is_empty(sb))
	{
		max = find_max(sb, 0, 0);
		goto_pos(sa, sb, get_index(sb, max), "b");
		pa(sa, sb);
	}

}