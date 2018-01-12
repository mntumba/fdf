/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mntumba <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 22:05:04 by mntumba           #+#    #+#             */
/*   Updated: 2017/12/11 14:21:26 by mntumba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_strlen(char *str)
{
	int		len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char		*ft_realloc(char *s)
{
	char	*new_s;
	int		i;

	i = -1;
	if ((new_s = (char*)malloc((ft_strlen(s) + 2) * sizeof(char))) == NULL)
		return (NULL);
	while (s[++i] != '\0')
		new_s[i] = s[i];
	new_s[i + 1] = '\0';
	return (new_s);
}

char		*readfile(const int fd)
{
	int				i;
	int				len;
	static char		buf[BUF_SIZE];
	char			*str;

	i = 0;
	len = 0;
	if ((str = (char*)malloc(sizeof(char))) == NULL)
		return (NULL);
	str[0] = '\0';
	while ((len = read(fd, buf, BUF_SIZE)) > 0 && buf[0] != '\n')
	{
		str = ft_realloc(str);
		str[i++] = buf[0];
	}
	return ((len == 0 && i == 0) ? NULL : str);
}
