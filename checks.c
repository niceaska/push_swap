/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgigi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 13:43:04 by lgigi             #+#    #+#             */
/*   Updated: 2019/05/11 13:43:09 by lgigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long		ft_atol(const char *str)
{
	unsigned long	res;
	long			sign;
	char			*s;
	unsigned long	cutoff;

	res = 0;
	s = (char *)str;
	while (*s == ' ' || *s == '\t' || *s == '\n' \
			|| *s == '\r' || *s == '\v' || *s == '\f')
		s++;
	cutoff = 922337203685477580L;
	sign = (*s == '-') ? -1 : 1;
	s += (*s == '-' || *s == '+') ? 1 : 0;
	while (*s >= '0' && *s <= '9')
	{
		if (res >= cutoff || (res == cutoff && (((*s - '0') > 7 && sign == 1) \
						|| ((*s - '0') > 8 && sign == -1))))
		{
			res = (sign == -1) ? -9223372036854775808U : 9223372036854775807L;
			return ((long)res);
		}
		res = res * 10 + *s - '0';
		s++;
	}
	return ((long)res * sign);
}

static int		check_dup(int *arr, int v, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == v)
			return (0);
		i++;
	}
	return (1);
}

static int		check_all(char *str, int *arr, unsigned int i)
{
	long val;

	val = ft_atol(str);
	if ((val >= 0 && !ft_str_is_numeric(str)) \
		|| (val < 0 && !ft_str_is_numeric(str + 1)))
		return (0);
	if (val > 2147483647 || val < -2147483648)
		return (0);
	if (!check_dup(arr, val, i))
		return (0);
	return (1);
}

static int		check_valid(char *s, int *arr, unsigned int size)
{
	long			val;
	unsigned int	i;
	char			**str;

	i = 0;
	str = NULL;
	if (!(str = ft_strsplit(s, ' ')))
		return (0);
	while (str[i])
	{
		val = ft_atol(str[i]);
		if (!check_all(str[i], arr, i + size))
		{
			free_tab(str);
			return (0);
		}
		arr[size + i++] = val;
	}
	free_tab(str);
	return (i);
}

int				*check_args(char **ag, int ac, t_stack **sa, unsigned int i)
{
	int		*arr;
	int		s;
	int		ret;

	s = ac;
	arr = NULL;
	while (--s)
		i += (unsigned int)ft_strlen(ag[s]);
	if (!(arr = (int *)malloc(sizeof(int) * i)))
		return (0);
	i = 0;
	s = 1;
	while (s < ac)
	{
		if (!(ret = check_valid(ag[s], arr, i)))
		{
			ft_memdel((void *)&arr);
			return (0);
		}
		s++;
		i += ret;
	}
	while (i--)
		push(sa, arr[i]);
	return (arr);
}
