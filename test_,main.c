#include <stdio.h>
#include "push-swap.h"

int	main(int ac, char **ag)
{
	int *arr;
	t_stack *sa = init_stack();
	t_stack *sb = init_stack();
	if (!(arr = check_args(ag, ac, &sa, 0)))
		print_error(sa, sb);
	


	mainsort(sa, sb, arr, ac -1);
//minmax_sort(sa, sb, arr, ac -1);

	//ins_sort(sa, sb);
	//printf("%d\n", ac - 1);
//print_stack(sa, sb);
	free_stack(sa);
	free_stack(sb);
	free(arr);
	
//	swap(&sa, &sb, "sa");
	//push_ab(&sa, &sb, "pb");

	//push_ab(&sa, &sb, "pb");
	//push_ab(&sa, &sb, "pb");
	//rotate_ab(&sa, &sb, "rr");
//	rev_rotate(&sa, &sb, "rrr");
	//rev_rotate(&sa, &sb, "rrb");
	//swap(&sa, &sb, "sa");
//	push_ab(&sa, &sb, "pa");
//	push_ab(&sa, &sb, "pa");
//	push_ab(&sa, &sb, "pa");


	/*
	int i = 40;
	t_stack *s = init_stack();
	
	printf("is empty? %d\n", is_empty(s));

	while (i)
	{
	}
		printf("is empty? %d\n", is_empty(s));
	printf("is sorted? %d\n", is_sorted(s));
	printf("size? %u\n", stack_size(s));

	while (i++ < 40)
		printf("%d\n", pop(&s));
	printf("is empty? %d\n", is_empty(s));
	*/
}