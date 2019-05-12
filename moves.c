/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:45:34 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:45:39 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **sa, t_stack **sb, char *ord)
{
	int swp;

	if (sa && *sa && (*sa)->top && (*sa)->top->next && \
		(!ft_strcmp(ord, "sa") || !ft_strcmp(ord, "ss")))
	{
		swp = (*sa)->top->data;
		(*sa)->top->data = (*sa)->top->next->data;
		(*sa)->top->next->data = swp;
	}
	if (sb && *sb && (*sb)->top && (*sb)->top->next && \
		(!ft_strcmp(ord, "sb") || !ft_strcmp(ord, "ss")))
	{
		swp = (*sb)->top->data;
		(*sb)->top->data = (*sb)->top->next->data;
		(*sb)->top->next->data = swp;
	}
}

void	push_ab(t_stack **sa, t_stack **sb, char *ord)
{
	if ((ft_strcmp(ord, "pa") == 0) && !is_empty(*sb))
		push(sa, pop(sb));
	else if ((ft_strcmp(ord, "pb") == 0) && !is_empty(*sa))
		push(sb, pop(sa));
}

void	rotate_ab(t_stack **sa, t_stack **sb, char *ord)
{
	t_lst	*first;
	t_lst	*list;

	if (sa && (*sa)->top && (*sa)->top->next && !is_empty(*sa)\
		&& (!ft_strcmp(ord, "ra") || !ft_strcmp(ord, "rr")))
	{
		first = (*sa)->top;
		(*sa)->top = (*sa)->top->next;
		list = (*sa)->top;
		while (list->next)
			list = list->next;
		list->next = first;
		first->next = NULL;
	}
	if (sb && (*sb)->top && (*sb)->top->next && !is_empty(*sb)\
		&& (!ft_strcmp(ord, "rb") || !ft_strcmp(ord, "rr")))
	{
		first = (*sb)->top;
		(*sb)->top = (*sb)->top->next;
		list = (*sb)->top;
		while (list->next)
			list = list->next;
		list->next = first;
		first->next = NULL;
	}
}

void	rev_rotate(t_stack **sa, t_stack **sb, char *ord)
{
	t_lst	*list;
	t_lst	*last;

	if (sa && (*sa)->top && (*sa)->top->next && \
		(!ft_strcmp(ord, "rra") || !ft_strcmp(ord, "rrr")))
	{
		list = (*sa)->top;
		while (list->next && list->next->next)
			list = list->next;
		last = list->next;
		list->next = NULL;
		last->next = (*sa)->top;
		(*sa)->top = last;
	}
	if (sb && (*sb)->top && (*sb)->top->next && \
		(!ft_strcmp(ord, "rrb") || !ft_strcmp(ord, "rrr")))
	{
		list = (*sb)->top;
		while (list->next && list->next->next)
			list = list->next;
		last = list->next;
		list->next = NULL;
		last->next = (*sb)->top;
		(*sb)->top = last;
	}
}
