/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe <moabe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:02:58 by moabe             #+#    #+#             */
/*   Updated: 2025/09/14 15:18:08 by moabe            ###   ########.fr       */
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
		if (!((*nptr >= '0' && *nptr <= '9') || *nptr == 0)
			|| long_edge(num, *nptr - '0') != 1)
			return ((long)INT_MAX + 1);
		num = num * 10 + (*nptr++ - '0');
	}
	if (*nptr != 0 || (num * sign > (long)INT_MAX)
		|| (num * sign < (long)INT_MIN))
		return ((long)INT_MAX + 1);
	return (num * sign);
}

size_t	count_numbers(char **string)
{
	size_t	i;

	i = 0;
	while (string[i] != NULL)
		i++;
	return (i);
}

size_t	count_length(char **string)
{
	size_t	ret;
	size_t	i;
	char	**sub;

	ret = 0;
	while (*string != NULL)
	{
		sub = ft_split(*string, ' ');
		i = 0;
		while (sub[i++] != NULL)
			ret++;
		double_pointer_free(sub);
		string++;
	}
	return (ret);
}

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	len;
	char	*copy;

	if (src == NULL)
		return (NULL);
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
