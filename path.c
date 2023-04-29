/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:00:16 by haarab            #+#    #+#             */
/*   Updated: 2023/02/22 15:20:32 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	path_up(char **str, int i, int j, int counter)
{
	if (str[i - 1][j] == 'C' || str[i - 1][j] == '0')
	{
		str[i - 1][j] = 'P';
		counter++;
	}
	return (counter);
}

int	path_left(char **str, int i, int j, int counter)
{
	if (str[i][j - 1] == 'C' || str[i][j - 1] == '0')
	{
		str[i][j - 1] = 'P';
		counter++;
	}
	return (counter);
}

int	path_right(char **str, int i, int j, int counter)
{
	if (str[i][j + 1] == 'C' || str[i][j + 1] == '0')
	{
		str[i][j + 1] = 'P';
		counter++;
	}
	return (counter);
}

int	path_down(char **str, int i, int j, int counter)
{
	if (str[i + 1][j] == 'C' || str[i + 1][j] == '0')
	{
		str[i + 1][j] = 'P';
		counter++;
	}
	return (counter);
}

int	check_p(char **str, int i, int j, int counter)
{
	if (str[i][j] == 'P')
	{
		if (str[i - 1][j] == 'C' || str[i - 1][j] == '0')
			path_up(str, i, j, counter);
		if (str[i][j - 1] == 'C' || str[i][j - 1] == '0')
			path_left(str, i, j, counter);
		if (str[i][j + 1] == 'C' || str[i][j + 1] == '0')
			path_right(str, i, j, counter);
		if (str[i + 1][j] == 'C' || str[i + 1][j] == '0')
			path_down(str, i, j, counter);
	}
	return (counter);
}
