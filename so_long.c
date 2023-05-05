/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:13:57 by haarab            #+#    #+#             */
/*   Updated: 2023/05/05 17:13:56 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get(char *str)
{
	int		fd;
	int		i;
	char	*s;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		exit(1);
	while (1)
	{
		s = get_next_line (fd);
		if (s == NULL)
			break ;
		i++;
		free(s);
	}
	close(fd);
	return (i);
}

int	check_line(char **map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		i++;
	}
	if (i > 28)
	{
		write (1, "mapislarg\n", 10);
		exit (0);
	}
	return (i);
}

char	**map(t_vars *vars, char *f)
{
	int		fd;
	int		i;

	i = 0;
	fd = open(f, O_RDONLY);
	if (fd < 0)
		exit(1);
	vars->move = malloc((ft_get(f)) * sizeof(char *) + 1);
	if (!vars->move)
		return (NULL);
	while (1)
	{
		vars->move[i] = get_next_line(fd);
		if (vars->move[i] == NULL && i == 0)
			writeerror();
		if (vars->move[i] == NULL)
			break ;
		i++;
	}
	vars->move[i] = 0;
	close(fd);
	return (vars->move);
}

int	check_av(char *str)
{
	if (str[ft_strlen(str) - 1] == 'r' && str[ft_strlen(str) - 2] == 'e'
		&& str[ft_strlen(str) - 3] == 'b' && str[ft_strlen(str) - 4] == '.')
	{
		return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	**s;
	int		n;
	int		len;

	if (ac != 2)
		return (0);
	s = map(&vars, av[1]);
	if (check_av(av[1]) == 0)
		writeerror();
	check_mapiscorrect(s);
	n = ft_width(s);
	len = ft_height(s[0]);
	read_line(s);
	handle_map(s);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, len * 50, n * 50, "game");
	map_player(s);
	mlx_key_hook(vars.win, key_hook, &vars);
	free_malloc (s);
	s = map(&vars, av[1]);
	ft_image(&vars);
	mlx_hook(vars.win, 17, 0, closeee, NULL);
	mlx_loop(vars.mlx);
	return (0);
}
