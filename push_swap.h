/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moabe < moabe@student.42tokyo.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 17:03:16 by moabe             #+#    #+#             */
/*   Updated: 2025/09/05 18:48:35 by moabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

typedef struct s_node {
	struct s_node	*prev;
	struct s_node	*next;
	int				num;
} node;

typedef struct s_stack {
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
} stack;

