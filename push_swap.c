/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:12 by moabe             #+#    #+#             */
/*   Updated: 2025/09/11 18:36:12 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int main()
// {
// 	// argvの引数1個はここではじく
// 	return (0);
// }

// void print_stack_status(Stack *stack, const char *operation_label)
// {
//     printf("\n>>>>>>>>>> After: %s >>>>>>>>>>\n", operation_label);
//     if (stack == NULL || stack->size == 0)
//     {
//         printf("Stack is empty.\n");
//         printf("Size: %ld\n", stack ? stack->size : 0);
//         printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
//         return;
//     }
//     printf("Stack (top to bottom): ");
//     Node *current = stack->top;
//     for (size_t i = 0; i < stack->size; i++)
//     {
//         printf("%d ", current->num);
//         current = current->prev;
//     }
//     printf("\n");
//     printf("Top element: %d\n", stack->top->num);
//     printf("Bottom element: %d\n", stack->bottom->num);
//     printf("Stack size: %ld\n", stack->size);
//     printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
// }