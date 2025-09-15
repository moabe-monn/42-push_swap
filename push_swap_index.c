/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:08:32 by moabe             #+#    #+#             */
/*   Updated: 2025/09/15 12:29:00 by moabe            ###   ########.fr       */
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
			else if (string[j] == string[j - 1])
				return (NULL);
			j--;
		}
		i++;
	}
	return (string);
}

int	cd_compression(int *string, size_t size, t_Stack *a)
{
	int		num;
	size_t	i;
	size_t	j;

	i = 0;
	num = 0;
	string = bubble_sort(string, size);
	if (string == NULL)
		return (1);
	while (i++ < a->size)
	{
		j = 0;
		num = a->top->num;
		while (j < a->size)
		{
			if (string[j] == num)
				a->top->index = j;
			j++;
		}
		rotate_stack(a);
	}
	return (0);
}