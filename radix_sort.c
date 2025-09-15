/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:35:56 by moabe             #+#    #+#             */
/*   Updated: 2025/09/15 18:48:17 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sort(t_Stack *a, t_Stack *b)
{
	size_t	i;
	size_t	digit;
	size_t	size;

	i = 0;
	size = a->size;
	if (size <= 5)
	{
		if (push_swap_smallcase(size, a) == 1)
			return (1);
	}
	else
	{
		digit = binary_digit(a);
		while (i < digit)
		{
			if (bit_shift(a, b, size, i) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

int	binary_digit(t_Stack *a)
{
	size_t	i;
	size_t	size;

	size = a->size;
	i = 0;
	while (size > 1)
	{
		size /= 2;
		i++;
	}
	return (i + 1);
}

int	bit_shift(t_Stack *a, t_Stack *b, int size, size_t i)
{
	int		j;
	long	num;

	j = 0;
	while (j++ < size)
	{
		if (((a->top->index >> i) & 1) == 0)
		{
			num = pop_from_stack(a);
			if (num == (long)INT_MAX + 1 || push_to_stack(b, (int)num) == 1)
				return (1);
			printf("pb\n");
		}
		else
		{
			rotate_stack(a);
			printf("ra\n");
		}
	}
	while (b->size > 0)
	{
		num = pop_from_stack(b);
		if (num == (long)INT_MAX + 1 || push_to_stack(a, (int)num) == 1)
			return (1);
		printf("pa\n");
	}
	return (0);
}

// void	print_stack_status(t_Stack *stack, const char *label) // 消す
// {
// 	t_Node	*current;
// 	size_t	i;

// 	i = 0;
// 	printf("\n--- %s ---\n", label);
// 	if (stack == NULL || stack->size == 0)
// 	{
// 		printf("Stack is empty.\n");
// 		return ;
// 	}
// 	printf("Stack (top to bottom): ");
// 	current = stack->top;
// 	while (i++ < stack->size)
// 	{
// 		printf("%d ", current->num);
// 		current = current->prev;
// 	}
// 	printf("\nSize: %ld\n", stack->size);
// }

// int main(void)
// {
//     Stack *stack_a = create_stack();
//     Stack *stack_b = create_stack();
// 	//　本当はINT_MAXを使用
//     push_to_stack(stack_a, 5);  // 101
//     push_to_stack(stack_a, 2);  // 010
//     push_to_stack(stack_a, 8);  // 1000
//     push_to_stack(stack_a, 0);  // 0
//     push_to_stack(stack_a, 3);  // 011
//     push_to_stack(stack_a, 7);  // 111
// 	push_to_stack(stack_a, INT_MAX);

//     print_stack_status(stack_a, "Before Sort");

//     printf("\n... Executing Radix Sort ...\n");
//     if (radix_sort(stack_a, stack_b) == 0)
//     {
//         printf("Sort completed successfully.\n\n");
//     }
//     else
//     {
//         printf("Sort failed.\n\n");
//     }

//     print_stack_status(stack_a, "After Sort");

//     free_stack(stack_a);
//     free_stack(stack_b);

//     return (0);
// }