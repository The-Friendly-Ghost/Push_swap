/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_middle.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/13 13:19:59 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/08 11:07:37 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

/**
Sorts numbers with 4 or 5 arguments
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	do_middle_sort(t_stack **a, t_stack **b, int argc)
{
	int	temp_argc;

	temp_argc = argc;
	put_smallest_on_top_a(a, argc);
	if (check_sorted(a))
		return ;
	push_a_to_b(a, b, 1);
	if (argc == 5)
	{
		argc--;
		put_smallest_on_top_a(a, argc);
		if (check_sorted(a))
		{
			push_b_to_a(b, a, 1);
			return ;
		}
		else
			push_a_to_b(a, b, 1);
	}
	do_short_sort(a, argc);
	if (temp_argc == 5)
		push_b_to_a(b, a, 1);
	push_b_to_a(b, a, 1);
}
