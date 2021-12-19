/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:21:35 by rlachau           #+#    #+#             */
/*   Updated: 2021/12/14 15:03:37 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_window(t_mlx_data *g)
{
	end_game(g);
	return (1);
}

void	init_game(t_mlx_data *g)
{
	char	*line;
	int		i;
	int		y;

	y = -1;
	while (g->layout[++y])
	{
		i = -1;
		line = g->layout[y];
		while (line[++i])
		{
			if (line[i] == 'C' || line[i] == 'P')
				ft_put_image('0', i * IMG_SIZE, y * IMG_SIZE, g);
			ft_put_image(line[i], i * IMG_SIZE, y * IMG_SIZE, g);
		}
	}
}

void	ft_put_image(char c, int x, int y, t_mlx_data *g)
{
	void	*img_ptr;

	if (c == '0')
		img_ptr = g->f;
	else if (c == '1')
		img_ptr = g->w;
	else if (c == 'P')
	{
		g->player.x = x;
		g->player.y = y;
		img_ptr = g->p;
	}
	else if (c == 'C')
		img_ptr = g->c;
	else
		img_ptr = g->e;
	mlx_put_image_to_window(g->mlx_ptr, g->wn, img_ptr, x, y);
}

void	set_zero(t_mlx_data *g)
{
	g->char_count.c = 0;
	g->char_count.e = 0;
	g->char_count.p = 0;
}

void	set_data(int x, int y, t_mlx_data *g)
{
	g->wn_x = (x - 1) * IMG_SIZE;
	g->wn_y = y * IMG_SIZE;
	g->moves = 0;
	g->player.coins = 0;
}
