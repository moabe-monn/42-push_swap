/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:02:58 by moabe             #+#    #+#             */
/*   Updated: 2025/09/05 18:45:51 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	long_edge(long num, int next_digit)
{
	if ((LONG_MAX / 10 < num) || (LONG_MAX / 10 == num && 7 < next_digit))
		return (-1);
	else if ((LONG_MIN / 10 > num)
		|| (LONG_MIN / 10 == num && 8 < next_digit))
		return (0);
	else
		return (1);
}

int	ft_atoi(const char *nptr)
{
	long		num;
	int			sign;

	num = 0;
	sign = 1;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign = 1 - ((*nptr++ == '-') << 1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (long_edge(num * sign, *nptr - '0') != 1) //確認
			return (INT_MAX + 1);
		num = num * 10 + (*nptr++ - '0');
	}
	if ((num * sign > INT_MAX) || (num * sign < INT_MIN))
		return (INT_MAX + 1); //intの範囲外はINT_MAX+1を返す
	return (num * sign);
}
