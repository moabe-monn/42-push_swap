/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:08:32 by moabe             #+#    #+#             */
/*   Updated: 2025/09/13 17:41:32 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

int	*bubble_sort(int *string, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size - 1)
	{
		j = size - 1;
		while (j >= i + 1)
		{
			if (string[j] < string[j - 1])
				ft_swap(&string[j], &string[j - 1]);
			j--;
		}
		i++;
	}
	return (string);
}

void	coordinate_compression(int *string, size_t size, t_Stack *a)
{
	int		num;
	size_t	i;
	size_t	j;

	i = 0;
	string = bubble_sort(string, size);
	while (i++ < a->size)
	{
		j = 0;
		num = a->top->num;
		while (j++ < a->size)
		{
			if (string[j] == num)
			{
				a->top->index = j;
				break ;
			}
		}
		rotate_stack(a);
	}
}