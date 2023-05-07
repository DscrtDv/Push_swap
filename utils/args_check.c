/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args_check.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tcensier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/13 20:13:08 by tcensier      #+#    #+#                 */
/*   Updated: 2023/04/13 20:13:11 by tcensier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/push_swap.h"

static int	is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	find_duplicate(int val, char **argt, int i)
{	
	i++;
	while (argt[i])
	{
		if (ft_atoi(argt[i]) == val)
			return (1);
		i++;
	}
	return (0);
}

void	check_args(int argc, char **argv)
{
	long	temp;
	int		i;
	char	**argt;

	if (argc < 2)
		error_log();
	argt = argv;
	i = 1;
	while (argt[i])
	{
		temp = ft_atoi(argt[i]);
		if (!is_num(argt[i]))
			error_log();
		if (find_duplicate(temp, argt, i))
			error_log();
		if (temp < -2147483648 || temp > 2147483647)
			error_log();
		i++;
	}
}
