/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 19:43:06 by haarab            #+#    #+#             */
/*   Updated: 2023/04/30 19:01:27 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exitup(t_vars *vars, int i, int j)
{
	if (vars->move[i][j] == 'P' && vars->move[i - 1][j] == 'E' &&
		checkcoin(vars->move) == 0)
	{
		vars->count++;
		write (1, "YOU WIN\nMOVE IS : ", 19);
		ft_putnbr (vars->count);
		exit(0);
	}
}

void	ft_exitdown(t_vars *vars, int i, int j)
{
	if (vars->move[i][j] == 'P' && vars->move[i + 1][j] == 'E' &&
		checkcoin(vars->move) == 0)
	{
		vars->count++;
		write (1, "YOU WIN\nMOVE IS : ", 19);
		ft_putnbr (vars->count);
		exit(0);
	}
}

void	ft_exitright(t_vars *vars, int i, int j)
{
	if (vars->move[i][j] == 'P' && vars->move[i][j + 1] == 'E' &&
		checkcoin(vars->move) == 0)
	{
		vars->count++;
		write (1, "YOU WIN\nMOVE IS : ", 19);
		ft_putnbr (vars->count);
		exit(0);
	}
}

void	ft_exitleft(t_vars *vars, int i, int j)
{
	if (vars->move[i][j] == 'P' && vars->move[i][j - 1] == 'E' &&
		checkcoin(vars->move) == 0)
	{
		vars->count++;
		write (1, "YOU WIN\nMOVE IS : ", 19);
		ft_putnbr (vars->count);
		exit(0);
	}
}

void	free_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free(str);
}
