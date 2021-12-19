/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:35:15 by rlachau           #+#    #+#             */
/*   Updated: 2021/12/18 11:56:20 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	end_game(t_mlx_data *g)
{
	if (g->player.coins == g->char_count.c)
		ft_putstr_fd("You Win!\n", 1);
	else
		ft_putstr_fd("You Loose!\n", 1);
	mlx_destroy_image(g->mlx_ptr, g->p);
	mlx_destroy_image(g->mlx_ptr, g->c);
	mlx_destroy_image(g->mlx_ptr, g->f);
	mlx_destroy_image(g->mlx_ptr, g->w);
	mlx_destroy_image(g->mlx_ptr, g->e);
	mlx_clear_window(g->mlx_ptr, g->wn);
	mlx_destroy_window(g->mlx_ptr, g->wn);
	free(g->mlx_ptr);
	exit(EXIT_FAILURE);
}

void	move_player(t_mlx_data *g, int new_x, int new_y)
{
	const int	old_x = (g->player.x) / IMG_SIZE;
	const int	old_y = (g->player.y) / IMG_SIZE;
	char		direction;

	direction = 'P';
	if (g->layout[new_y][new_x] == 'C')
		g->player.coins += 1;
	if (g->layout[new_y][new_x] == 'E')
	{
		if (g->player.coins == g->char_count.c)
			end_game(g);
	}
	else
	{
		g->layout[old_y][old_x] = '0';
		g->layout[new_y][new_x] = direction;
		g->moves += 1;
		ft_putnbr_fd(g->moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

int	keys_dealer(int key, t_mlx_data *g)
{
	const int	x = (g->player.x) / IMG_SIZE;
	const int	y = (g->player.y) / IMG_SIZE;
	char *str;

	if (key == W && g->layout[y - 1][x] != '1')
		move_player(g, x, y - 1);
	else if (key == A && g->layout[y][x - 1] != '1')
		move_player(g, x - 1, y);
	else if (key == S && g->layout[y + 1][x] != '1')
		move_player(g, x, y + 1);
	else if (key == D && g->layout[y][x + 1] != '1')
		move_player(g, x + 1, y);
	else if (key == ESC)
		end_game(g);
	mlx_clear_window(g->mlx_ptr, g->wn);
	init_game(g);
	str = ft_itoa(g->moves);
	mlx_string_put(g->mlx_ptr, g->wn, 10, 15, 0x00FFFFFF, str);
	free(str);
	return (0);
}

char	**map_alloc(char *map, int y)
{
	int		fd;
	char	*line;
	char	**layout;
	int		i;

	i = 0;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	layout = ft_calloc(sizeof(char *), (y + 1));
	while (line)
	{
		layout[i++] = line;
		line = get_next_line(fd);
	}
	free(line);
	return (layout);
}

int	main(int argc, char **argv)
{
	t_mlx_data	g;
	void		*(*func)(void *, char *, int *, int *);

	if (argc != 2 || !ft_parse_map(argv[1], &g) || g.wn_y == 0)
	{
		write(2, "Error\n", 5);
		return (0);
	}
	g.layout = map_alloc(argv[1], g.wn_x);
	g.mlx_ptr = mlx_init();
	g.wn = mlx_new_window(g.mlx_ptr, g.wn_x, g.wn_y, "42 so_long");
	func = mlx_xpm_file_to_image;
	g.p = func(g.mlx_ptr, "pic/p2_final.xpm", &g.img_wd, &g.img_len);
	g.c = func(g.mlx_ptr, "pic/rl_coin.xpm", &g.img_wd, &g.img_len);
	g.w = func(g.mlx_ptr, "pic/wall_final.xpm", &g.img_wd, &g.img_len);
	g.f = func(g.mlx_ptr, "pic/floor_final.xpm", &g.img_wd, &g.img_len);
	g.e = func(g.mlx_ptr, "pic/rl_exit.xpm", &g.img_wd, &g.img_len);
	mlx_key_hook(g.wn, keys_dealer, &g);
	mlx_hook(g.wn, 17, 0, close_window, &g);
	init_game(&g);
	mlx_loop(g.mlx_ptr);
}
