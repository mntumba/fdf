/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 21:50:21 by mntumba           #+#    #+#             */
/*   Updated: 2018/01/12 09:50:11 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_env(t_env **env, char **tab, int i, int j)
{
	t_env	*elem;

	if ((elem = (t_env*)malloc(sizeof(t_env))) == NULL)
		exit(0);
	elem->x = i;
	elem->y = j;
	elem->z = ft_atoi(tab[i]);
	elem->next = *env;
	*env = elem;
}

t_env	*parser(t_env **env, char **av, t_img *img)
{
	char	**tab;
	char	*str;
	int		fd;
	int		i;
	int		j;

	j = 0;
	(void)img;
	if ((fd = open(av[1], O_RDONLY)) == -1)
		exit(0);
	while ((str = readfile(fd)) != NULL)
	{
		i = -1;
		tab = ft_strsplit(str);
		while (tab[++i])
			fill_env(env, tab, i, j);
		j++;
	}
	close(fd);
	return (*env);
}
