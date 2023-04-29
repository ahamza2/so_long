/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_Player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:58:13 by haarab            #+#    #+#             */
/*   Updated: 2023/03/04 18:15:51 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	click_up(t_vars *vars, int i, int j)
{
	int	k;

	if (vars->move[i][j] == 'P' && vars->move[i - 1][j] != '1' &&
		vars->move[i - 1][j] != 'E')
	{
		if (vars->move[i - 1][j] == 'C')
		{
			vars->move[i][j] = '0';
			vars->move[i - 1][j] = 'P';
			return ;
		}
		k = vars->move[i][j];
		vars->move[i][j] = vars->move[i - 1][j];
		vars->move[i - 1][j] = k;
		// vars->move[i][j] = '0';
		// vars->move[i - 1][j] = 'P';
	}
}

void	click_down(t_vars *vars, int i, int j)
{
	int	k;

	if (vars->move[i][j] == 'P' && vars->move[i + 1][j] != '1' &&
		vars->move[i + 1][j] != 'E')
	{
		if (vars->move[i + 1][j] == 'C')
		{
			vars->move[i][j] = '0';
			vars->move[i + 1][j] = 'P';
			return ;
		}
		k = vars->move[i][j];
		vars->move[i][j] = vars->move[i + 1][j];
		vars->move[i + 1][j] = k;
		// vars->move[i][j] = '0';
		// vars->move[i + 1][j] = 'P';
	}
}

void	click_right(t_vars *vars, int i, int j)
{
	int	k;

	if (vars->move[i][j] == 'P' && vars->move[i][j + 1] != '1' &&
		vars->move[i][j + 1] != 'E')
	{
		if (vars->move[i][j + 1] == 'C')
		{
			vars->move[i][j] = '0';
			vars->move[i][j + 1] = 'P';
			return ;
		}
		k = vars->move[i][j];
		vars->move[i][j] = vars->move[i][j + 1];
		vars->move[i][j + 1] = k;
		// vars->move[i][j] = '0';
		// vars->move[i][j + 1] = 'P';
	}
}

void	click_left(t_vars *vars, int i, int j)
{
	int	k;

	if (vars->move[i][j] == 'P' && vars->move[i][j - 1] != '1' &&
		vars->move[i][j - 1] != 'E')
	{
		if (vars->move[i][j - 1] == 'C')
		{
			vars->move[i][j] = '0';
			vars->move[i][j - 1] = 'P';
			return ;
		}
		k = vars->move[i][j];
		vars->move[i][j] = vars->move[i][j - 1];
		vars->move[i][j - 1] = k;
		// vars->move[i][j] = '0';
		// vars->move[i][j - 1] = 'P';
	}
}

int	closeee(void)
{
	exit(1);
	return (17);
}
