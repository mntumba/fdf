/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:22:37 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/12 09:47:57 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		pixel_put_to_img(t_img *img, char *image, int x, int y)
{
	if (img->bpp == 0 || img->len == 0)
		exit(0);
	image[(x + y)] = 0xFF;
	image[(x + y) + 1] = 0xFF;
	image[(x + y) + 2] = 0xFF;
	return (0);
}

void	iso_proj(t_env **env, t_img *img)
{
	t_env		*elem;
	float		cst;

	(void)img;
	elem = *env;
	cst = 0.7;
	while (elem != NULL)
	{
		elem->env_x = ((cst * (elem->x * 5)) -
				(cst * (elem->y * 5)) + (WIN_H / 3));
		elem->env_y = ((elem->z * (-5)) + (cst / 2) * (elem->x * (20)) +
				(cst / 2) * (elem->y * 5) + (WIN_W / 5));
		elem = elem->next;
	}
}

void	display(t_env **env, t_img *img, char *image)
{
	t_env	*p1;
	t_env	*p2;

	p1 = *env;
	while (p1 != NULL)
	{
		p2 = *env;
		while (p2 != NULL)
		{
			if (p1->x == p2->x - 1 && p1->y == p2->y)
				draw(img, image, p1, p2);
			if (p1->y == p2->y - 1 && p1->x == p2->x)
				draw(img, image, p1, p2);
			p2 = p2->next;
		}
		p1 = p1->next;
	}
}
