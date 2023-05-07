/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlegame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 14:53:27 by haarab            #+#    #+#             */
/*   Updated: 2023/05/06 14:53:37 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	writeerror(void)
{
	write (2, "Error\n", 6);
	exit (1);
}

char	**checkpath(char **str)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			counter = 0;
			if (str[i][j] == 'P')
			{
				counter = check_p(str, i, j, counter);
			}
			if (counter != 0)
				checkpath(str);
			j++;
		}
		i++;
	}
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
			j++;
		}
		i++;
	}
	handeldoor(str);
	if (checkcoin(str) != 0)
	{
		write (2, "Error\n", 6);
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
				writeerror();
			if (checkdoor(str) != 1)
				writeerror();
			if (checkpersone(str) != 1)
				writeerror();
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
		while (str[i][j])
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
		write (2, "Error\n", 6);
		exit (1);
	}
	return (str);
}
