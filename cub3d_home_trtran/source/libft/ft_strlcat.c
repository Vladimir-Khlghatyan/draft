/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 15:01:50 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/15 20:11:27 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	j;
	size_t	res;

	dstlen = ft_strlen(dst);
	res = ft_strlen(src);
	if (dstsize <= dstlen)
		res += dstsize;
	else
		res += dstlen;
	j = -1;
	while (src[++j] && dstlen + 1 < dstsize)
	{
		dst[dstlen] = src[j];
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (res);
}
