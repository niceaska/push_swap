/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:44:02 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:44:06 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *s)
{
	while (!is_empty(s))
		pop(&s);
	free(s);
}

void	free_tab(char **tab)
{
	unsigned int i;

	i = 0;
	if (tab != NULL)
	{
		while (tab[i])
			if (tab[i] != NULL)
				free(tab[i++]);
		free(tab);
	}
}
