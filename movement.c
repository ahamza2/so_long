/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 09:22:41 by haarab            #+#    #+#             */
/*   Updated: 2023/05/05 21:07:29 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == 126 || keycode == 13)
		clickup(vars);
	if (keycode == 125 || keycode == 1)
		clicdown(vars);
	if (keycode == 124 || keycode == 2)
		clicright(vars);
	if (keycode == 123 || keycode == 0)
		clickleft(vars);
	if (keycode == 53 || keycode == 7)
	{
		write (1, "game over\n", 10);
		exit (0);
	}
	ft_putimage(vars);
	return (0);
}

void	clickup(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->move[i])
	{
		j = 0;
		while (vars->move[i][j] != '\0')
		{
			if (vars->move[i][j] == 'P' && vars->move[i - 1][j] == 'E' &&
				checkcoin(vars->move) == 0)
				ft_exitup (vars, i, j);
			if (vars->move[i][j] == 'P' && vars->move[i - 1][j] != '1' &&
				vars->move[i - 1][j] != 'E')
			{
				vars->count++;
				ft_putnbr (vars->count);
				write (1, "\n", 1);
				click_up(vars, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	clicdown(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->move[i])
	{
		j = 0;
		while (vars->move[i][j] != '\0')
		{
			if (vars->move[i][j] == 'P' && vars->move[i + 1][j] == 'E' &&
				checkcoin(vars->move) == 0)
				ft_exitdown (vars, i, j);
			if (vars->move[i][j] == 'P' && vars->move[i + 1][j] != '1' &&
				vars->move[i + 1][j] != 'E')
			{
				vars->count++;
				ft_putnbr (vars->count);
				write (1, "\n", 1);
				click_down(vars, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	clicright(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->move[i])
	{
		j = 0;
		while (vars->move[i][j] != '\0')
		{
			if (vars->move[i][j] == 'P' && vars->move[i][j + 1] == 'E' &&
				checkcoin(vars->move) == 0)
				ft_exitright (vars, i, j);
			if (vars->move[i][j] == 'P' && vars->move[i][j + 1] != '1' &&
				vars->move[i][j + 1] != 'E')
			{
				vars->count++;
				ft_putnbr (vars->count);
				write (1, "\n", 1);
				click_right(vars, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}

void	clickleft(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->move[i])
	{
		j = 0;
		while (vars->move[i][j] != '\0')
		{
			if (vars->move[i][j] == 'P' && vars->move[i][j - 1] == 'E' &&
				checkcoin(vars->move) == 0)
				ft_exitleft (vars, i, j);
			if (vars->move[i][j] == 'P' && vars->move[i][j - 1] != '1' &&
				vars->move[i][j - 1] != 'E')
			{
				vars->count++;
				ft_putnbr (vars->count);
				write (1, "\n", 1);
				click_left(vars, i, j);
				return ;
			}
			j++;
		}
		i++;
	}
}
