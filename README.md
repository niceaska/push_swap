# push_swap
Second project of algoritmic branch.

The goal of this project is sort stack with following rules:

On start you have only two stacks - first one - stack a - contains a random number of either positive or negative numbers without any duplicates. Second - stack b - is empty.

You can use only this operations:
<p>sa: swap a- swap the first 2 elements at the top of stacka. Do nothing if thereis only one or no elements).<br>
sb: swap b- swap the first 2 elements at the top of stackb. Do nothing if thereis only one or no elements).<br>
ss: sa and sb at the same time. <br>
pa: push a- take the first element at the top of b and put it at the top ofa. Do nothing if b is empty.<br>
pb: push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.<br>
ra: rotate a - shift up all elements of stack a by 1. The first element becomesthe last one<br>
rb: rotate b - shift up all elements of stack b by 1. The first element becomesthe last one.<br>
rr: ra and rb at the same time<br>
rra: reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.<br>
rrb: reverse rotate b- shift down all elements of stack b by 1. The last element becomes the first one.<br>
rrr: rra and rrb at the same time.</p>

The goal is to sort the stack with the minimum possible number of operations.
<p>no more than 2-3 operations for 3 integers<br>
no more than 12 operations for 5 integers<br>
no more than 700 operations for 100 integers<br>
no more than 5300 operations for 500 integers</p>

<p style="font-size: 14px">My marks is:<br>
2-3 for 3<br>
9-11 for 5<br>
600-670 for 100<br>
4200-4600 for 500</p>
