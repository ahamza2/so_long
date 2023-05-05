/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:01:42 by haarab            #+#    #+#             */
/*   Updated: 2023/05/05 19:14:39 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_wall(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, j * 50, i * 50);
}

void	image_nothing(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imb, j * 50, i * 50);
}

void	image_persone(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->ima, j * 50, i * 50);
}

void	image_c(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imb, j * 50, i * 50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imc, j * 50, i * 50);
}

void	image_end(t_vars *vars, int i, int j)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->imb, j * 50, i * 50);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->ime, j * 50, i * 50);
}
