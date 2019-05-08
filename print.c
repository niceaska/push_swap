#include "push_swap.h"

void			print_error(t_stack *sa, t_stack *sb, t_env *e)
{
	if (sa)
		free_stack(sa);
	if (sb)
		free_stack(sb);
	if (e)
		free(e);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void			print_stack(t_stack *sa, t_stack *sb) 
{
	t_lst	*list1;
	t_lst	*list2;

	list1 = sa->top;
	list2 = sb->top;
	ft_putstr("Stack A:                     Stack B:\n");
	ft_putstr("|TOP|                           |TOP|\n");
	ft_putstr("-------------------------------------\n");
	while (1)
	{
		if (!list1 && !list2)
			break ;

		(list1) ? ft_putnbr(list1->data) : write(1, " ", 1);
				write(1, "     ", 5);

		(list2) ? ft_putnbr(list2->data) : write(1, " ", 1);
		if (list1 && list1->next && (!list2 || !list2->next))
			write(1, "\n", 1);
		if (list2 && list2->next)
			write(1, "\n", 1);
		if (list1)
			list1 = list1->next;
		if (list2)
			list2 = list2->next;
	}
	ft_putstr("\n-------------------------------------\n");
}