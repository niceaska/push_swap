#include "push-swap.h"

int	main(int ac, char **ag)
{
	int *arr;
	t_stack *sa = init_stack();
	t_stack *sb = init_stack();
	if (!(arr = check_args(ag, ac, &sa, 0)))
		print_error(sa, sb);
	


	mainsort(sa, sb, arr, ac -1);
	free_stack(sa);
	free_stack(sb);
	free(arr);
}