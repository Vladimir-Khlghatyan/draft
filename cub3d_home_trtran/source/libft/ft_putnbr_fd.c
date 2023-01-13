/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:33:00 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/03/15 21:48:38 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	x;
	char			c;

	x = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		x = -n;
	}
	if (x > 9)
	{
		ft_putnbr_fd(x / 10, fd);
		ft_putnbr_fd(x % 10, fd);
	}
	else
	{
		c = x + '0';
		write(fd, &c, 1);
	}
}
