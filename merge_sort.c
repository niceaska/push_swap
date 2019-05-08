#include "push-swap.h"

static void		devide(t_stack *sa, t_stack *sb, int *arr, unsigned int size)
{
	int mid;

	ft_quicksort(arr, 0, size - 1);
	mid = arr[size / 2];
	while (is_more(sa, mid))
	{
		if (sa->top->data <= mid)
			pb(sa, sb);
		else
		{	
			if (to_next(sa, mid) < stack_size(sa) / 2)
				ra(sa, sb);
			else
				rra(sa, sb);
		}
	}
}

static t_move	*find_path(t_stack *sa, t_stack *sb, int el)
{
	t_move			*move;
	unsigned int	path_sa;
	unsigned int	path_sb;

	path_sa = (find_place(sa, el) > stack_size(sa) / 2) ?\
		stack_size(sa) - find_place(sa, el) : find_place(sa, el);
	path_sb = (get_index(sb, el) > stack_size(sb) / 2) ?
			stack_size(sb) - get_index(sb, el) : get_index(sb, el);
	move = (t_move *)malloc(sizeof(t_move));
	move->index = get_index(sb, el);
	move->val = el;
	move->path = path_sa + path_sb; 
	return (move);
}

static unsigned int		find_best_index(t_stack *sa, t_stack *sb)
{
	t_move			*move;
	t_lst			*list;
	unsigned int	best_index;
	unsigned int	best_path;

	best_index = 0;
	best_path = 4294967295;
	list = sb->top;
	while (list)
	{
		move = find_path(sa, sb, list->data);
		if (move->path < best_path)
		{
			best_path = move->path;
			best_index = move->index;
		}
		free(move);
		list = list->next;
	}
	return (best_index);
}

static void		insertion_s(t_stack *sa, t_stack *sb)
{
	unsigned int	pl_a;
	unsigned int	pl_b;
	int				val1;
	int				val2;

	while (!is_empty(sb))
	{
		pl_b = find_best_index(sa, sb);
		pl_a = find_place(sa, get_by_index(sb, pl_b));
		val1 = get_by_index(sb, pl_b);
		val2 = get_by_index(sa, pl_a);
		if (pl_b > stack_size(sb) / 2 && pl_a > stack_size(sa) / 2)
			while (sa->top->data != val2 && sb->top->data != val1)
				rrr(sa, sb);
		else if (pl_b < stack_size(sb) / 2 && pl_a < stack_size(sa) / 2)
			while (sa->top->data != val2 && sb->top->data != val1)
				rr(sa, sb);
		goto_pos(sa, sb, get_index(sb, val1), "b");
		goto_pos(sa, sb, get_index(sa, val2), "ra");	
		pa(sa, sb);
	}
}

void			mainsort(t_stack *sa, t_stack *sb, int *arr, unsigned int size)
{
	int		min;
	int		max;

	while (size / 4 && !is_sorted(sa, 0, stack_size(sa)))
	{
			devide(sa, sb, arr, size);
			size /= 2;
	}
	if (!is_sorted(sa, 0, stack_size(sa)))
		while (!is_empty(sa))
			pb(sa, sb);
	max = find_max(sb, 0, 0);
	goto_pos(sa, sb, get_index(sb, max), "b");
	pa(sa, sb);
	insertion_s(sa, sb);
	min = find_min(sa, 0, 0);
	if (get_index(sa, min) > stack_size(sa)/ 2)
		while (!is_sorted(sa, 0, stack_size(sa)))
			rra(sa, sb);
	else
		while (!is_sorted(sa, 0, stack_size(sa)))
			ra(sa, sb);
}
