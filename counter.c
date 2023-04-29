/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:20:27 by haarab            #+#    #+#             */
/*   Updated: 2023/02/24 09:43:22 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkcoin(char **str)
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
			if (str[i][j] == 'C')
			{
				counter++;
			}
			j++;
		}
		i++;
	}
	return (counter);
}

int	checkpersone(char **str)
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
				counter++;
			}
			j++;
		}
		i++;
	}
	return (counter);
}

int	checkdoor(char **str)
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
			if (str[i][j] == 'E')
			{
				counter++;
			}
			j++;
		}
		i++;
	}
	return (counter);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write (1, "-", 1);
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}
