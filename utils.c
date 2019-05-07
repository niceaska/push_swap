#include "push-swap.h"

int				is_sorted(t_stack *s, unsigned int start, unsigned int end)
{
	t_lst *list;
	unsigned int i;

	if (!s)
		return (-1);
	list = s->top;
	i = 0;
	while (list && list->next && i <= end)
	{
		if (i >= start)
			if (list->data > list->next->data)
				return (0);
		i++;
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

int		find_max(t_stack *s, int excl, int flag)
{
	t_lst	*list;
	int		res;

	list = s->top;
	if (!flag)
	{
		res = list->data;
		while (list)
		{
			if (list->data > res)
				res = list->data;
			list = list->next;
		}
	}
	else
	{
		res = find_min(s, 0, 0);
		while (list)
		{
			if (list->data > res && list->data < excl)
				res = list->data;
			list = list->next;
		}
	}
	return (res);
}

int		find_min(t_stack *s, int excl, int flag)
{
	t_lst	*list;
	int		res;

	list = s->top;
	if (!flag)
	{
		res = list->data;
		while (list)
		{
			if (list->data < res)
				res = list->data;
			list = list->next;
		}
	}
	else
	{
		res = find_max(s, 0, 0);
		while (list)
		{
			if (list->data < res && list->data > excl)
				res = list->data;
			list = list->next;
		}
	}
	return (res);
}
