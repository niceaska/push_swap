#include "push_swap.h"

t_env	*init_env(int flag)
{
	t_env *e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	e->s_a = init_stack();
	e->s_b = init_stack();
	e->flags = 0;
	e->fl_c = 0;
	e->fd = (flag) ? 1 : 0;
	return (e);
}

void		process_file(t_env **e, char *fname, int flag)
{
	if (flag)
	{
		if (!((*e)->fd = open(fname, O_RDWR | O_CREAT, 0644)))
			print_error(NULL, NULL, *e);
	}
	else
	{
		if (!((*e)->fd = open(fname, O_RDONLY)))
			print_error(NULL, NULL, *e);
	}
	(*e)->fl_c++;
}

void		parse_flags(char **ag, int ac, t_env **e)
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
				process_file(e, ag[i + 1], 1);
			else
				print_error(NULL, NULL, *e);
			(*e)->fl_c++;
		}
		i++;
	}
}