/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:02:58 by moabe             #+#    #+#             */
/*   Updated: 2025/09/06 20:19:00 by moabe            ###   ########.fr       */
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

long	ft_atoi_md(char *nptr)
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
	if (!(*nptr >= '0' && *nptr <= '9'))
		return ((long)INT_MAX + 1);
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (!((*nptr >= '0' && *nptr <= '9') || *nptr == 0) || long_edge(num, *nptr - '0') != 1) //確認
			return ((long)INT_MAX + 1);
		num = num * 10 + (*nptr++ - '0');
	}
	if (*nptr != 0 || (num * sign > (long)INT_MAX) || (num * sign < (long)INT_MIN))
		return ((long)INT_MAX + 1); //intの範囲外はINT_MAX+1を返す
	return (num * sign);
}

size_t	count_numbers(char **string)
{
	size_t	i;

	i = 0;
	while (string[i] != NULL)
	{
		i++;
	}
	return (i);
}
