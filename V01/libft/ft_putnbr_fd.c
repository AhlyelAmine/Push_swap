/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 09:18:43 by aahlyel           #+#    #+#             */
/*   Updated: 2023/01/16 22:23:15 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	b;

	b = n;
	if (b < 0)
	{
		write(fd, "-", 1);
		b = -b;
	}
	if (b > 9)
		ft_putnbr_fd(b / 10, fd);
	ft_putchar_fd((b % 10) + 0x30, fd);
}
