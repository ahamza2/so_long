/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:14:51 by haarab            #+#    #+#             */
/*   Updated: 2023/05/05 19:15:04 by haarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <mlx.h>
# include "./get_next_line/get_next_line.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*ima;
	void	*imb;
	void	*imc;
	void	*imd;
	void	*ime;
	char	**move;
	char	*wall;
	char	*person;
	char	*nothing;
	char	*coin;
	char	*door;
	char	*open_door;
	int		count;
}	t_vars;

void	ft_putchar(char c);

void	ft_putnbr(int n);

int		checkcoin(char **str);

int		checkpersone(char **str);

int		checkdoor(char **str);

char	**checkpath(char **str);

void	map_player(char **str);

void	handle_map(char **str);

char	**handeldoor(char **str);

void	ft_image(t_vars *vars);

void	image_wall(t_vars *vars, int i, int j);

void	image_nothing(t_vars *vars, int i, int j);

void	image_persone(t_vars *vars, int i, int j);

void	image_c(t_vars *vars, int i, int j);

void	image_end(t_vars *vars, int i, int j);

void	image_e(t_vars *vars, int i, int j);

void	ft_putimage(t_vars *vars);

void	click_up(t_vars *vars, int i, int j);

void	click_down(t_vars *vars, int i, int j);

void	click_right(t_vars *vars, int i, int j);

void	click_left(t_vars *vars, int i, int j);

int		key_hook(int keycode, t_vars *vars);

void	clickup(t_vars *vars);

void	clicdown(t_vars *vars);

void	clicright(t_vars *vars);

void	clickleft(t_vars *vars);

void	path_up(char **str, int i, int j);

void	path_left(char **str, int i, int j);

void	path_right(char **str, int i, int j);

void	path_down(char **str, int i, int j);

int		check_p(char **str, int i, int j, int counter);

int		ft_get(char *str);

int		ft_width(char **map);

char	**map(t_vars *vars, char *f);

void	read_linelkher(char **str);

void	read_line(char **str);

void	read_linelwast(char **str);

void	check_mapiscorrect(char **str);

void	ft_exitup(t_vars *vars, int i, int j);

void	ft_exitdown(t_vars *vars, int i, int j);

void	ft_exitright(t_vars *vars, int i, int j);

void	ft_exitleft(t_vars *vars, int i, int j);

void	free_malloc(char **str);

int		closeee(void);

void	writeerror(void);

size_t	ft_height(const char *str);

#endif
