#include "push-swap.h"

int 		get_index(t_stack *sa, unsigned int val)
{
	t_lst			*list;
	unsigned int	i;

	i = 0;
	list = sa->top;
	while (list->data != val)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int 		get_by_index(t_stack *sa, unsigned int index)
{
	t_lst *list;

	list = sa->top;
	while (list && index--)
		list = list->next;
	return (list->data);
}

void		goto_pos(t_stack *sa, t_stack *sb, unsigned int pos, char *o)
{
	int val;

	if (ft_strcmp("ra", o) == 0)
		val = get_by_index(sa, pos);
	else
		val = get_by_index(sb, pos);
	if (ft_strcmp("ra", o) == 0)
	{
		if (get_index(sa, val) > stack_size(sa) / 2)
			while (sa->top->data != val)
				rra(sa, sb);
		else
			while (sa->top->data != val)
				ra(sa, sb);
	}
	else
	{
		if (get_index(sb, val) > stack_size(sb) / 2)
			while (sb->top->data != val)
				rrb(sa, sb);
		else
			while (sb->top->data != val)
				rb(sa, sb);
	}
}

int		is_values(t_stack *s, int *arr, int size)
{
	t_lst *list;
	unsigned int j;

	list = s->top;
	while (list)
	{
		j = 0;
		while (j < size)
		{
			if (list->data == arr[j])
				return (1);
			j++;
		}

		list = list->next;
	}
	return (0);
}


int		path_to_next(t_stack *s, int *arr, int size)
{
	t_lst			*list;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	list = s->top;
	while (list)
	{
		j = 0;
		while (j < size)
		{
			if (list->data == arr[j])
				return (i);
			j++;
		}
		i++;
		list = list->next;
	}
	return (i);
}
