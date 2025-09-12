/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:12 by moabe             #+#    #+#             */
/*   Updated: 2025/09/12 15:27:31 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void print_stack_status(Stack *stack, const char *label);

int main(int argc, char *argv[])
{
	Stack	*a;
	Stack	*b;
	if (argc != 1)
	{
		a = input_handle(argc, argv);
		print_stack_status(a, "initinal a");
		b = create_stack();
		if (radix_sort(a, b) == 1)
		{
			write(1, "Error\n", 6);
			return (1);
		}
		print_stack_status(a, "sorted a");
	} //freeする？
	return (0);
}

//やること
//同じ数があるとき排除する
//負の数の扱い
//一個だけ馬鹿でかいときの効率
//