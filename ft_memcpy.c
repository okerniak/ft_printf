/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:59:19 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/06 12:49:23 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *out, const void *in, size_t n)
{
	unsigned int	i;
	char			*str1;
	char			*str2;

	i = 0;
	str1 = out;
	str2 = (char*)in;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}
