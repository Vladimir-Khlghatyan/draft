/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:30:35 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/12 22:30:48 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*h;
	char	*n;
	size_t	i;
	size_t	j;

	h = (char *)haystack;
	n = (char *)needle;
	i = 0;
	j = 0;
	if (n[0] == '\0' || n == NULL)
		return (h);
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && i + j < len)
		{
			++j;
			if (n[j] == '\0')
			{
				return (h + i);
			}
		}
		++i;
	}
	return (NULL);
}
