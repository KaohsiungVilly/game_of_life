/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_of_life.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvillena <pvillena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 10:59:18 by pvillena          #+#    #+#             */
/*   Updated: 2022/04/25 18:01:56 by pvillena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_OF_LIFE_H
# define GAME_OF_LIFE_H
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <strings.h>
# include <string.h>
# include <limits.h>
# include "minilibx_macos/mlx.h"
# define BUFFER_SIZE 100

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_scrn {
	int	width;
	int	height;
}				t_scrn;

typedef struct	s_vars {
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_data	img_b;
	t_data	img_w;
	t_scrn	scrn;
	char	**map;
}				t_vars;

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const *s1, const char *s2);
void	print_map(char **map);
int		ft_nbr_rows(char **map);
void	free_machine(char **map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
t_vars	get_scrn_size(t_vars vars);
t_vars	init_vars(char *argv[]);
char	*get_next_line(int fd);
char	**get_map(char *argv[]);
char	*ft_strjoin(char const *s1, const char *s2);
void	game_of_life(t_vars *vars);
void	paint_map(t_vars vars);
void	paint_white_img(t_data img, int x, int y);
char	top_left_corner(int i, int j, char **map);
char	top_row(int i, int j, char **map);
char	top_right_corner(int i, int j, char **map);
char	left_column(int i, int j, char **map);
char	right_column(int i, int j, char **map);
char	bottom_left_corner(int i, int j, char **map);
char	bottom_row(int i, int j, char **map);
char	bottom_right_corner(int i, int j, char **map);
char	every_other_case(int i, int j, char **map);
char	calc_char(int count, char current);
#endif
