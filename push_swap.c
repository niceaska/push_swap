#include "push_swap.h"

static t_env	*init_env(void)
{
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->s_a = init_stack();
	e->s_b = init_stack();
	e->flags = 0;
	e->fl_c = 0;
	e->fd = 1;
	return (e);
}

static void		process_file(t_env **e, char *fname)
{
	if (!((*e)->fd = open(fname, O_RDWR | O_CREAT)))
		print_error(NULL, NULL, *e);
	(*e)->fl_c++;
}

static void		free_all(int *arr, t_env *e)
{
	if (e->fd != 1)
		close(e->fd);
	free_stack(e->s_a);
	free_stack(e->s_b);
	free(e);
	free(arr);
}

static void		parse_flags(char **ag, int ac, t_env **e)
{
	int i;

	i = 1;
	while (i < ac && (!ft_isdigit(ag[i][0]) \
		|| !(ft_isdigit(ag[i][1]) && ag[i][0] == '-')))
	{
		if (ag[i][0] == '-' && !ft_isdigit(ag[i][1]))
		{
			if (ag[i][1] == 'v' && ft_atoi(ag[i] + 2) == 0)
				(*e)->flags |= FL_V0;
			else if (ag[i][1] == 'v' && ft_atoi(ag[i] + 2) == 1)
				(*e)->flags |= FL_V1;
			else if (ag[i][1] == 'c')
				(*e)->flags |= FL_C;
			else if (ag[i][1] == 'f')
				process_file(e, ag[i + 1]);
			else
				print_error(NULL, NULL, *e);
			(*e)->fl_c++;
		}
		i++;
	}
}

int				main(int ac, char **ag)
{
	t_env			*e;
	unsigned int	size;
	int				*arr;

	if (ac == 1)
		return (0);
	if (!(e = init_env()))
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