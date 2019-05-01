#include "push-swap.h"

static char		*case_swap(t_stack *sa, t_stack *sb)
{
	char *str;

	str = NULL;  
	if (sb->top && sa->top->next && sb->top->next)
		if (sa->top->data > sa->top->next->data &&\
			sb->top->data < sb->top->next->data)
			str = ft_strdup("ss");
	else if (sa->top->next && sb->top && sa->top->next->data < sa->top->data\
			&& (!sb->top->next || (sb->top->data > sb->top->next->data)))
		str = ft_strdup("sa");
	else if (sb->top &&(!sa->top->next || (sa->top->data < sa->top->next->data))\
			&& (sb->top->data < sb->top->next->data))
		str = ft_strdup("sb");
	return(str);
}

static void		devide(t_stack *sa, t_stack *sb, int *arr, unsigned int size)
{
	char			*str;
	long			mid;
	unsigned int	half;

	half = stack_size(sa) / 2;
	ft_quicksort(arr, 0, size);
	mid = arr[size / 2];
	while (half)
	{
		if (sa->top->data <= mid)
		{
			push_ab(&sa, &sb, "pb");
			write(1, "pb\n", 3);
			half--;
		}
		else
		{
			rotate_ab(&sa, &sb, "ra");
			ft_putendl("ra");
		}
		str = case_swap(sa, sb);
		if (str)
		{
			swap(&sa, &sb, str);
			ft_putendl(str);
			free(str);

		}
	}
}

void	merge_sort(t_stack *sa, t_stack *sb, int *arr, unsigned int size)
{
	char *str;

	devide(sa, sb, arr, size);
	while (!is_sorted(sa) || !is_rev_sorted(sb))
	{
		str = case_swap(sa, sb);
		if (str)
		{
			swap(&sa, &sb, str);
			ft_putendl(str);
			free(str);

		}
			print_stack(sa, sb);

		if (!is_sorted(sa) && !is_rev_sorted(sb))
		{
			rev_rotate(&sa, &sb, "rrr");
			ft_putendl("rrr");
		}
		if (!is_sorted(sa) && is_rev_sorted(sb))
		{
			t_lst *list = sa->top;
			while(list->next)
				list = list->next;
			if (list->data > sa->top->data)
			{
				rev_rotate(&sa, &sb, "rra");
				ft_putendl("rra");
			}
			else
			{
				rotate_ab(&sa, &sb, "ra");
				ft_putendl("ra");
			}
		}
		if (is_sorted(sa) && !is_rev_sorted(sb))
		{
			rotate_ab(&sa, &sb, "rb");
			ft_putendl("rb");
		}
	}
	print_stack(sa, sb);
}