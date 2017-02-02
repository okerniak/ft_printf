/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrfloat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 11:16:29 by okerniak          #+#    #+#             */
/*   Updated: 2017/01/28 08:39:25 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrbeforepoint(float nbr)
{
	char c;

	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		ft_putnbrbeforepoint(nbr / 10);
	c = (long long)nbr % 10 + '0';
	write(1, &c, 1);
}

static void	ft_putnbrafterpoint(float nbr, int t)
{
	int	tens;

	write(1, ".", 1);
	if (nbr < 0)
		nbr *= -1;
	nbr = nbr - (long long)nbr;
	tens = 1;
	while (t-- >= 0)
		tens *= 10;
	nbr *= tens;
	if ((long long)(nbr * 10) % 10 >= 5)
		nbr += 1;
	tens /= 10;
	while (tens != 1)
	{
		ft_putnbrbeforepoint((long long)nbr / tens % 10);
		tens /= 10;
	}
}

void		ft_putnbrfloat(float nbr)
{
	ft_putnbrbeforepoint(nbr);
	ft_putnbrafterpoint(nbr, 6);
}
