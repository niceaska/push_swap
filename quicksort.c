#include "push-swap.h"

static int		find_pivot(int *arr, int bot, int top)
{
	int		mid;
	int		swp;

	mid = (bot + top) / 2;
	if (arr[mid] > arr[bot])
	{
		swp = arr[mid];
		arr[mid] = arr[bot];
		arr[bot] = swp;
	}
	if (arr[top] > arr[bot])
	{
		swp = arr[top];
		arr[top] = arr[bot];
		arr[bot] = swp;
	}
	if (arr[top] > arr[mid])
	{
		swp = arr[top];
		arr[top] = arr[mid];
		arr[mid] = swp;
	}
	return (arr[top]);
}

static int		part(int *arr, int bot, int top) 
{ 
	int				pivot;
	int				swp;
	unsigned int	i;
	unsigned int	j;
	
	pivot = find_pivot(arr, bot, top);
	i = (bot - 1);
	j = bot;
	while (j < top) 
	{  
		if (arr[j] >= pivot) 
		{ 
			i++;
			swp = arr[i];
			arr[i] = arr[j];
			arr[j] = swp;
		} 
		j++;
	} 
	swp = arr[i + 1];
	arr[i + 1] = arr[top];
	arr[top] = swp;
	return (i + 1); 
} 

void			ft_quicksort(int *arr, int bot, int top) 
{ 
	int p;

	if (bot >= top || top <= bot) 
		return ;
	p = part(arr, bot, top); 
	ft_quicksort(arr, bot, p - 1); 
	ft_quicksort(arr, p + 1, top); 
} 