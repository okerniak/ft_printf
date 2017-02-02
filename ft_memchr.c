/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:56:42 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/07 15:52:12 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*str;
	unsigned char	a;

	str = (unsigned char*)s;
	a = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == a)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
