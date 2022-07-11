/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_long.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/16 11:43:04 by cpost         #+#    #+#                 */
/*   Updated: 2022/06/24 15:33:06 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
Sorts when the amount of arguments is above 5
 * @param[in] a The address of stack a
 * @param[in] b The address of stack b
 * @return none
 */
void	do_long_sort(t_stack **a, t_stack **b)
{
	int	low_index;
	int	high_index;
	int	elements_a;

	if (check_sorted(a))
		return ;
	low_index = 1;
	high_index = get_middle_index(a, low_index);
	while (count_elements(a) >= 6)
	{
		presort_elements_to_b(a, b, low_index, high_index);
		low_index = high_index + 1;
		high_index = get_middle_index(a, low_index);
	}
	elements_a = count_elements(a);
	if (elements_a == 2 || elements_a == 3)
		do_short_sort(a, elements_a);
	if (elements_a == 4 || elements_a == 5)
		do_middle_sort(a, b, elements_a);
	sort_all(a, b);
}
