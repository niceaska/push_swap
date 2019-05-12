/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:47:59 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:48:24 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			push(t_stack **s, int data)
{
	t_lst *new;

	if (!(new = (t_lst *)malloc(sizeof(t_lst))))
		return ;
	new->data = data;
	if ((*s)->top)
		new->next = (*s)->top;
	else
		new->next = NULL;
	(*s)->top = new;
}

int				pop(t_stack **s)
{
	int		data;
	t_lst	*tmp;

	if (!s || !*s)
		return (0);
	data = (*s)->top->data;
	tmp = (*s)->top;
	(*s)->top = (*s)->top->next;
	free(tmp);
	return (data);
}

t_stack			*init_stack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	stack->top = NULL;
	return (stack);
}

int				is_empty(t_stack *s)
{
	return ((!s->top) ? 1 : 0);
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
