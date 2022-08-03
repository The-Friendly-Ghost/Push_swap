/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_bonus.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/27 14:40:22 by cpost         #+#    #+#                 */
/*   Updated: 2022/08/03 17:18:16 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>

static void	execute_command(char *command, t_stack **a, t_stack **b)
{
	if (ft_strncmp(command, "sa\n", 4) == 0)
		swap_a(a, 0);
	else if (ft_strncmp(command, "sb\n", 4) == 0)
		swap_b(b, 0);
	else if (ft_strncmp(command, "ss\n", 4) == 0)
		swap_ss(a, b, 0);
	else if (ft_strncmp(command, "pb\n", 4) == 0)
		push_a_to_b(a, b, 0);
	else if (ft_strncmp(command, "pa\n", 4) == 0)
		push_b_to_a(b, a, 0);
	else if (ft_strncmp(command, "rra\n", 5) == 0)
		r_rotate_a(a, 0);
	else if (ft_strncmp(command, "rrb\n", 5) == 0)
		r_rotate_b(b, 0);
	else if (ft_strncmp(command, "rrr\n", 5) == 0)
		r_rotate_rr(a, b, 0);
	else if (ft_strncmp(command, "ra\n", 4) == 0)
		rotate_a(a, 0);
	else if (ft_strncmp(command, "rb\n", 4) == 0)
		rotate_b(b, 0);
	else if (ft_strncmp(command, "rr\n", 4) == 0)
		rotate_rr(a, b, 0);
	else
		print_error_and_exit(command, a, b);
}

static void	free_and_exit(t_stack **a, t_stack **b, char *buf, char t)
{
	char	c;

	c = '0';
	while (c != '\n' && t != '\n')
		read(0, &c, 1);
	print_error_and_exit(buf, a, b);
	exit (1);
}

static char	*get_next_command(t_stack **a, t_stack **b, int rd, int total_rd)
{
	char	*buffer;
	char	c;

	buffer = malloc(sizeof(char) * 6);
	if (!buffer)
		return (NULL);
	buffer[0] = '\0';
	rd = 0;
	total_rd = 0;
	while (1)
	{
		rd = read(0, &c, 1);
		total_rd += rd;
		if (check_rd(rd, buffer) == 1)
			return (NULL);
		if (total_rd > 5 || rd == -1)
			free_and_exit(a, b, buffer, c);
		buffer[total_rd - 1] = c;
		buffer[total_rd] = '\0';
		if (c == '\n')
			break ;
	}
	return (buffer);
}

static void	check_sorted_bonus(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		compare;

	if (*b || !(*a))
	{
		ft_printf("KO\n");
		free_stacks(a, b);
		return ;
	}
	temp = *a;
	compare = temp->content;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->content < compare)
		{
			ft_printf("KO\n");
			free_stacks(a, b);
			return ;
		}
		compare = temp->content;
	}
	ft_printf("OK\n");
	free_stacks(a, b);
	return ;
}

int	main(int argc, char **argv)
{
	int		*numbers;
	t_stack	*a;
	t_stack	*b;
	char	*command;

	b = NULL;
	a = NULL;
	numbers = parse_input(argc - 1, argv);
	if (!numbers)
		exit (1);
	create_stack(&a, numbers, argc - 1);
	free(numbers);
	set_index(&a, argc - 1, 1);
	while (1)
	{
		command = get_next_command(&a, &b, 0, 0);
		if (!command)
			break ;
		execute_command(command, &a, &b);
		free(command);
	}
	check_sorted_bonus(&a, &b);
	return (0);
}
