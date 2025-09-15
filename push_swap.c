/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:12 by moabe             #+#    #+#             */
/*   Updated: 2025/09/15 18:50:47 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// void print_stack_status(t_Stack *stack, const char *label);

int	main(int argc, char *argv[])
{
	t_Stack	*a;
	t_Stack	*b;

	(void)argc;
	if (argc != 1)
	{
		a = input_handle(argv);
		if (a == NULL)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		// print_stack_status(a, "initinal a");
		b = create_stack();
		if (radix_sort(a, b) == 1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		// print_stack_status(a, "sorted a");
		free_stack(a);
		free_stack(b);
	}
	return (0);
}

void	double_pointer_free(char **string)
{
	size_t	i;

	if (!string)
		return ;
	i = 0;
	while (string[i] != NULL)
		free(string[i++]);
	free(string);
}

//やること

//norminette
//tester
//int超えたらErrorなのかどうかMandatory見る
//printの関数を消す
//Mandatoryに即してることの確認