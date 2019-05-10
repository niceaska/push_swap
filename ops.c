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

void	ss(t_env *e)
{
	swap(&(e->s_a), &(e->s_b), "ss");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("ss", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	op_sa(t_env *e)
{
	swap(&(e->s_a), &(e->s_b), "sa");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("sa", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}

void	op_sb(t_env *e)
{
	swap(&(e->s_a), &(e->s_b), "sb");
	(e->flags & FL_C) ? ft_putstr(YEL) : 0;
	ft_putendl_fd("sb", e->fd);
	(e->flags & FL_C) ? ft_putstr(COL) : 0;
	(e->flags & FL_V0) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
}