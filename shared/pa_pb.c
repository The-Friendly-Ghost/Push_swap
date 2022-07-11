/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pa_pb.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:54:09 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/04 16:38:39 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

/**
 * Push the top element of stack a to the stack of stack b.
 * @param[in] a stack b
 * @param[in] b stack b
 * @return none
 */
void	push_a_to_b(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp_a;

	if (*a)
	{
		temp_a = *a;
		*a = (*a)->next;
		temp_a->next = *b;
		*b = temp_a;
		if (print == 1)
			write(1, "pb\n", 3);
	}
}

/**
 * Push the top element of stack b to the stack of stack a.
 * @param[in] b stack b
 * @param[in] a stack a
 * @return none
 */
void	push_b_to_a(t_stack **b, t_stack **a, int print)
{
	t_stack	*temp_b;

	if (*b)
	{
		temp_b = *b;
		*b = (*b)->next;
		temp_b->next = *a;
		*a = temp_b;
		if (print == 1)
			write(1, "pa\n", 3);
	}
}
