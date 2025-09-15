/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:02:53 by moabe             #+#    #+#             */
/*   Updated: 2025/09/15 13:53:56 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_status(t_Stack *stack, const char *label);

t_Stack	*input_handle(char **argv) // stackにできる状態にする
{
	char	**string;
	int		*numlist;
	size_t	size;
	t_Stack	*a;

	string = find_string(++argv);
	if (string == NULL)
		return (NULL);
	size = count_numbers(string);
	numlist = convert_into_int(string, size);
	if (numlist == NULL)
		return (NULL);
	a = convert_into_stack(numlist, size);
	if (cd_compression(numlist, size, a) == 1)
		return (NULL);
	double_pointer_free(string);
	free(numlist);
	return (a);
}

int	*convert_into_int(char **string, size_t size)
{
	int		*ret;
	size_t	i;

	ret = (int *)malloc(sizeof(int) * size);
	if (ret == NULL || *string == NULL)
		return (NULL);
	i = 0;
	while (*string != NULL)
	{
		if (ft_atoi_md(*string) > (long)INT_MAX)
		{
			free(ret);
			return (NULL);
		}
		ret[i] = ft_atoi_md(*string);
		string++;
		i++;
	}
	return (ret);
}

char	**find_string(char **string)
{
	char	**ret;
	char	**sub;
	char	*substring;
	size_t	i;
	size_t	j;

	ret = (char **)malloc(sizeof(char *) * (count_length(string) + 1));
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (*string)
	{
		substring = *string;
		sub = ft_split(substring, ' ');
		j = 0;
		if (sub[j] == NULL)
			return (NULL);
		while (sub[j] != NULL)
			ret[i++] = ft_strdup(sub[j++]);
		double_pointer_free(sub);
		string++;
	}
	ret[i] = NULL;
	return (ret);
}

t_Stack	*convert_into_stack(int *string, size_t size)
{
	t_Stack	*a;
	int		i;

	a = (t_Stack *)malloc(sizeof(t_Stack));
	if (a == NULL)
		return (NULL);
	a->top = NULL;
	a->bottom = NULL;
	a->size = 0;
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
// 	if (argc == 2 && check_args2(*argv) == 1)
		// ./push_swap "1 3 6 2 8 6" 対策."1 3 6 2 8 6"をchar型のリストにする
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
