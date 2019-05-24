# push_swap
Second project of algoritmic branch.

The goal of this project is sort stack with following rules:

On start you have only two stacks -◦first one - stack a - contains a random number of either positive or negative numbers without any duplicates.◦Second - stack b - is empty.

You can use only this operations:

sa: swap a- swap the first 2 elements at the top of stacka. Do nothing if thereis only one or no elements).

sb: swap b- swap the first 2 elements at the top of stackb. Do nothing if thereis only one or no elements).

ss: sa and sb at the same time. 

pa: push a- take the first element at the top of b and put it at the top ofa. Donothing if b is empty.

pb: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

ra: rotate a - shift up all elements of stackaby 1. The first element becomesthe last one.

rb: rotate b - shift up all elements of stackbby 1. The first element becomesthe last one.

rr: ra and rb at the same time.

rra: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.

rrb: reverse rotate b- shift down all elements of stackbby 1. The last elementbecomes the first one.

rrr: rra and rrb at the same time.

The goal is to sort the stack with the minimum possible number of operations.

no more than 2-3 operations for 3 integers
no more than 12 operations for 5 integers
no more than 700 operations for 100 integers
no more than 5300 operations for 500 integers

My marks is:

2-3 for 3

9-11 for 5

600-670 for 100

4200-4600 for 500
