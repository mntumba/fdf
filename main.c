/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:43:25 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/12 09:46:16 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_env		*env;
	t_img		*img;
	char		*image;

	if (ac != 2)
		return (0);
	if ((img = (t_img*)malloc(sizeof(t_img))) == NULL)
		return (0);
	env = NULL;
	parser(&env, av, img);
	iso_proj(&env, img);
	if ((img->mlx = mlx_init()) == NULL)
		return (0);
	img->img = mlx_new_image(img->mlx, WIN_H, WIN_W);
	image = mlx_get_data_addr(img->img, &(img->bpp),
			&(img->len), &(img->endian));
	display(&env, img, image);
	img->win = mlx_new_window(img->mlx, WIN_H, WIN_W, "FDF");
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	hook(img, &env);
	return (0);
}
