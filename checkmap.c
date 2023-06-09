/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:25:04 by haarab            #+#    #+#             */
/*   Updated: 2023/05/06 16:05:50 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_line(char **str)
{
	int		j;

	j = 0;
	while (str[0][j] != '\0')
	{
		if (str[0][j] != '1')
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
	read_middlelines(str);
}

void	read_middlelines(char **str)
{
	int		i;
	int		j;
	int		len;
	int		k;

	i = 1;
	len = ft_strlen(str[i]) - 1;
	k = ft_width(str) - 2;
	while (i <= k)
	{
		j = 0;
		while (j <= len)
		{
			if (str[i][0] != '1' || str[i][len] != '1')
			{
				write (2, "Error\n", 6);
				exit (1);
			}
			j++;
		}
		i++;
	}
	read_lastline(str);
}

void	read_lastline(char **str)
{
	int	i;
	int	j;

	i = ft_width(str) - 1;
	j = 0;
	while (str[i][j] != '\0')
	{
		if (str[i][j] != '1')
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		j++;
	}
}

void	check_mapiscorrect(char **str)
{
	int	i;
	int	j;
	int	len;
	int	k;

	i = 0;
	if (checkcoin(str) == 0)
	{
		write (2, "Error\n", 6);
		exit (1);
	}
	len = ft_strlen(str[i]);
	k = ft_width(str) - 1;
	while (i <= k)
	{
		j = 0;
		while (str[i][j] != '\0')
			j++;
		if (j != len)
		{
			write (2, "Error\n", 6);
			exit (1);
		}	
		i++;
	}
}
