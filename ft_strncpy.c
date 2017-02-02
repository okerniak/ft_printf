/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 15:01:00 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/06 12:59:54 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = len;
	while (len > 0)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	i = 0;
	while (src[i])
		i++;
	while (i < j)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
