/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_small.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:27:48 by moabe             #+#    #+#             */
/*   Updated: 2025/09/15 18:49:35 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void print_stack_status(t_Stack *stack, const char *label);

int	push_swap_smallcase(size_t size, t_Stack *a)
{
	if (size == 0)
		return (1);
	else if (size == 1)
		return (0);
	else if (size == 2)
	{
		if (a->top->num > a->bottom->num)
		{
			(void)rotate_stack(a);
			printf("ra\n");
		}
	}
	else if (size == 3)
		push_swap_case3(a);
	else if (size == 4)
		push_swap_case4(a, 0);
	else if (size == 5)
		push_swap_case5(a);
	if (confirm_assemble(a) != 0)
		return (1);
	return (0);
}

void	push_swap_case3(t_Stack *a)
{
	int		i;
	long	num;

	i = 0;
	while (i++ < 3)
	{
		if (confirm_assemble(a) == 0)
			return ;
		rotate_stack(a);
		printf("ra\n");
	}
	num = pop_from_stack(a);
	printf("pb\n");
	rotate_stack(a);
	printf("ra\n");
	push_to_stack(a, (int)num);
	printf("pa\n");
	i = 0;
	while (i++ < 3)
	{
		if (confirm_assemble(a) == 0)
			return ;
		rotate_stack(a);
		printf("ra\n");
	}
}

void	push_swap_case4(t_Stack *a, size_t number)
{
	size_t	i;
	long	min;

	i = 0;
	min = 0;
	while (i++ < a->size)
	{
		if (a->top->index == number)
		{
			min = pop_from_stack(a);
			printf("pb\n");
			break ;
		}
		rotate_stack(a);
		printf("ra\n");
	}
	push_swap_case3(a);
	push_to_stack(a, (int)min);
	printf("pa\n");
}

void	push_swap_case5(t_Stack *a)
{
	size_t	i;
	long	min;

	i = 0;
	min = 0;
	while (i++ < a->size)
	{
		if (a->top->index == 0)
		{
			min = pop_from_stack(a);
			printf("pb\n");
			break ;
		}
		rotate_stack(a);
		printf("ra\n");
	}
	push_swap_case4(a, 1);
	push_to_stack(a, (int)min);
	printf("pa\n");
}

int	confirm_assemble(t_Stack *a)
{
	size_t	i;
	int		number;
	int		flag;

	i = 0;
	flag = 0;
	number = a->top->num;
	rotate_stack(a);
	while (i++ < a->size - 1)
	{
		if (number > a->top->num)
			flag = 1;
		else if (number == a->top->num)
			flag = -1;
		number = a->top->num;
		rotate_stack(a);
	}
	return (flag);
}
