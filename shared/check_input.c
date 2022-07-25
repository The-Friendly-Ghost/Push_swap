/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_input.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cpost <cpost@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 14:37:56 by cpost         #+#    #+#                 */
/*   Updated: 2022/07/14 13:28:34 by cpost         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

/**
 * Checks if all the arguments are integers
 * @param[in] nptr A string which contains an argument which was inputted
 * on the command line.
 * @param[in] numbers Integer struct which contain all arguments.
 * @return Nothing (or exit if an error is found).
 */
static void	check_if_integer(const char *nptr, int *numbers)
{
	int	i;

	i = 0;
	if (!nptr)
	{
		ft_printf("Error\n");
		free(numbers);
		exit (1);
	}
	if (nptr[i] == '-')
		i++;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
		{
			ft_printf("Error\n");
			free(numbers);
			exit (1);
		}
		i++;
	}
}

/**
 * Child function of ft_atoi_ps. Converts the string to a integer and does
 * some additional checks to make sure the string is an integer.
 * @param[in] ptr a string which contains an argument which was inputted
 * on the command line.
 * @param[in] c 1 ptr is positive or -1 if ptr is negative.
 * @return int (or exit program if error is found).
 */
static int	ft_getnumber_ps(const char *ptr, int c, int *numbers)
{
	long		num;
	int			length;

	num = 0;
	length = 0;
	while (*ptr)
	{
		num = (*ptr - 48) + (num * 10);
		ptr++;
		length++;
		if (((*ptr < '0' || *ptr > '9') || length >= 11) && *ptr)
		{
			ft_printf("Error\n");
			free(numbers);
			exit (1);
		}
	}
	num *= c;
	if (num < INT_MIN || num > INT_MAX)
	{
		ft_printf("Error\n");
		free(numbers);
		exit (1);
	}
	return (num);
}

/**
 * Converts a string '*nptr' to an integer.
 * @param[in] nptr a string which contains an argument which was inputted
 * on the command line.
 * @return int (or exit program if error is found).
 */
static int	ft_atoi_ps(const char *nptr, int *numbers)
{
	int	i;
	int	c;

	i = 0;
	c = 1;
	if (nptr[i] == '-')
	{
		c = -c;
		i++;
	}
	if (nptr[i] < '0' || nptr[i] > '9')
	{
		ft_printf("Error\n");
		free(numbers);
		exit (1);
	}
	return (ft_getnumber_ps(nptr + i, c, numbers));
}

/**
 * Checks if integer 'index' already exits in the 'numbers' array (and therefore
 * is a duplicate).
 * @param[in] numbers the array with all the inputted numbers in it
 * @param[in] index the index of the current integer to check
 * @return nothing if no duplicate found. Free and exit if duplicate is found.
 */
static void	check_duplicate(int *numbers, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (numbers[i] == numbers[index])
		{
			ft_printf("Error\n");
			free(numbers);
			exit (1);
		}
		i++;
	}
}

/**
 * Parses the input from the command line. Uses atoi to convert the string
 * to a integer and then checks if there are duplicate integers.
 * @param[in] argc the amount of arguments - 1 (minus program name)
 * @param[in] argv an array of arguments
 * @return int (or exit program if error is found).
 */
int	*parse_input(int argc, char **argv)
{
	int	i;
	int	*numbers;

	if (argc <= 0)
		return (NULL);
	numbers = ft_calloc(argc, sizeof(int));
	if (!numbers)
		return (NULL);
	i = 0;
	while (i < argc)
	{
		check_if_integer(argv[i + 1], numbers);
		numbers[i] = ft_atoi_ps(argv[i + 1], numbers);
		check_duplicate(numbers, i);
		i++;
	}
	return (numbers);
}
