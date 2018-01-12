/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:29:52 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/12 09:19:27 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ABS(x) (x < 0) ? -x : x
# define BUF_SIZE 1
# define WIN_H 1650
# define WIN_W 1000

typedef struct		s_env
{
	int				x;
	int				y;
	int				z;
	int				env_x;
	int				env_y;
	struct s_env	*next;
}					t_env;

typedef struct		s_img
{
	int				bpp;
	int				len;
	int				endian;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	void			*mlx;
	void			*win;
	void			*img;
}					t_img;

void				draw(t_img *img, char *image, t_env *p1, t_env *p2);
int					pixel_put_to_img(t_img *img, char *image, int x, int y);
void				hook(t_img *img, t_env **env);
t_env				*parser(t_env **env, char **av, t_img *img);
void				iso_proj(t_env **env, t_img *img);
void				display(t_env **env, t_img *img, char *image);
char				*readfile(const int fd);
int					countwords(char *str);
char				**ft_strsplit(char *str);
int					ft_atoi(const char *str);

#endif
