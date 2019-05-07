#include "push-swap.h"
#include <stdio.h>

static int 		get_by_index(t_stack *sa, unsigned int index)
{
	t_lst *list;

	list = sa->top;
	while (list && index--)
		list = list->next;
	return (list->data);
}


static int	find_bottom(t_stack *s)
{
	t_lst *list;

	list = s->top;
	while (list->next)
		list = list->next;
	return (list->data);
}


static int		push_back(t_stack *sa, t_stack *sb, int pivot)
{
	char *str;

	if (stack_size(sb))
	{
		while (stack_size(sb) > 0)
		{
			pa(sa, sb);
		}
	}

	return (1);
}






static int		go_back(int pivot, int p_index, t_stack *sa, t_stack *sb, int pos)
{
	char *str;
	unsigned int index;
	unsigned int rot;

	index = get_index(sa, pivot);
	goto_pos(sa, sb, get_index(sa, pivot), "ra");
	push_back(sa, sb, pivot);
	//while (get_by_index(sa, index) != pivot)
	//	rra(sa, sb);
	return (p_index);
}
/*
static int		is_values(t_stack *s, int val, int *arr, int size)
{
	t_lst		*list;
	unsigned int i;

	i = 0;
	list = s->top;
	while (list)
	{
		i = 0;
		while (i <= size)
		{
			if (list->data < val &&\
				 list->data == arr[i])
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}
*/
static int		*get_subarray(t_stack *s, int bottom, int top)
{
	t_lst *list;
	unsigned int size;
	int *arr;
	int i;
	int j;

	j = 0;
	i = 0;
	list = s->top;
	size = top - bottom + 1;
	if (size >= 1)
	{
		arr = (int *)malloc(sizeof(int) * size);
		while (list)
		{
			if (i >= bottom && i <= top)
				arr[j++] = list->data;
			i++;
			list = list->next;
		}
		return (arr);

	}
	return (0);
}



static int		arr_max(int *arr, int size)
{
	unsigned int	i;
	int				max;
	
	i = 0;
	max = arr[0]; 
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}


static int		partition(t_stack *sa, t_stack *sb, int top, int bottom)
{
	int		pivot;
	t_lst	*list;
	unsigned int i;
	char *str;
	int		p_index;
	int *sub_arr = get_subarray(sa, bottom, top);
	int size = top - bottom + 1;


	i = 0;
	if (is_sorted(sa, bottom, top))
		return (bottom);
	//if (sub_arr[size - 1] == arr_max(sub_arr, size))
	//	return (top);
	pivot = get_by_index(sa, bottom);
	p_index = bottom;
	int j = bottom;
	i = 0;
	int count = 0;
	int rot = 0;
	while (is_values(sa, pivot, sub_arr, size))
	{
		if (sa->top->data < pivot)
		{
			if (stack_size(sa) > 1)
				pb(sa, sb);
			p_index++;
			count++;
		}
		else
		{
			ra(sa, sb);
			rot++;
		}

	}
	if (rot > stack_size(sa) / 2)
		while (rot++ < stack_size(sa))
			ra(sa, sb);
	else
		while (rot--)
			rra(sa, sb);
	//print_stack(sa, sb);
	ft_memdel((void *)&sub_arr);

	return (go_back(pivot, p_index, sa, sb, j));
}

int				quick_sort(int top, int bottom, t_stack *sa, t_stack *sb)
{
	int		p_index;

	if (top < 0 || bottom < 0  || top > stack_size(sa) || bottom > stack_size(sa))
		return (1);
	if (top < bottom)
		return (1);
	if ((is_sorted(sa, 0, stack_size(sa))))
		return (1);
	p_index = partition(sa, sb, top, bottom);
	quick_sort(top, p_index + 1, sa, sb);
	quick_sort(p_index - 1, bottom, sa, sb);
	return (1);
}