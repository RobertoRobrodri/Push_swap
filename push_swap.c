/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 13:28:44 by robrodri          #+#    #+#             */
/*   Updated: 2021/08/26 14:40:30 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(int i)
{
	write (1, "Error\n", 6);
	exit(i);
}

static	void	ft_error_control(int i, char **argv)
{
	int	pos;

	pos = 0;
	while (argv[i][pos])
	{
		if (!ft_isdigit(argv[i][pos]) && !ft_is_space(argv[i][pos])
				&& !ft_is_sign(argv[i][pos]))
			ft_error(-1);
		if (ft_is_sign(argv[i][pos]))
		{
			if (!ft_isdigit(argv[i][pos + 1]) || !argv[i][pos + 1])
				ft_error(-1);
		}
		if (ft_is_space(argv[i][pos]))
		{
			if (!argv[i][pos + 1])
				ft_error(-1);
		}
		pos++;
	}
}

void	ft_store_args(t_push **stack, int *num)
{
	t_push	*tmp;

	if (*stack == NULL)
		*stack = create_new_node(num);
	else
	{
		tmp = *stack;
		*stack = create_new_node(num);
		(*stack)->next = tmp;
	}
}

static	t_push	*ft_args(int argc, char **argv, t_push *stack_a)
{
	int		*num;
	char	**split;
	int		len;

	while (--argc)
	{
		ft_error_control(argc, argv);
		split = ft_split(argv[argc], ' ');
		len = ft_split_len(split);
		while (len--)
		{
			num = malloc(sizeof(int));
			if (!num)
				return (0);
			*num = ft_atoi_plus(split[len]);
			free(split[len]);
			ft_store_args(&stack_a, num);
		}
		free(split);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_push	*stack_a;
	t_push	*stack_b;

	if (argc < 2)
		exit (-1);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_args(argc, argv, stack_a);
	if (ft_len_lst(stack_a) < 2)
		return (0);
	ft_check_equals(stack_a);
	ft_order(&stack_a, &stack_b);
	return (0);
}
