/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   short_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/13 09:04:00 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/04 16:44:43 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
Child function of do_short_sort
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	do_short_sort_triple(t_stack **a, t_stack *second,
		t_stack *third)
{
	if ((*a)->content > third->content)
	{
		if (second->content > third->content)
		{
			rotate_a(a, 1);
			swap_a(a, 1);
		}
		else
			rotate_a(a, 1);
	}
	else
		swap_a(a, 1);
}

/**
Sorts 2 arguments
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	do_short_sort_2_numbers(t_stack **a, t_stack *second)
{
	if ((*a)->content > second->content)
		swap_a(a, 1);
}

/**
Sorts numbers up to 3 arguments
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	do_short_sort(t_stack **a, int argc)
{
	t_stack	*second;
	t_stack	*third;

	second = (*a)->next;
	if (argc == 2)
	{
		do_short_sort_2_numbers(a, second);
		return ;
	}
	third = second->next;
	if ((*a)->content < second->content)
	{
		if ((*a)->content < third->content)
		{
			if (second->content > third->content)
			{
				swap_a(a, 1);
				rotate_a(a, 1);
			}
		}
		else
			r_rotate_a(a, 1);
	}
	else
		do_short_sort_triple(a, second, third);
}
