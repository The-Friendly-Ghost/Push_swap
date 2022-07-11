/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ra_rb_rr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/13 08:15:19 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/04 16:39:23 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

/**
 * Shift up all elements of stack a by 1.
 * The first element becomes the last one.
 * @param[in] a stack a
 * @return none
 */
void	rotate_a(t_stack **a, int print)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (*a && (*a)->next)
	{
		temp = *a;
		*a = (*a)->next;
		temp_2 = *a;
		while (temp_2->next)
			temp_2 = temp_2->next;
		temp_2->next = temp;
		temp->next = NULL;
		if (print == 1)
			write(1, "ra\n", 3);
	}
}

/**
 * Shift up all elements of stack b by 1.
 * The first element becomes the last one.
 * @param[in] b stack b
 * @return none
 */
void	rotate_b(t_stack **b, int print)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (*b && (*b)->next)
	{
		temp = *b;
		*b = (*b)->next;
		temp_2 = *b;
		while (temp_2->next)
			temp_2 = temp_2->next;
		temp_2->next = temp;
		temp->next = NULL;
		if (print == 1)
			write(1, "rb\n", 3);
	}
}

/**
 * Combination of rotate_a and rotate_b
 * @param[in] a stack a
 * @param[in] b stack b
 * @return none
 */
void	rotate_rr(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if ((*a && (*a)->next) && (*b && (*b)->next))
	{
		temp = *a;
		*a = (*a)->next;
		temp_2 = *a;
		while (temp_2->next)
			temp_2 = temp_2->next;
		temp_2->next = temp;
		temp->next = NULL;
		temp = *b;
		*b = (*b)->next;
		temp_2 = *b;
		while (temp_2->next)
			temp_2 = temp_2->next;
		temp_2->next = temp;
		temp->next = NULL;
		if (print == 1)
			write(1, "rr\n", 3);
	}
}
