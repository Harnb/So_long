/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlachau <rlachau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:31:56 by rlachau           #+#    #+#             */
/*   Updated: 2021/12/18 10:31:30 by rlachau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# define BUFFER_SIZE 1
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define IMG_SIZE 32

typedef struct s_char_count
{
	int	c;
	int	e;
	int	p;
}	t_char_count;

typedef struct s_player
{
	int	x;
	int	y;
	int	coins;
}	t_player;

typedef struct s_mlx_data
{
	void			*p;
	void			*c;
	void			*e;
	void			*w;
	void			*f;
	char			**layout;
	void			*mlx_ptr;
	void			*wn;
	int				wn_x;
	int				wn_y;
	int				moves;
	int				img_wd;
	int				img_len;
	t_char_count	char_count;
	t_player		player;
}	t_mlx_data;

typedef struct s_map_opts
{
	int	x;
	int	y;
}	t_map_opts;

int		close_window(t_mlx_data *g);
void	end_game(t_mlx_data *g);
int		ft_parse_map(char *map, t_mlx_data *g);
void	ft_put_image(char c, int x, int y, t_mlx_data *g);
void	init_game(t_mlx_data *g);
int		max_chr(char *map);
int		max_ln(char *map);
char	*get_next_line(int fd);
char	*gnl_strjoin(char const *s1, char const *s2);
void	set_data(int x, int y, t_mlx_data *g);
void	set_zero(t_mlx_data *g);
char	*gnl_strchr(const char *s, int c);
void	*gnl_calloc(size_t count, size_t size);
void	gnl_bzero(void *s, size_t n);
size_t	gnl_strlen(const char *s);
#endif