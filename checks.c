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

static int		check_valid(char *s)
{
	long val;

	val = ft_atol(s);
	if (val < 0)
		s++;
	if (!ft_str_is_numeric(s))
		return (0);
	if (val > 2147483647 || val < -2147483648)
		return (0);
	return (1);
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

int		*check_args(char **ag, int ac, t_stack **sa, unsigned int i)
{
	int				*arr;
	int				val;
	unsigned int	size;

	size = 0;
	if (!(arr = (int *)malloc(sizeof(int) * (ac))))
		return (NULL);
	while (--ac)
	{
		if (!check_valid(ag[ac]))
		{
			ft_memdel((void *)&arr);
			return (0);
		}
		val = ft_atoi(ag[ac]);
		if (!check_dup(arr, val, size))
		{
			ft_memdel((void *)&arr);
			return (0);
		}
		arr[size++] = val;
	}
	while (i < size)
		push(sa, arr[i++]);
	return (arr);
}