/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sa_sb_ss.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/09 10:54:09 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/04 16:43:57 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include <unistd.h>

/**
 * Swap the first 2 elements at the top of stack a. 
 * Do nothing if there is only one or no elements.
 * @param[in] a stack a
 * @return none
 */
void	swap_a(t_stack **a, int print)
{
	int		temp_content;
	int		temp_index;
	t_stack	*temp;

	if (*a && (*a)->next)
	{
		temp_content = (*a)->content;
		temp_index = (*a)->index;
		temp = (*a)->next;
		(*a)->content = temp->content;
		(*a)->index = temp->index;
		temp->content = temp_content;
		temp->index = temp_index;
		if (print == 1)
			write(1, "sa\n", 3);
	}
}

/**
 * Swap the first 2 elements at the top of stack b. 
 * Do nothing if there is only one or no elements.
 * @param[in] b stack b
 * @return none
 */
void	swap_b(t_stack **b, int print)
{
	int		temp_content;
	int		temp_index;
	t_stack	*temp;

	if (*b && (*b)->next)
	{
		temp_content = (*b)->content;
		temp_index = (*b)->index;
		temp = (*b)->next;
		(*b)->content = temp->content;
		(*b)->index = temp->index;
		temp->content = temp_content;
		temp->index = temp_index;
		if (print == 1)
			write(1, "sb\n", 3);
	}
}

/**
 * Combination of swap_a and swap_b
 * @param[in] a stack a
 * @param[in] b stack b
 * @return none
 */
void	swap_ss(t_stack **a, t_stack **b, int print)
{
	int		temp_content;
	int		temp_index;
	t_stack	*temp;

	if ((*a && (*a)->next) && (*b && (*b)->next))
	{
		temp_content = (*a)->content;
		temp_index = (*a)->index;
		temp = (*a)->next;
		(*a)->content = temp->content;
		(*a)->index = temp->index;
		temp->content = temp_content;
		temp->index = temp_index;
		temp_content = (*b)->content;
		temp_index = (*b)->index;
		temp = (*b)->next;
		(*b)->content = temp->content;
		(*b)->index = temp->index;
		temp->content = temp_content;
		temp->index = temp_index;
		if (print == 1)
			write(1, "ss\n", 3);
	}
}
