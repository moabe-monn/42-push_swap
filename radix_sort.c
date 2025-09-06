/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:18 by moabe             #+#    #+#             */
/*   Updated: 2025/09/06 18:26:12 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_to_a(Stack *a, int number)
{
	Node	*newnode;
	
	newnode = (Node *)malloc(sizeof(Node));
	if (newnode == NULL)
		return (1);
	newnode->num = number;
	if (a->top == NULL)
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		a->top = newnode;
		a->bottom = newnode;
		return (0);
	}
	newnode->prev = a->top;
	newnode->next = a->bottom;
	a->top = newnode;
	a->bottom->prev = newnode;
	a->size++;
	return (0);
}

void	push_to_b()
{
	
}

// void	pop_from_a(Stack* stack)
// {
// 	// if (stack == )
// }

void	pop_from_b()
{
	
}