#include "push-swap.h"

int				is_sorted(t_stack *s)
{
	t_lst *list;

	if (!s)
		return (-1);
	list = s->top;
	while (list && list->next)
	{
		if (list->data > list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

int				is_rev_sorted(t_stack *s)
{
	t_lst *list;

	if (!s)
		return (-1);
	list = s->top;
	while (list && list->next)
	{
		if (list->data < list->next->data)
			return (0);
		list = list->next;
	}
	return (1);
}

unsigned int	stack_size(t_stack *s)
{
	t_lst			*list;
	unsigned int	size;		

	size = 0;
	if (!s)
		return (0);
	list = s->top;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
