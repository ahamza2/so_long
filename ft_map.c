/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:42:02 by haarab            #+#    #+#             */
/*   Updated: 2023/02/23 11:32:44 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_image(t_vars *vars)
{
	int		img_width;
	int		img_height;

	vars->wall = "./img/hit.xpm";
	vars->person = "./img/persone.xpm";
	vars->walo = "./img/walo.xpm";
	vars->coin = "./img/coin.xpm";
	vars->bab = "./img/bab.xpm";
	vars->door = "./img/open_door.xpm";
	vars->img = mlx_xpm_file_to_image(vars->mlx, \
	vars->wall, &img_width, &img_height);
	vars->ima = mlx_xpm_file_to_image(vars->mlx, \
	vars->person, &img_width, &img_height);
	vars->imb = mlx_xpm_file_to_image(vars->mlx, \
	vars->walo, &img_width, &img_height);
	vars->imc = mlx_xpm_file_to_image(vars->mlx, \
	vars->coin, &img_width, &img_height);
	vars->imd = mlx_xpm_file_to_image(vars->mlx, \
	vars->bab, &img_width, &img_height);
	vars->ime = mlx_xpm_file_to_image(vars->mlx, \
	vars->door, &img_width, &img_height);
	if (vars->img == NULL || vars->ima == NULL || vars->imb == NULL
		||vars->imc == NULL || vars->imd == NULL || vars->ime == NULL)
		exit (1);
	ft_putimage(vars);
}

void	image_e(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imb, j * 50, i * 50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imd, j * 50, i * 50);
}

void	ft_putimage(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->move[i])
	{
		j = 0;
		while (vars->move[i][j] != '\0')
		{
			if (vars->move[i][j] == '1')
				image_wall (vars, i, j);
			if (vars->move[i][j] == '0')
				image_walo (vars, i, j);
			if (vars->move[i][j] == 'P')
				image_persone (vars, i, j);
			if (vars->move[i][j] == 'C')
				image_c(vars, i, j);
			if (vars->move[i][j] == 'E')
				image_e(vars, i, j);
			if (checkcoin(vars->move) == 0 && vars->move[i][j] == 'E')
				image_end(vars, i, j);
			j++;
		}
		i++;
	}
}
