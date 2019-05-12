/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:46:20 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:46:24 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void		stack_printer(t_lst *list1, t_lst *list2, short flags)
{
	while (1)
	{
		if (!list1 && !list2)
			break ;
		(flags & FL_C) ? ft_printf(GREEN) : 0;
		(list1) ? ft_printf("%-18d", list1->data) : ft_printf("%-18c", ' ');
		(flags & FL_C) ? ft_printf(COL) : 0;
		(flags & FL_C) ? ft_printf(RED) : 0;
		(list2) ? ft_printf("%18d", list2->data) : ft_printf("%18c", ' ');
		(flags & FL_C) ? ft_printf(COL) : 0;
		if (list1 && list1->next && (!list2 || !list2->next))
			ft_printf("\n");
		if (list2 && list2->next)
			ft_printf("\n");
		if (list1)
			list1 = list1->next;
		if (list2)
			list2 = list2->next;
	}
}

void			print_stack(t_stack *sa, t_stack *sb, short flags)
{
	t_lst	*list1;
	t_lst	*list2;

	list1 = sa->top;
	list2 = sb->top;
	(flags & FL_C) ? ft_printf(BLUE) : 0;
	ft_printf("Stack A:                     Stack B:\n");
	ft_printf("|TOP|                           |TOP|\n");
	(flags & FL_C) ? ft_printf(COL) : 0;
	(flags & FL_C) ? ft_printf(CYAN) : 0;
	ft_printf("-------------------------------------\n");
	(flags & FL_C) ? ft_printf(COL) : 0;
	stack_printer(list1, list2, flags);
	(flags & FL_C) ? ft_printf(CYAN) : 0;
	ft_printf("\n-------------------------------------\n");
	(flags & FL_C) ? ft_printf(COL) : 0;
}

void			op_sb(t_env *e)
{
	swap(&(e->s_a), &(e->s_b), "sb");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("sb", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}
