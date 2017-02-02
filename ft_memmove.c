/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:22:33 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/01 12:48:56 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*str1;
	const char		*str2;

	str1 = dst;
	str2 = (char*)src;
	if ((unsigned long)str1 < (unsigned long)str2)
		while (len--)
			*str1++ = *str2++;
	else
		while (len-- > 0)
			str1[len] = str2[len];
	return (dst);
}
