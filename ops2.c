/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:57:19 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:57:23 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_env *e)
{
	rotate_ab(&(e->s_a), &(e->s_b), "rr");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("rr", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	rra(t_env *e)
{
	rev_rotate(&(e->s_a), &(e->s_b), "rra");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("rra", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	rrr(t_env *e)
{
	rev_rotate(&(e->s_a), &(e->s_b), "rrr");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("rrr", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	rrb(t_env *e)
{
	rev_rotate(&(e->s_a), &(e->s_b), "rrb");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("rrb", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}
