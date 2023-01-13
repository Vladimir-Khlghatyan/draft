/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:43:26 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/04/01 14:16:38 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = (void *)s;
	if (n == 0)
		return (NULL);
	i = -1;
	while (++i < n)
		if ((unsigned char)str[i] == (unsigned char) c)
			return (str + i);
	return (NULL);
}
