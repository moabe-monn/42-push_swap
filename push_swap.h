/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:16 by moabe             #+#    #+#             */
/*   Updated: 2025/09/11 21:33:56 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h> //いらなかったら消す

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
} Node;

typedef struct s_stack {
	struct s_node	*top;
	struct s_node	*bottom;
	size_t				size;
} Stack;

Stack	*input_handle(int args, char **argv);
int		check_args2(char *string);
int*	convert_into_int(char **string, size_t	size);
Stack	*convert_into_stack(int *string, size_t size);
char	**ft_split(char *s, char c);
size_t	count_numbers(char **string);
long	ft_atoi_md(char *nptr);
Stack*	create_stack(void);
int		push_to_stack(Stack *stack, int number);
long	pop_from_stack(Stack* stack);
int		rotate_stack(Stack* stack);
int		reverse_rotate_stack(Stack* stack);
int		radix_sort(Stack *a, Stack *b);
int		binary_digit(Stack *a);
int 	bit_shift(Stack *a, Stack *b, int size, size_t i);
void	free_stack(Stack *stack);