/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:18 by moabe             #+#    #+#             */
/*   Updated: 2025/09/12 14:29:04 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Stack* create_stack(void)
{
	Stack *stack;

	stack = (Stack *)malloc(sizeof(Stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}


int	push_to_stack(Stack *stack, unsigned int number)
{
	Node	*newnode;
	
	newnode = (Node *)malloc(sizeof(Node));
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


long	pop_from_stack(Stack* stack)
{
	int		ret;
	Node	*old_top;

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

int rotate_stack(Stack* stack)
{
	if (stack == NULL || stack->top == NULL)
		return (1);
	else if (stack->size == 1)
		return (0);
	stack->top = stack->top->prev;
	stack->bottom = stack->bottom->prev;
	return (0);
}

void free_stack(Stack *stack)
{
    if (stack == NULL)
        return;
    if (stack->top != NULL)
    {
        Node *current = stack->top;
        Node *temp;
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