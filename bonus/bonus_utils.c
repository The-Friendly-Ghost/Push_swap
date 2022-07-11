/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/07/04 15:32:31 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/11 16:34:53 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

int	check_rd(int rd, char *buffer)
{
	if (rd == 0 && buffer[0] == '\0')
	{
		free(buffer);
		return (1);
	}
	return (0);
}

void	print_error_and_exit(char *command, t_stack **a, t_stack **b)
{
	ft_printf("Error\n");
	free_stacks(a, b);
	if (command)
		free(command);
	exit (1);
}
