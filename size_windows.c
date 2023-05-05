/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_windows.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 17:01:31 by haarab            #+#    #+#             */
/*   Updated: 2023/05/05 17:11:37 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_width(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	if (i > 28)
	{
		write (1, "width_is_larg\n", 14);
		exit (0);
	}
	return (i);
}

size_t	ft_height(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (i > 51)
	{
		write (1, "hieght_is_larg\n", 15);
		exit (0);
	}
	return (i);
}
