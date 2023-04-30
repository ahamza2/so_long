/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:59:39 by haarab            #+#    #+#             */
/*   Updated: 2023/04/30 15:42:30 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char		buff[BUFFER_SIZE + 1];
	int			red;

	red = 1;
	while (red != 0)
	{
		red = read (fd, buff, BUFFER_SIZE);
		if (red == -1)
		{
			free(str);
			return (NULL);
		}
		buff[red] = '\0';
		str = ft_strjoin(str, buff);
		if (check_new_line(str))
			break ;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*ptr;
	char		*s;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	s = read_file(fd, str);
	ptr = ft_get_line(s);
	str = ft_cut(s);
	return (ptr);
}
