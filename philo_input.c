/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinoh <jinoh@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:33:31 by jinoh             #+#    #+#             */
/*   Updated: 2022/07/22 15:33:32 by jinoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	set_input(char *argv[], t_info *info, int i);

int	handle_input(char *argv[], t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (argv[++i])
	{
		j = -1;
		while (argv[i][++j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
		}
		if (j > 10 || ft_atol(argv[i]) > 2147483647ULL)
			return (1);
	}
	if (set_input(argv, info, i))
		return (1);
	return (0);
}

static int	set_input(char *argv[], t_info *info, int i)
{
	info->NOP = (int) ft_atol(argv[1]);
	if (info->NOP > 200)
		return (1);
	info->TTD = (int) ft_atol(argv[2]);
	info->TTE = (int) ft_atol(argv[3]);
	info->TTS = (int) ft_atol(argv[4]);
	info->kill = 0;
	if (i > 5)
		info->NOT = (int) ft_atol(argv[5]);
	else
		info->NOT = -1;
	info->start = ft_getms();
	if (info->start == 0)
		return (1);
	memset(info->fork, 1, (info->NOP + 2) * sizeof(char));
	return (0);
}
