/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:49:15 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:49:19 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

unsigned int	get_index(t_stack *sa, int val)
{
	t_lst			*list;
	unsigned int	i;

	i = 0;
	list = sa->top;
	while (list->data != val)
	{
		i++;
		list = list->next;
	}
	return (i);
}

int				is_sorted(t_stack *s, unsigned int start, unsigned int end)
{
	t_lst			*list;
	unsigned int	i;

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

int				find_max(t_stack *s, int excl, int flag)
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

int				find_min(t_stack *s, int excl, int flag)
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

int				find_bottom(t_stack *s)
{
	t_lst *list;

	list = s->top;
	while (list->next)
		list = list->next;
	return (list->data);
}
