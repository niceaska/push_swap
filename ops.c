#include "push-swap.h"

void	pa(t_stack *sa, t_stack *sb)
{
	push_ab(&sa, &sb, "pa");
	ft_putendl("pa");
}

void	pb(t_stack *sa, t_stack *sb)
{
	push_ab(&sa, &sb, "pb");
	ft_putendl("pb");
}

void	ra(t_stack *sa, t_stack *sb)
{
	rotate_ab(&sa, &sb, "ra");
	ft_putendl("ra");
}

void	rb(t_stack *sa, t_stack *sb)
{
	rotate_ab(&sa, &sb, "rb");
	ft_putendl("rb");
}

void	rr(t_stack *sa, t_stack *sb)
{
	rotate_ab(&sa, &sb, "rr");
	ft_putendl("rr");
}

void	rra(t_stack *sa, t_stack *sb)
{
	rev_rotate(&sa, &sb, "rra");
	ft_putendl("rra");
}

void	rrr(t_stack *sa, t_stack *sb)
{
	rev_rotate(&sa, &sb, "rra");
	ft_putendl("rra");
}

void	rrb(t_stack *sa, t_stack *sb)
{
	rev_rotate(&sa, &sb, "rrb");
	ft_putendl("rrb");
}

void	ss(t_stack *sa, t_stack *sb)
{
	swap(&sa, &sb, "ss");
	ft_putendl("ss");
}

void	op_sa(t_stack *sa, t_stack *sb)
{
	swap(&sa, &sb, "sa");
	ft_putendl("sa");
}