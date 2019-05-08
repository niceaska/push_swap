#include "push-swap.h"

static t_env *init_env(void)
{
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->s_a = init_stack();
	e->s_b = init_stack();
	return (e);
}

int		main(int ac, char **ag)
{
	t_env			*e;
	unsigned int	size;
	int				*arr;

	if (ac == 1)
		return (0);
	if (!(e = init_env()))
		print_error(NULL, NULL, NULL);
	if (!(arr = check_args(ag, ac, &(e->s_a), 0)))
		print_error(e->s_a, e->s_b, e);
	size = stack_size(e->s_a);
	if (is_sorted(e->s_a, 0, size))
		return (0);
	if (size <= 3)
		sort_tree(e->s_a, e->s_b);
	else if (size <= 10)
		sel_sort(e->s_a, e->s_b);
	else
		mainsort(e->s_a, e->s_b, arr, ac -1);
	free_stack(e->s_a);
	free_stack(e->s_b);
	free(e);
	free(arr);
}