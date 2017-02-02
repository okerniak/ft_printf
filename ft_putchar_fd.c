/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:09:37 by okerniak          #+#    #+#             */
/*   Updated: 2017/02/02 10:47:36 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define BIT7 127
#define BIT11 2047
#define BIT16 65535
#define BIT21 2097151
#define BIT26 67108863
#define BIT31 2147483647

static void		ft_putchar_fd_2(const uint32_t symbol, char *rt)
{
	if (symbol <= BIT21)
	{
		rt[0] = ((symbol & 1835008) >> 18) | 240;
		rt[1] = ((symbol & 258048) >> 12) | 128;
		rt[2] = ((symbol & 4032) >> 6) | 128;
		rt[3] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT26)
	{
		rt[0] = ((symbol & 50331648) >> 24) | 248;
		rt[1] = ((symbol & 16515072) >> 18) | 128;
		rt[2] = ((symbol & 258048) >> 12) | 128;
		rt[3] = ((symbol & 4032) >> 6) | 128;
		rt[4] = (symbol & 63) | 128;
	}
	else
	{
		rt[0] = ((symbol & 1073741824) >> 30) | 252;
		rt[1] = ((symbol & 1056964608) >> 24) | 128;
		rt[2] = ((symbol & 16515072) >> 18) | 128;
		rt[3] = ((symbol & 258048) >> 12) | 128;
		rt[4] = ((symbol & 4032) >> 6) | 128;
		rt[5] = (symbol & 63) | 128;
	}
}

size_t			ft_putchar_fd(const uint32_t symbol, const int fd)
{
	char		*rt;
	size_t		ct;

	rt = ft_strnew(6);
	ct = 0;
	if (symbol <= BIT7)
		rt[0] = symbol;
	else if (symbol <= BIT11)
	{
		rt[0] = ((symbol & 1984) >> 6) | 192;
		rt[1] = (symbol & 63) | 128;
	}
	else if (symbol <= BIT16)
	{
		rt[0] = ((symbol & 61440) >> 12) | 224;
		rt[1] = ((symbol & 4032) >> 6) | 128;
		rt[2] = (symbol & 63) | 128;
	}
	else
		ft_putchar_fd_2(symbol, rt);
	ct = write(fd, rt, sizeof(char)) + write(fd, &rt[1], ft_strlen(&rt[1]));
	ft_strdel(&rt);
	return (ct);
}
