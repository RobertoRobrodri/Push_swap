#include "push_swap.h"

void	ft_error(int i)
{
	write (1, "Error\n", 6);
	exit(i);
}

static	void	ft_error_control(int i, char **argv)
{
	int	pos;
	int	flag;

	pos = 0;
	flag = 0;
	while (argv[i][pos])
	{
		if (!ft_isdigit(argv[i][pos]) && !ft_is_space(argv[i][pos]) 
				&& !ft_is_sign(argv[i][pos]))
				ft_error(0);
		if (ft_isdigit(argv[i][pos]))
			flag = 1;
		pos++;
	}
	if (flag == 0)
		ft_error(0);
}

static void	ft_store_args(t_push **stack_a, int num)
{
	t_push	*tmp;

	if (*stack_a == NULL)
		*stack_a = create_new_node(num);
	else
	{
		tmp = *stack_a;
		*stack_a = create_new_node(num);
		(*stack_a)->next = tmp;
		(*stack_a)->prev = *stack_a;
	}
}

static	t_push	*ft_args(int argc, char **argv, t_push *stack_a)
{
	int		num;
	char	**split;
	int		len;

	while (--argc)
	{
		ft_error_control(argc, argv);
		split = ft_split(argv[argc], ' ');
		len = ft_split_len(split);
		while (len--)
		{
			num = ft_atoi_plus(split[len]);
			free(split[len]);
			ft_store_args(&stack_a, num);
		}
		free(split);
	}
	return(stack_a);
}

int	main (int argc, char **argv)
{
	t_push	*stack_a;
//	t_push	stack_b;

	if (argc < 2)
		ft_error(0);
	stack_a = NULL;
	stack_a = ft_args(argc, argv, stack_a);
	if (ft_len_lst(stack_a) < 2)
		ft_error(0);
	ft_check_equals(stack_a);
	print_list(stack_a);
	reverse_rotate_a(&stack_a);
	printf("-------------------------\n");
	print_list(stack_a);
	system("leaks a.out");
	return(0);
}
