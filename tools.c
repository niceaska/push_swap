#include "push-swap.h"

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

int		is_more(t_stack *s, int val)
{
	t_lst *list;

	list = s->top;
	while (list)
	{
		if (list->data <= val)
			return (1);
		list = list->next;
	}
	return (0);
}

unsigned int		to_next(t_stack *s, int val)
{
	t_lst			*list;
	unsigned int	i;

	i = 0;
	list = s->top;
	while (list)
	{
		if (list->data <= val)
			return (i);
		i++;
		list = list->next;
	}
	return (i);
}

unsigned int		find_place(t_stack *s, int val)
{
	unsigned int	i;
	int				cmp;
	t_lst			*list;
	t_lst			*l1;

	list = s->top;
	i = 0;
	while (list)
	{
		if (val < list->data)
		{
			l1 = s->top;
			cmp = list->data;
			while (l1)
			{
				if (val < l1->data && l1->data < cmp)
					break ;
				l1 = l1->next;
			}
			if (!l1)
				return (i);
		}
		list = list->next;
		i++;
	}
}
