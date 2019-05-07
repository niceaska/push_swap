#include "push-swap.h"

static int		check_instr(char *line)
{
	if (ft_strcmp(line, "sa") && ft_strcmp(line, "sb")\
		&& ft_strcmp(line, "pa") && ft_strcmp(line, "pb")\
		&& ft_strcmp(line, "ss") && ft_strcmp(line, "ra")\
		&& ft_strcmp(line, "rb") && ft_strcmp(line, "rr")\
		&& ft_strcmp(line, "rra") && ft_strcmp(line, "rrb")\
		&& ft_strcmp(line, "rrr"))
		return (0);
	return (1);
}

static char		**read_instr(int fd, int ret, char **line, char *swp)
{
	char	*parse_line;
	char	*space_line;
	char	**tab;

	parse_line = ft_strnew(1);
	while ((ret = get_next_line(fd, line)) > 0)
	{
		if (!check_instr(*line))
		{
			ft_memdel((void *)line);
			ft_memdel((void *)&parse_line);
			return (NULL);
		}
		space_line = ft_strnew(ft_strlen(*line) + 1);
		ft_strcpy(space_line, *line);
		space_line[ft_strlen(*line)] = ' ';
		swp = parse_line;
		parse_line = ft_strjoin(parse_line, space_line);
		ft_memdel((void *)&space_line);
		ft_memdel((void *)line);
		ft_memdel((void *)&swp);
	}
	tab = (ret == 0) ? ft_strsplit(parse_line, ' ') : NULL;
	ft_memdel((void *)&parse_line);
	return (tab);
}

static int		append_instr(char **tab, t_stack **sa, t_stack **sb)
{
	unsigned int i;

	i = 0;
	while (tab[i])
	{
		if (tab[i][0] == 's')
			swap(sa, sb, tab[i]);
		else if (tab[i][0] == 'p')
			push_ab(sa, sb, tab[i]);
		else if (tab[i][0] == 'r' && (ft_strlen(tab[i]) == 2))
			rotate_ab(sa, sb, tab[i]);
		else if (tab[i][0] == 'r' && (ft_strlen(tab[i]) > 2))
			rev_rotate(sa, sb, tab[i]);
		i++;
	}
	return(is_sorted((*sa), 0, stack_size(*sa)) && is_empty(*sb));
}

static void		free_everything(char *line, t_stack *sa, t_stack *sb, int *arr)
{
	ft_memdel((void *)&line);
	free_stack(sa);
	free_stack(sb);
	free(arr);
}

int				main(int ac, char **ag)
{
	t_stack		*sa;
	t_stack		*sb;
	int			*arr;
	char		**inst;
	char		*line;

	sa = NULL;
	sb = NULL;
	if (ac > 1)
	{
		sa = init_stack();
		sb = init_stack();
		if (!(arr = check_args(ag, ac, &sa, 0)))
			print_error(sa, sb);
		if ((inst = read_instr(0, 0, &line, NULL)) == NULL)
		{
			ft_memdel((void *)&arr);
			print_error(sa, sb);
		}
		(append_instr(inst, &sa, &sb) ? write(1, "OK\n", 3) : write(1, "KO\n", 3));
		free_tab(inst);
		free_everything(line, sa, sb, arr);
	}
}