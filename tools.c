/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:48:56 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:49:00 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int					get_by_index(t_stack *sa, unsigned int index)
{
	t_lst *list;

	list = sa->top;
	while (list && index--)
		list = list->next;
	return (list->data);
}

void				goto_pos(t_env *e, unsigned int pos, char *o)
{
	int val;

	if (ft_strcmp("ra", o) == 0)
		val = get_by_index(e->s_a, pos);
	else
		val = get_by_index(e->s_b, pos);
	if (ft_strcmp("ra", o) == 0)
	{
		if (get_index(e->s_a, val) > stack_size(e->s_a) / 2)
			while (e->s_a->top->data != val)
				rra(e);
		else
			while (e->s_a->top->data != val)
				ra(e);
	}
	else
	{
		if (get_index(e->s_b, val) > stack_size(e->s_b) / 2)
			while (e->s_b->top->data != val)
				rrb(e);
		else
			while (e->s_b->top->data != val)
				rb(e);
	}
}

int					is_more(t_stack *s, int val)
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

unsigned int		find_place(t_stack *s, int val, unsigned int i)
{
	int				cmp;
	t_lst			*list;
	t_lst			*l1;

	list = s->top;
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
	return (0);
}
