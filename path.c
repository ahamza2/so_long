/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:00:16 by haarab            #+#    #+#             */
/*   Updated: 2023/05/05 14:18:12 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_up(char **str, int i, int j)
{
	if (str[i - 1][j] == 'C' || str[i - 1][j] == '0')
	{
		str[i - 1][j] = 'P';
	}
}

void	path_left(char **str, int i, int j)
{
	if (str[i][j - 1] == 'C' || str[i][j - 1] == '0')
	{
		str[i][j - 1] = 'P';
	}
}

void	path_right(char **str, int i, int j)
{
	if (str[i][j + 1] == 'C' || str[i][j + 1] == '0')
	{
		str[i][j + 1] = 'P';
	}
}

void	path_down(char **str, int i, int j)
{
	if (str[i + 1][j] == 'C' || str[i + 1][j] == '0')
	{
		str[i + 1][j] = 'P';
	}
}

int	check_p(char **str, int i, int j)
{
	int	counter;

	counter = 0;
	if (str[i][j] == 'P')
	{
		if (str[i - 1][j] == 'C' || str[i - 1][j] == '0')
		{
			path_up(str, i, j);
			counter++;
		}
		if (str[i][j - 1] == 'C' || str[i][j - 1] == '0')
		{
			path_left(str, i, j);
			counter++;
		}
		if (str[i][j + 1] == 'C' || str[i][j + 1] == '0')
		{
			path_right(str, i, j);
			counter++;
		}
		if (str[i + 1][j] == 'C' || str[i + 1][j] == '0')
		{
			path_down(str, i, j);
			counter++;
		}
	}
	return (counter);
}
