/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rra_rrb_rrr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/13 08:29:09 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/04 16:43:07 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

/**
 * Shift down all elements of stack a by 1.
 * The first element becomes the last one.
 * @param[in] a stack a
 * @return none
 */
void	r_rotate_a(t_stack **a, int print)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (*a && (*a)->next)
	{
		temp = *a;
		temp_2 = temp;
		while (temp->next)
		{
			temp = temp->next;
			if (temp->next != NULL)
				temp_2 = temp;
		}
		temp->next = *a;
		temp_2->next = NULL;
		*a = temp;
		if (print == 1)
			write(1, "rra\n", 4);
	}
}

/**
 * Shift down all elements of stack b by 1.
 * The first element becomes the last one.
 * @param[in] b stack b
 * @return none
 */
void	r_rotate_b(t_stack **b, int print)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if (*b && (*b)->next)
	{
		temp = *b;
		temp_2 = temp;
		while (temp->next)
		{
			temp = temp->next;
			if (temp->next != NULL)
				temp_2 = temp;
		}
		temp->next = *b;
		temp_2->next = NULL;
		*b = temp;
		if (print == 1)
			write(1, "rrb\n", 4);
	}
}

/**
 * Child function of r_rotate_rr
 * @param[in] a stack a
 * @param[in] b stack b
 * @param[in] temp temporary variable
 * @param[in] temp_2 temporary variable
 * @return none
 */
static void	rrr(t_stack **a, t_stack **b, t_stack *temp, t_stack *temp_2)
{
	temp = *a;
	temp_2 = temp;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next != NULL)
			temp_2 = temp;
	}
	temp->next = *a;
	temp_2->next = NULL;
	*a = temp;
	temp = *b;
	temp_2 = temp;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->next != NULL)
			temp_2 = temp;
	}
	temp->next = *b;
	temp_2->next = NULL;
	*b = temp;
}

/**
 * Combination of r_rotate_a and r_rotate_b
 * @param[in] a stack a
 * @param[in] b stack b
 * @return none
 */
void	r_rotate_rr(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;
	t_stack	*temp_2;

	if ((*a && (*a)->next) && (*b && (*b)->next))
	{
		temp = NULL;
		temp_2 = NULL;
		rrr(a, b, temp, temp_2);
		if (print == 1)
			write(1, "rrr\n", 4);
	}
}
