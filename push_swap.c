#include "push_swap.h"

static void		free_all(int *arr, t_env *e)
{
	if (e->fd != 1)
		close(e->fd);
	free_stack(e->s_a);
	free_stack(e->s_b);
	free(e);
	free(arr);
}

int				main(int ac, char **ag)
{
	t_env			*e;
	unsigned int	size;
	int				*arr;

	if (ac == 1)
		return (0);
	if (!(e = init_env(1)))
		print_error(NULL, NULL, NULL);
	parse_flags(ag, ac, &e);
	if (!(arr = check_args(ag + e->fl_c, ac - e->fl_c, &(e->s_a), 0)))
		print_error(e->s_a, e->s_b, e);
	size = stack_size(e->s_a);
	if (is_sorted(e->s_a, 0, size))
		return (0);
	if (size <= 3)
		sort_tree(e);
	else if (size <= 10)
		sel_sort(e);
	else
		mainsort(e, arr, ac - e->fl_c - 1);
	(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
	free_all(arr, e);
}