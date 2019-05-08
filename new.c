#include "push-swap.h"

static int		*get_subarray_minmax(t_stack *s, int size, unsigned int i,  int fl)
{
	int		*arr;
	int		min_max;

	arr = (int *)malloc(sizeof(int) * size);
	if (!fl)
	{
		min_max = find_min(s, 0, 0);
		while (i < size)
		{
			arr[i++] = min_max;
			min_max = find_min(s, min_max, 1);
		}
	}
	else
	{
		min_max = find_max(s, 0, 0);
		while (i < size)
		{
			arr[i++] = min_max;
			min_max = find_max(s, min_max, 1);
		}
	}
	return (arr);
}

static void		get_size(t_stack *sa, int *size)
{
	if (stack_size(sa) <= 450)
		*size = 16;
	if (stack_size(sa) <= 350)
		*size = 14;
	if (stack_size(sa) <= 250)
		*size = 12;
	if (stack_size(sa) <= 175)
		*size = 10;
	if (stack_size(sa) <= 100)
		*size = 5;
	if (stack_size(sa) <= 50)
		*size = 4;
	if (stack_size(sa) <= 20)
		*size = 2;
	if (stack_size(sa) <= 10)
		*size = 1;
}

static void		devider(t_stack *sa, t_stack *sb, int size)
{
	int				*sub_mins;
	int				*sub_max;

	while (!is_empty(sa))
	{
		get_size(sa, &size);
		sub_mins = get_subarray_minmax(sa, size, 0, 0);
		sub_max = get_subarray_minmax(sa, size, 0, 1);
		while (path_to_next(sa, sub_mins, size) != 0 \
				&& path_to_next(sa, sub_max, size) != 0)
			if ((path_to_next(sa, sub_mins, size) < stack_size(sa) / 2 ||\
				 path_to_next(sa, sub_max, size) < stack_size(sa) / 2))
				ra(sa, sb);
			else
				rra(sa, sb);	
		pb(sa, sb);
		if (is_values(sb, sub_max, size) && !path_to_next(sb, sub_max, size))	
			if ((path_to_next(sa, sub_mins, size) != 0 \
				&& path_to_next(sa, sub_max, size) != 0))
				rr(sa, sb);
			else 
				rb(sa, sb);
		else
			if (stack_size(sa) > 1 && sa->top->data > sa->top->next->data)
				if (stack_size(sb) > 1 && sb->top->data < sb->top->next->data)
					ss(sa, sb);
		free(sub_mins);
		free(sub_max);
	}		
}

static void		minmax(t_stack *sa, t_stack *sb)
{
	int		max;
	int		max2;
	int		pos;
	int		pos2;

	max = find_max(sb, 0, 0);
	max2 = find_max(sb, max, 1);
	pos2 = stack_size(sb) - get_index(sb, max2);
	pos = stack_size(sb) - get_index(sb, max);
	if ((pos < get_index(sb, max) || pos2 < get_index(sb, max2)))\
		while (sb->top->data != max2 && sb->top->data != max)
			rrb(sa, sb);
	else
		while (sb->top->data != max2 && sb->top->data != max)
			rb(sa, sb);	
}

void	minmax_sort(t_stack *sa, t_stack *sb, int *arr, unsigned int size)
{
	int				min;
	int				max;
	unsigned int	i;
	
	devider(sa, sb, 18);
	i = 0;
	while (!is_empty(sb))
	{
		max = find_max(sb, 0, 0);
		if (i % 2 && stack_size(sb) > 1)
			minmax(sa, sb);
		else if (stack_size(sb) > 1)
			goto_pos(sa, sb, get_index(sb, max), "b");		
		pa(sa, sb);
		if (stack_size(sa) > 1 && sa->top->data > sa->top->next->data)
			if (stack_size(sb) > 1 && sb->top->data < sb->top->next->data)
				ss(sa, sb);
			else
				op_sa(sa, sb);
		i++;
	}
}
