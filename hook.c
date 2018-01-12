/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:24:52 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/12 09:22:26 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key(int keycode, t_env *env)
{
	(void)env;
	if (keycode == 53)
		exit(0);
	return (0);
}

int		expose(t_img *img)
{
	mlx_put_image_to_window(img->mlx, img->win, img->img, 0, 0);
	return (0);
}

void	hook(t_img *img, t_env **env)
{
	mlx_key_hook(img->win, key, env);
	mlx_expose_hook(img->win, expose, img);
	mlx_loop(img->mlx);
}
