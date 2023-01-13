/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:03:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/06/14 11:03:52 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

double	ft_min(double x, double y)
{
	if (x < y)
		return (x);
	return (y);
}

double	ft_max(double x, double y)
{
	if (x > y)
		return (x);
	return (y);
}

char	**ft_copy_map_and_replace_door(char **map, char c1, char c2)
{
	int		len;
	int		i;
	int		j;
	char	**new_map;

	if (!map)
		return (NULL);
	len = ft_arrlen(map);
	new_map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new_map)
		ft_error("something went wrong with malloc, try again!\n", 1);
	i = -1;
	while (map[++i])
		new_map[i] = ft_strdup(map[i]);
	new_map[i] = NULL;
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
			if (map[i][j] == c1)
				new_map[i][j] = c2;
	}
	return (new_map);
}
