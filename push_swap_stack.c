/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:18 by moabe             #+#    #+#             */
/*   Updated: 2025/09/13 15:57:41 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_Stack	*create_stack(void)
{
	t_Stack	*stack;

	stack = (t_Stack *)malloc(sizeof(t_Stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

int	push_to_stack(t_Stack *stack, unsigned int number)
{
	t_Node	*newnode;

	newnode = (t_Node *)malloc(sizeof(t_Node));
	if (newnode == NULL)
		return (1);
	newnode->num = number;
	stack->size++;
	if (stack->top == NULL)
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		stack->top = newnode;
		stack->bottom = newnode;
		return (0);
	}
	newnode->prev = stack->top;
	newnode->next = stack->bottom;
	stack->top = newnode;
	stack->bottom->prev = newnode;
	newnode->prev->next = newnode;
	return (0);
}

long	pop_from_stack(t_Stack *stack)
{
	int		ret;
	t_Node	*old_top;

	if (stack == NULL || stack->top == NULL)
		return ((long)INT_MAX + 1);
	old_top = stack->top;
	ret = old_top->num;
	stack->size--;
	if (stack->size == 0)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = stack->top->prev;
		stack->top->next = stack->bottom;
		stack->bottom->prev = stack->top;
	}
	free(old_top);
	return (ret);
}

int	rotate_stack(t_Stack *stack)
{
	if (stack == NULL || stack->top == NULL)
		return (1);
	else if (stack->size == 1)
		return (0);
	stack->top = stack->top->prev;
	stack->bottom = stack->bottom->prev;
	return (0);
}

void	free_stack(t_Stack *stack)
{
	t_Node	*current;
	t_Node	*temp;

	current = stack->top;
	if (stack == NULL)
		return ;
	if (stack->top != NULL)
	{
		stack->bottom->prev = NULL;
		while (current != NULL)
		{
			temp = current;
			current = current->prev;
			free(temp);
		}
	}
	free(stack);
}