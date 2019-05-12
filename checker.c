/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:43:28 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:43:35 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (is_sorted((*sa), 0, stack_size(*sa)) && is_empty(*sb));
}

static void		free_everything(char *line, t_env *e, char **inst, int *arr)
{
	free_tab(inst);
	ft_memdel((void *)&line);
	if (e->fd != 0)
		close(e->fd);
	free_stack(e->s_a);
	free_stack(e->s_b);
	free(e);
	free(arr);
}

int				main(int ac, char **ag)
{
	t_env		*e;
	int			*arr;
	char		**inst;
	char		*line;

	if (ac > 1)
	{
		if (!(e = init_env(0)))
			print_error(NULL, NULL, NULL);
		parse_flags(ag, ac, &e);
		if (!(arr = check_args(ag + e->fl_c, ac - e->fl_c, &(e->s_a), 0)))
			print_error(e->s_a, e->s_b, e);
		if ((inst = read_instr(e->fd, 0, &line, NULL)) == NULL)
		{
			ft_memdel((void *)&arr);
			print_error(e->s_a, e->s_b, e);
		}
		(append_instr(inst, &(e->s_a), &(e->s_b)) ?\
				write(1, "OK\n", 3) : write(1, "KO\n", 3));
		free_everything(line, e, inst, arr);
	}
}
