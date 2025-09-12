/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:02:53 by moabe             #+#    #+#             */
/*   Updated: 2025/09/12 15:05:48 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void print_stack_status(Stack *stack, const char *label);

Stack *input_handle(int argc, char **argv) //stackにできる状態にする
{
	char **string;
	int  *numlist;
	size_t	size;
	Stack	*a;

	string = ++argv;
	if (argc == 2 && check_args2(*argv) == 1) // ./push_swap "1 3 6 2 8 6" 対策."1 3 6 2 8 6"をchar型のリストにする
	{
		string = ft_split(*argv, ' ');
		if (string == NULL)
			return (NULL);
	}
	size = count_numbers(string);
	numlist = convert_into_int(string, size);
	if (numlist == NULL)
		return (NULL);
	a = convert_into_stack(numlist, size);
	return (a);
}

int check_args2(char *string) //その引数がかっこつきか否か判定
{
	while (*string)
	{
		if (*string == ' ')
			return (1);
		string++;
	}	
	return (0);
}

int *convert_into_int(char **string, size_t	size) //要素一個ずつint型に変換。int型から外れたり数字じゃないのはエラーでNULL返す 
{
	int   *ret;
	size_t i;

	ret = (int *)malloc(sizeof(int) * size);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*string != NULL)
	{
		// printf("%s\n", *string);
		if (ft_atoi_md(*string) > (long)INT_MAX)
		{
			free(ret);
			return (NULL);	
		}
		ret[i] = ft_atoi_md(*string);
		// printf("%zu\n", ret[i]);
		string++;
		i++;
	}
	return (ret);
}

Stack	*convert_into_stack(int *string, size_t size) //全部int型のリストだったらstackにして双方向連結リストを作る
{
	Stack	*a;
	int		i;
	
	a = (Stack *)malloc(sizeof(Stack));
	if (a == NULL)
		return (NULL);
	a->top = NULL;
	a->bottom = NULL; 
	i = (int)size - 1;
	while (0 <= i)
		push_to_stack(a, string[i--]);
	return (a);
}
// int main(int argc, char *argv[])
// {
// 	char **string;
// 	int  *numlist;
// 	size_t	size;

// 	string = ++argv;
// 	if (argc == 2 && check_args2(*argv) == 1) // ./push_swap "1 3 6 2 8 6" 対策."1 3 6 2 8 6"をchar型のリストにする
// 	{
// 		string = ft_split(*argv, ' ');
// 		if (string == NULL)
// 		{
// 			printf("Error\n");
// 			return (1);
// 		}
// 	}
// 	size = count_numbers(string);
// 	numlist = convert_into_int(string, size);
// 	if (numlist == NULL)
// 	{
// 		printf("Error\n");
// 		return (1);
// 	}
// 	size = count_numbers(string);
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		printf("%d\n", *numlist);
// 		numlist++;
// 	}
// 	return (0);
// }


