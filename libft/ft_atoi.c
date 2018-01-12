/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 14:44:33 by mntumba           #+#    #+#             */
/*   Updated: 2017/12/11 14:20:48 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_atoi(const char *str)
{
	int		sign;
	int		nbr;

	nbr = 0;
	while (*str <= 32)
		str++;
	sign = (*str == '-' && str++) ? -1 : 1;
	while (*str && *str >= 48 && *str <= 57)
		nbr = (nbr * 10) + (*str++ - 48);
	return (nbr * sign);
}