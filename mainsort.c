#include "push_swap.h"

static void		devide(t_env *e, int *arr, unsigned int size)
{
	int mid;

	ft_quicksort(arr, 0, size - 1);
	mid = arr[size / 2];
	while (is_more(e->s_a, mid))
	{
		if (e->s_a->top->data <= mid)
			pb(e);
		else
		{	
			if (to_next(e->s_a, mid) < stack_size(e->s_a) / 2)
				ra(e);
			else
				rra(e);
		}
	}
}

static t_move	*find_path(t_stack *sa, t_stack *sb, int el)
{
	t_move			*move;
	unsigned int	path_sa;
	unsigned int	path_sb;

	path_sa = (find_place(sa, el, 0) > stack_size(sa) / 2) ?\
		stack_size(sa) - find_place(sa, el, 0) : find_place(sa, el, 0);
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

static void		insertion_s(t_env *e)
{
	unsigned int	pl_a;
	unsigned int	pl_b;
	int				val1;
	int				val2;

	while (!is_empty(e->s_b))
	{
		pl_b = find_best_index(e->s_a, e->s_b);
		pl_a = find_place(e->s_a, get_by_index(e->s_b, pl_b), 0);
		val1 = get_by_index(e->s_b, pl_b);
		val2 = get_by_index(e->s_a, pl_a);
		if (pl_b > stack_size(e->s_b) / 2 && pl_a > stack_size(e->s_a) / 2)
			while (e->s_a->top->data != val2 && e->s_b->top->data != val1)
				rrr(e);
		else if (pl_b < stack_size(e->s_b) / 2 && pl_a < stack_size(e->s_a) / 2)
			while (e->s_a->top->data != val2 && e->s_b->top->data != val1)
				rr(e);
		goto_pos(e, get_index(e->s_b, val1), "b");
		goto_pos(e, get_index(e->s_a, val2), "ra");	
		pa(e);
	}
}

void			mainsort(t_env *e, int *arr, unsigned int size)
{
	int		min;
	int		max;

	while (size / 4 && !is_sorted(e->s_a, 0, stack_size(e->s_a)))
	{
			devide(e, arr, size);
			size /= 2;
	}
	(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
	if (!is_sorted(e->s_a, 0, stack_size(e->s_a)))
		while (!is_empty(e->s_a))
			pb(e);
	max = find_max(e->s_b, 0, 0);
	goto_pos(e, get_index(e->s_b, max), "b");
	pa(e);
	(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
	insertion_s(e);
	min = find_min(e->s_a, 0, 0);
	if (get_index(e->s_a, min) > stack_size(e->s_a) / 2)
		while (!is_sorted(e->s_a, 0, stack_size(e->s_a)))
			rra(e);
	else
		while (!is_sorted(e->s_a, 0, stack_size(e->s_a)))
			ra(e);
}
