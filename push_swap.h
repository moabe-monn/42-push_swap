/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:16 by moabe             #+#    #+#             */
/*   Updated: 2025/09/14 18:26:04 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stddef.h>
#include <stdio.h> //いらなかったら消す
#include <stdlib.h>
#include <unistd.h>

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
	size_t			index;
}					t_Node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	size_t			size;
}					t_Stack;

t_Stack				*input_handle(char **argv);
int					*convert_into_int(char **string, size_t size);
t_Stack				*convert_into_stack(int *string, size_t size);
char				**ft_split(char *s, char c);
size_t				count_numbers(char **string);
long				ft_atoi_md(char *nptr);
t_Stack				*create_stack(void);
int					push_to_stack(t_Stack *stack, int number);
long				pop_from_stack(t_Stack *stack);
int					rotate_stack(t_Stack *stack);
int					reverse_rotate_stack(t_Stack *stack);
int					radix_sort(t_Stack *a, t_Stack *b);
int					binary_digit(t_Stack *a);
int					bit_shift(t_Stack *a, t_Stack *b, int size, size_t i);
void				free_stack(t_Stack *stack);
int					cd_compression(int *string, size_t size, t_Stack *a);
char				**find_string(char **string);
size_t				count_length(char **string);
void				double_pointer_free(char **string);
char				*ft_strdup(const char *src);
int					search_minimum(t_Stack *a);
int					push_swap_smallcase(size_t size, t_Stack *a);
void				push_swap_case3(t_Stack *a);
void				push_swap_case4(t_Stack *a, size_t number);
void				push_swap_case5(t_Stack *a);
int					confirm_assemble(t_Stack *a);
