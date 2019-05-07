#include "push-swap.h"

char		*case_swap(t_stack *sa, t_stack *sb)
{
	char *str;

	str = NULL;  
	if (sb->top && sa->top->next && sb->top->next)
		if (sa->top->data > sa->top->next->data &&\
			sb->top->data < sb->top->next->data && !str)
			str = ft_strdup("ss");
	else if (sa->top->next && sb->top && sa->top->next->data < sa->top->data\
			&& (!sb->top->next || (sb->top->data > sb->top->next->data)) && !str)
		str = ft_strdup("sa");
	else if (sb->top &&(!sa->top->next || (sa->top->data < sa->top->next->data))\
			&& (sb->top->data < sb->top->next->data) && !str)
		str = ft_strdup("sb");
	return(str);
}

static int		is_values(t_stack *s, int val)
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


static int	find_bottom(t_stack *s)
{
	t_lst *list;

	list = s->top;
	while (list->next)
		list = list->next;
	return (list->data);
}

static int		path_to_next(t_stack *s, int val)
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


#include <stdio.h>
static void		devide(t_stack *sa, t_stack *sb, int *arr, unsigned int size)
{
	long mid;
	int max;

	ft_quicksort(arr, 0, size - 1);
	mid = arr[size / 2];
	while (is_values(sa, mid))
	{
		if (sa->top->data <= mid)
			pb(sa, sb);
		else
		{	
			if (path_to_next(sa, mid) < stack_size(sa) / 2 && \
				((get_index(sb, find_max(sb, 0, 0)) < stack_size(sb) / 2)
				&& sb->top->data != find_max(sb, 0, 0)) && \
				(sa->top->data > sa->top->next->data &&\
				sb->top->data < sb->top->next->data))
			{
				swap(&sa, &sb, "ss");
				ft_putendl("ss");
			}
			else if (path_to_next(sa, mid) < stack_size(sa) / 2 \
				&& (get_index(sb, find_max(sb, 0, 0)) < stack_size(sb) / 2)
				&& sb->top->data != find_max(sb, 0, 0))
				rr(sa, sb);
			else if (path_to_next(sa, mid) < stack_size(sa) / 2 \
				&& (get_index(sb, find_max(sb, 0, 0)) > stack_size(sb) / 2) &&
				sb->top->data != find_max(sb, 0, 0))
				rrr(sa, sb);
			else if (path_to_next(sa, mid) < stack_size(sa) / 2)
				ra(sa, sb);
			else
				rra(sa, sb);
		}
	}
	/*while (is_values2(sb, mid))
	{
		if (sb->top->data > mid)
			pa(sa, sb);
		else
		{	
			if (path_to_next2(sb, mid) < stack_size(sb) / 2 && \
				((get_index(sb, find_max(sb, 0, 0)) < stack_size(sb) / 2)
				&& sb->top->data != find_max(sb, 0, 0)) && \
				(sa->top->data > sa->top->next->data &&\
				sb->top->data < sb->top->next->data))
			{
				swap(&sa, &sb, "ss");
				ft_putendl("ss");
			}
			else if (path_to_next(sb, mid) < stack_size(sb) / 2 \
				&& (get_index(sb, find_max(sb, 0, 0)) < stack_size(sb) / 2)
				&& sb->top->data != find_max(sb, 0, 0))
				rr(sa, sb);
			else if (path_to_next2(sb, mid) < stack_size(sb) / 2 \
				&& (get_index(sb, find_max(sb, 0, 0)) > stack_size(sb) / 2) &&
				sb->top->data != find_max(sb, 0, 0))
				rrr(sa, sb);
			else if (path_to_next2(sb, mid) < stack_size(sb) / 2)
				ra(sa, sb);
			else
				rra(sa, sb);
		}
	}*/
}



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

static void		minmax(t_stack *sa, t_stack *sb, char *o)
{
	int min;
	int min2;
	int max;
	int max2;
	int pos;
	int pos2;

	if (ft_strcmp(o, "ra") == 0 && !is_empty(sa))
	{
		min = find_min(sa, 0, 0);
		min2 = find_min(sa, min, 1);	
	}
	else
	{
		max = find_max(sb, 0, 0);
		max2 = find_max(sb, max, 1);
	}
	if (ft_strcmp("ra", o) == 0 && !is_empty(sa))
	{
		pos2 = stack_size(sa) - get_index(sa, min2);
		pos = stack_size(sa) - get_index(sa, min);
		if ((pos < get_index(sa, min) || pos2 < get_index(sa, min2)))\
			while (sa->top->data != min && sa->top->data != min2)
				rra(sa, sb);
		else
			while ((sa->top->data != min2 && sa->top->data != min))
				ra(sa, sb);
	}
	else
	{
		pos2 = stack_size(sb) - get_index(sb, max2);
		pos = stack_size(sb) - get_index(sb, max);
		if ((pos < get_index(sb, max) || pos2 < get_index(sb, max2)))\
			while (sb->top->data != max2 && sb->top->data != max)
				rrb(sa, sb);
		else
			while (sb->top->data != max2 && sb->top->data != max)
				rb(sa, sb);
	}
}
void	merge_sort(t_stack *sa, t_stack *sb, int *arr, unsigned int size)
{
	int n;
	int		min;
	int		max;
	int		*sub_arr;
	char *str;
	unsigned int i;

	while (stack_size(sa) >= 30\
			&& !is_sorted(sa, 0, stack_size(sa)))
	{
		if (!is_sorted(sa, 0, 5))
		{
			sub_arr = get_subarray(sa, 0, 10);
			devide(sa, sb, sub_arr, 10);
			free(sub_arr);
		}
		else
		{
			n = 5;
			while (n--)
				pb(sa, sb);
		}
	}

	while (!is_empty(sa) && !is_sorted(sa, 0, stack_size(sa))) 
	{	
		min = find_min(sa, 0, 0);
		if (sb->top)
			max = find_max(sb, 0, 0);
		while (sb->top && (get_index(sa, min) < stack_size(sa) / 2)
			&& (get_index(sb, max) < stack_size(sb) / 2)
			&& sa->top->data != min && sb->top->data != max)
			rr(sa, sb); 
		while (sb->top && (get_index(sa, min) > stack_size(sa) / 2)
			&& (get_index(sb, max) > stack_size(sb) / 2)
			&& sa->top->data != min && sb->top->data != max)
			rrr(sa, sb);
		goto_pos(sa, sb, get_index(sa, min), "ra");
		pb(sa, sb);
	}

	while (sb->top->data == find_max(sb, 0, 0))
		pa(sa, sb);

	/*while (!is_empty(sb))
	{
		max = find_max(sb, 0, 0);
		goto_pos(sa, sb, get_index(sb, max), "b");
		min = find_min(sb, 0, 0);
		pa(sa, sb);
	}*/


	i = 0;
	while (!is_empty(sb))
	{
		max = find_max(sb, 0, 0);
		if (i % 2)
			minmax(sa, sb, "b");
		else
			goto_pos(sa, sb, get_index(sb, max), "b");		
		pa(sa, sb);
		if (str = case_swap(sa, sb))
		{
			swap(&sa, &sb, str);
			ft_putendl(str);
			free(str);
		} 
		i++;
	}

}
