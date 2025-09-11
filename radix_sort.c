/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 16:35:56 by moabe             #+#    #+#             */
/*   Updated: 2025/09/11 21:36:14 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sort(Stack *a, Stack *b)
{
	int i;
	int digit;
	int size;

	i = 0;
	size = a->size;
	digit = binary_digit(a);
	while (i < digit)
	{
		if (bit_shift(a, b, size, i) == 1)
			return (1);
		i++;
	}
	return (0);
}

int	binary_digit(Stack *a)
{
	int 	max;
	size_t 	i;
	Node 	*node;

	max = INT_MIN;
	i = 0;
	node = a->top;
	while (i < a->size)
	{
		if (max < node->num)
			max = node->num;
		node = node->prev;
		i++;
	}
	i = 0;
	while (max > 1)
	{
		max /= 2;
		i++;
	}
	return (i+1);
}

int bit_shift(Stack *a, Stack *b, int size, size_t i)
{
	int j;
	long num;

	j = 0;
	while (j++ < size)
		{
			if ((a->top->num << i) == 1)
			{
				num = pop_from_stack(a);
				if (num == (long)INT_MAX + 1 || push_to_stack(b, (int)num) == 1)
					return (1);
			}
			else
				rotate_stack(a);
		}
	while (b->size > 0)
	{
		num = pop_from_stack(b);
		if (num == (long)INT_MAX + 1 || push_to_stack(a, (int)num) == 1)
			return (1);
	}
	return (0);
}

void print_stack_status(Stack *stack, const char *label) {
    printf("--- %s ---\n", label);
    if (stack == NULL || stack->size == 0) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    Node *current = stack->top;
    for (size_t i = 0; i < stack->size; i++) {
        printf("%d ", current->num);
        current = current->prev;
    }
    printf("\nSize: %ld\n", stack->size);
}

int main(void)
{
    // スタックaと、作業用のスタックbを作成
    Stack *stack_a = create_stack();
    Stack *stack_b = create_stack();

    // --- 計算過程1: ソート前のデータ準備 ---
    // ラディックスソートは負の数に対応していないため、0以上の整数を入れる
    push_to_stack(stack_a, 5);  // 101
    push_to_stack(stack_a, 2);  // 010
    push_to_stack(stack_a, 8);  // 1000
    push_to_stack(stack_a, 0);  // 0
    push_to_stack(stack_a, 3);  // 011
    push_to_stack(stack_a, 7);  // 111
    
    print_stack_status(stack_a, "Before Sort");

    // --- 計算過程2: ソート実行 ---
    printf("\n... Executing Radix Sort ...\n");
    if (radix_sort(stack_a, stack_b) == 0)
    {
        printf("Sort completed successfully.\n\n");
    }
    else
    {
        printf("Sort failed.\n\n");
    }

    // --- 計算過程3: ソート後の結果確認 ---
    print_stack_status(stack_a, "After Sort");

    // メモリ解放
    free_stack(stack_a);
    free_stack(stack_b);

    return 0;
}