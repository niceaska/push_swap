/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:45:58 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:46:02 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_env *e)
{
	push_ab(&(e->s_a), &(e->s_b), "pa");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("pa", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	pb(t_env *e)
{
	push_ab(&(e->s_a), &(e->s_b), "pb");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("pb", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	ra(t_env *e)
{
	rotate_ab(&(e->s_a), &(e->s_b), "ra");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("ra", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	rb(t_env *e)
{
	rotate_ab(&(e->s_a), &(e->s_b), "rb");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("rb", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}
