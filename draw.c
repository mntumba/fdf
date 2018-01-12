/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:25:39 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/12 09:45:57 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	dw_first(t_img *img, char *image)
{
	int	min;
	int x;
	int	y;
	int	max;

	if (img->x1 < img->x2)
	{
		min = img->x1;
		max = img->x2;
	}
	else
	{
		min = img->x2;
		max = img->x1;
	}
	while (min <= max)
	{
		x = min;
		y = ((img->y1 + ((img->y2 - img->y1) *
			(min - img->x1) / (img->x2 - img->x1))));
		if (x > 0 && x < WIN_H && y > 0 && y < WIN_W)
			pixel_put_to_img(img, image, x * img->bpp / 8, y * img->len);
		min++;
	}
}

void	dw_second(t_img *img, char *image)
{
	int	min;
	int	x;
	int	y;
	int	max;

	if (img->y1 < img->y2)
	{
		min = img->y1;
		max = img->y2;
	}
	else
	{
		min = img->y2;
		max = img->y1;
	}
	while (min <= max)
	{
		x = min;
		y = ((img->x1 + ((img->x2 - img->x1) *
			(min - img->y1) / (img->y2 - img->y1))));
		if (x > 0 && x < WIN_W && y > 0 && y < WIN_H)
			pixel_put_to_img(img, image, x * img->len, y * img->bpp / 8);
		min++;
	}
}

void	dw_vertical(t_img *img, char *image)
{
	int	min;
	int	x;
	int	y;
	int	max;

	if (img->y1 < img->y2)
	{
		min = img->y1;
		max = img->y2;
	}
	else
	{
		min = img->y2;
		max = img->y1;
	}
	while (min <= max)
	{
		x = img->x1;
		y = (min * img->len + img->x1);
		if (x > 0 && x < WIN_H && y > 0 && y < WIN_W)
			pixel_put_to_img(img, image, x, y * img->bpp / 8);
		min++;
	}
}

void	dw_horizontal(t_img *img, char *image)
{
	int	min;
	int	x;
	int	y;
	int	max;

	if (img->x1 < img->x2)
	{
		min = img->x1;
		max = img->x2;
	}
	else
	{
		min = img->x2;
		max = img->x1;
	}
	while (min <= max)
	{
		x = (min * img->bpp / 8 + img->y1);
		y = img->y1;
		if (x > 0 && x < WIN_H && y > 0 && y < WIN_W)
			pixel_put_to_img(img, image, x * img->len, y);
		min++;
	}
}

void	draw(t_img *img, char *image, t_env *p1, t_env *p2)
{
	img->x1 = p1->env_x;
	img->y1 = p1->env_y;
	img->x2 = p2->env_x;
	img->y2 = p2->env_y;
	if (ABS(p2->env_x - p2->env_y) >= ABS(p2->env_y - p2->env_x))
	{
		if (img->x1 != img->x2)
		{
			dw_first(img, image);
			dw_second(img, image);
		}
		else
			dw_horizontal(img, image);
	}
	else
	{
		if (img->y1 != img->y2)
		{
			dw_second(img, image);
			dw_first(img, image);
		}
		else
			dw_vertical(img, image);
	}
}
