/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okerniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:28:25 by okerniak          #+#    #+#             */
/*   Updated: 2016/12/07 12:06:24 by okerniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned long	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)memptr;
	while (num > i)
		str[i++] = (unsigned char)val;
	return (str);
}
