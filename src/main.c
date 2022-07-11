/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/07 15:10:48 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/11 14:56:13 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int		*numbers;
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	numbers = parse_input(argc - 1, argv);
	if (!numbers)
		return (1);
	create_stack(&a, numbers, argc - 1);
	free(numbers);
	set_index(&a, argc - 1, 1);
	if (argc - 1 <= 3 && argc - 1 > 1)
		do_short_sort(&a, argc - 1);
	if (argc - 1 == 4 || argc - 1 == 5)
		do_middle_sort(&a, &b, argc - 1);
	if (argc - 1 >= 6)
		do_long_sort(&a, &b);
	free_stacks(&a, &b);
	return (0);
}
