/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 18:02:53 by moabe             #+#    #+#             */
/*   Updated: 2025/09/05 19:15:54 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack *input_handle(char *argv, int args) //stackにできる状態にする
{
	char *string;
	int  *numlist;
	stack a;

	string = argv;
	if (check_args2(s) == 1) // ./push_swap "1 3 6 2 8 6" 対策."1 3 6 2 8 6"をリストにする
		string = ft_split(s, ' ');
	numlist = convert_into_int(string);
	a = convert_into_stack(numlist);
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

int *convert_into_int(char *string) //要素一個ずつint型に変換。int型から外れたり数字じゃないのはエラーでNULL返す
{
	
}

char convert_into_stack(char *string) //全部int型のリストだったらstackにして双方向連結リストを作る
{
	
}
