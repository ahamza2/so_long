/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handleGame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 09:04:05 by haarab            #+#    #+#             */
/*   Updated: 2023/02/22 17:04:16 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**checkpath(char **str)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == 'P')
			{
				check_p(str, i, j, counter);
			}
			j++;
		}
		i++;
	}
	if (counter != 0)
		checkpath(str);
	return (str);
}

void	map_player(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (str[i][j] == 'P')
				checkpath(str);
			if (str[i][j] == 'E')
				handeldoor(str);
			j++;
		}
		i++;
	}
	if (checkcoin(str) != 0)
	{
		write (1, "ma9darch nakel", 14);
		exit (1);
	}
}

void	handle_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C' &&
				str[i][j] != 'P' && str[i][j] != 'E')
				exit (1);
			if (checkdoor(str) != 1)
				exit (1);
			if (checkpersone(str) != 1)
				exit (1);
			j++;
		}
		i++;
	}
}

char	**handeldoor(char **str)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != 0)
		{
			if (str[i][j] == 'E')
				if (str[i - 1][j] == 'P' || str[i][j - 1] == 'P' ||
					str[i][j + 1] == 'P' || str[i + 1][j] == 'P')
					counter++;
			j++;
		}
		i++;
	}
	if (counter == 0)
	{
		write (1, "ma9dartch nwsal lbab", 20);
		exit (1);
	}
	return (str);
}
