/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:46:42 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:46:45 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		free_all(arr, e);
		return (0);
	}
	if (size <= 3)
		sort_tree(e);
	else if (size <= 10)
		sel_sort(e);
	else
		mainsort(e, arr, size);
	(e->flags & FL_V1) ? print_stack(e->s_a, e->s_b, e->flags) : 0;
	free_all(arr, e);
}
